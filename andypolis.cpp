#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats)
: mapa(archivo_mapa){

    // cuando venga vacio va a haber que meter una logica por aca
    cargar_informacion_jugadores();
    cargar_diccionario(archivo_edif);
    cargar_ubicaciones(archivo_ubics);
    cargar_inventarios(archivo_mats);
 
}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_informacion_jugadores(){


    this -> jugador_uno.asignar_identificador(IDENTIFICADOR_JUGADOR_UNO);
    this -> jugador_uno.asignar_numero_jugador(JUGADOR_UNO);
    this -> jugador_uno.sortear_objetivos_secundarios();
    this -> jugador_uno.crear_grafo(mapa);

    this -> jugador_dos.asignar_identificador(IDENTIFICADOR_JUGADOR_DOS);
    this -> jugador_dos.asignar_numero_jugador(JUGADOR_DOS);
    this -> jugador_dos.sortear_objetivos_secundarios();
    this -> jugador_dos.crear_grafo(mapa);

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_inventarios(ifstream& archivo_mats){

    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugador_uno.agregar_material_al_inventario(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugador_dos.agregar_material_al_inventario(material_leido_dos);
        
    }
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_diccionario(ifstream& archivo_edif){

    string linea_leida;

    while(getline(archivo_edif, linea_leida)){
        
        Parser parser(linea_leida);

        Datos_edificio* dato = parser.procesar_entrada_edificio();

        diccionario.insertar(dato, parser.nombre_edificio());
    }
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_ubicaciones(ifstream& archivo_ubics){

    string linea_leida;
    Estado_t estado = OK;
    Estado_t estado_edificios = OK;
    Estado_t estado_materiales = OK;
    streampos pos_inicial_archivo = 0;

    getline(archivo_ubics,linea_leida); // Leo la primer linea del archivo ubicaciones
    Parser parser(linea_leida);

    if(parser.nombre_elemento_ubicaciones() != "1"){
        
        // Si es distinto de 1 significa que hay materiales en el archivo ubicaciones
        // Entonces:

        archivo_ubics.seekg(pos_inicial_archivo); // Vuevlo a colocar el cursor de lectura en el inicio.
        estado_materiales = cargar_materiales_mapa(archivo_ubics);
        estado_edificios = cargar_edificios_jugador(archivo_ubics);
    }else{

        // Si la primera linea es la posicion de un jugador, entonces no hay materiales en el archivo ubicaciones.
        // Por ende:

        archivo_ubics.seekg(pos_inicial_archivo); // Vuelvo a colocar el cursor de lectura al inicio.
        estado_edificios = cargar_edificios_jugador(archivo_ubics);
    }

    if (estado_materiales != OK){
        estado = estado_materiales;
    } else if (estado_edificios != OK){
        estado = estado_edificios;
    }

    return estado;

    // ESTO LO PROBRE Y FUNCIONA, GOD NO ?

    // Lo probe con:
    // - El archivo ubicaciones que tenemos de prueba, el que esta actualmente en git (Funciona Joya)
    // - El archivo ubicaciones SIN materiales (Funciona joya)
    // - Solo con jugadores, osea sin materiales ni edificios  (Tambien funciona joya)
    // - Con materiales y jugadores, osea, sin edificios (Tambien funciona joya)

    // LEER LOS COMENTARIOS DE LOS METODOS QUE USO ACA.
}


// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::cargar_materiales_mapa(ifstream& archivo_ubics){//, streampos pos){

    Estado_t estado = OK;
    string linea_leida;
    bool jugador_encontrado = false;
    streampos nueva_pos = 0; //Lo inicializo porque sino tira que puede no estar inicializado (Creo)

    //archivo_ubics.seekg(pos);

    while(!jugador_encontrado){
        
        getline(archivo_ubics, linea_leida);
        Parser parser(linea_leida);

        if(parser.nombre_elemento_ubicaciones() != "1"){
            int coord_x = parser.obtener_coordenada_x();
            int coord_y = parser.obtener_coordenada_y();
            Material* mat = parser.procesar_entrada_ubicaciones_materiales();
            estado = mapa.agregar_material_en_coordenadas(mat, coord_x, coord_y);
            nueva_pos = archivo_ubics.tellg(); //Me guardo la pos del cursor ACTUAL.
        }else{
            jugador_encontrado = true;
        }

    }

    //nueva_pos tiene la posicion del cursor justo para que lo proximo que lea sea el jugador 1.
    archivo_ubics.seekg(nueva_pos);
    
    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_edificios_jugador(ifstream& archivo_ubics){
    //Este metodo deberiamos renombrarlo y ponerle tipo "cargar_edificios_y_jugadores" no ?
    // Sino, lo que puedo hacer es modularizarlo, haciendo otro metodo que lo unico que haga sea cargar los edificios y lo llamaria
    //donde dice (*). Y podria pasarle solo la linea leida. 
    //...Pienso....
    // No lo hago ahora porque el tema de nombres de metodos y etc me parece mejor discutirlo con el grupo (re pajero jaja)

    Estado_t estado = OK;
    string linea_leida;
    bool fin_jugador_1 = false;
    streampos pos_archivo = 0; //Lo inicializo porque sino tira que puede no estar inicializado (Creo)

    while(!fin_jugador_1){

        getline(archivo_ubics, linea_leida);
        Parser parser(linea_leida);

        if( parser.nombre_elemento_ubicaciones() == "1"){
            jugador_uno.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_UNO);
        }else if(parser.nombre_elemento_ubicaciones() == "2"){
            jugador_dos.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_DOS);
            pos_archivo = archivo_ubics.tellg();
            fin_jugador_1 = true;
        }else{
            //(*)
            int coordenada_x = parser.obtener_coordenada_x();
            int coordenada_y = parser.obtener_coordenada_y();
            estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_UNO), coordenada_x, coordenada_y);
            cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio(), coordenada_x, coordenada_y, JUGADOR_UNO);
        }

    }

    archivo_ubics.seekg(pos_archivo); // Esto lo deja justo para leer lo que sigue al "2 (420, 69)" jugador 2

    while(getline(archivo_ubics, linea_leida)){ // Se que todo lo que viene despues hasta eof son edificios del jugador 2.

        Parser parser(linea_leida);
        //(*)
        int coordenada_x = parser.obtener_coordenada_x();
        int coordenada_y = parser.obtener_coordenada_y();
        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_DOS), coordenada_x, coordenada_y);
        cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio(), coordenada_x, coordenada_y, JUGADOR_DOS);
    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado = OK;

    estado = mapa.posicionar_jugador(coord_x,coord_y,jugador);

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::cargar_edificio_a_jugador(string nombre, char identificador, int coord_x, int coord_y, Jugador_t jugador){
  
    int vida = 0;

    if(nombre == STR_MINA || nombre == STR_FABRICA)
        vida = 100;
    else
        vida = 50;


    if(jugador == JUGADOR_UNO)
        jugador_uno.agregar_edificio(nombre, identificador, vida, coord_x, coord_y);
    else
        jugador_dos.agregar_edificio(nombre, identificador, vida, coord_x, coord_y);
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::comprar_bombas(Jugador_t jugador){

    Estado_t estado = OK;
    
    if(jugador == JUGADOR_UNO)
        estado = jugador_uno.comprar_bombas();
    if(jugador == JUGADOR_DOS)
        estado = jugador_dos.comprar_bombas();    
        

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


bool Andypolis::esta_edificio(string nombre){

    return diccionario.buscar(nombre);
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::construir_edificio(string nombre, int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
 
    if((estado = mapa.verificar_coordenadas_construccion(coord_x, coord_y)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.

    if(jugador == JUGADOR_UNO){

        estado = jugador_uno.verificar_condiciones_construccion(nombre, diccionario);

        if(estado == OK){
            string linea = construir_string_edificio(nombre, coord_x, coord_y);
            Parser parser(linea);
            estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(jugador), coord_x, coord_y);
            cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio(), coord_x, coord_y, jugador);
            jugador_uno.restar_materiales_construccion(nombre, diccionario);
            jugador_uno.restar_energia((double)15); //desharcodear
        }
    }

    if(jugador == JUGADOR_DOS){

        estado = jugador_dos.verificar_condiciones_construccion(nombre, diccionario);

        if(estado == OK){
            string linea = construir_string_edificio(nombre, coord_x, coord_y);
            Parser parser(linea);
            estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(jugador), coord_x, coord_y);
            cargar_edificio_a_jugador(parser.nombre_elemento_ubicaciones(), parser.obtener_identificador_edificio(), coord_x, coord_y, jugador);
            jugador_dos.restar_materiales_construccion(nombre, diccionario);
            jugador_dos.restar_energia((double)15); //desharcodear
        }
    }
    
    return estado;
}


// ------------------------------------------------------------------------------------------------------------


string Andypolis::construir_string_edificio(string nombre, int coord_x, int coord_y){

    string linea;

    linea.append(nombre);
    linea.append(ESPACIO);
    linea.append("(");
    linea.append(to_string(coord_x));
    linea.append(", ");
    linea.append(to_string(coord_y));
    linea.append(")");

    return linea;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::destruir_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;

    if((estado = mapa.verificar_coordenadas_demolicion(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.

    if( jugador == JUGADOR_UNO){
        if(jugador_uno.obtener_energia() < (double) 15){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }
        else {
            nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
            estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);
            jugador_uno.demoler_edificio(nombre_edificio, diccionario, coord_x, coord_y);
        }
    }

    if( jugador == JUGADOR_DOS){
        if(jugador_dos.obtener_energia() < (double) 15){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }
        else {
            nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
            estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);
            jugador_dos.demoler_edificio(nombre_edificio, diccionario, coord_x, coord_y);
        }
    }

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::atacar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;
    int posicion_edificio, orden_edificio;

    if((estado = mapa.verificar_coordenadas_ataque(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.

    if( jugador == JUGADOR_UNO){
        if(jugador_uno.obtener_energia() < (double) 30){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }
        if(!jugador_uno.obtener_cantidad_bombas()){
            return estado = ERROR_BOMBAS_INSUFICIENTES;
        }
        else {
            nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
            posicion_edificio = jugador_dos.buscar_edificio_por_nombre(nombre_edificio);
            orden_edificio = jugador_dos.buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);


            if( jugador_dos.obtener_vida_edificio(posicion_edificio, orden_edificio) == 100 ){
                    jugador_dos.restar_vida_edificio(posicion_edificio, orden_edificio);

            }
            else{
                jugador_dos.destruir_edificio(nombre_edificio, diccionario, coord_x, coord_y);
                estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);
            }

            jugador_uno.restar_bombas();
            jugador_uno.aumentar_bombas_usadas();
            jugador_uno.restar_energia(30);
        }
    }

    if( jugador == JUGADOR_DOS){
        if(jugador_dos.obtener_energia() < (double) 30){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }
        if(!jugador_dos.obtener_cantidad_bombas()){
            return estado = ERROR_BOMBAS_INSUFICIENTES;
        }
        else {
            nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
            posicion_edificio = jugador_uno.buscar_edificio_por_nombre(nombre_edificio);
            orden_edificio = jugador_uno.buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);


            if( jugador_uno.obtener_vida_edificio(posicion_edificio, orden_edificio) == 100 ){
                    jugador_uno.restar_vida_edificio(posicion_edificio, orden_edificio);

            }
            else{
                jugador_uno.destruir_edificio(nombre_edificio, diccionario, coord_x, coord_y);
                estado = mapa.destruir_edificio_en_coord(coord_x, coord_y);
            }

            jugador_dos.restar_bombas();
            jugador_dos.aumentar_bombas_usadas();
            jugador_dos.restar_energia(30);
        }
    }
    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::reparar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado;
    string nombre_edificio;
    int posicion_edificio, orden_edificio;

    if((estado = mapa.verificar_coordenadas_reparacion(coord_x, coord_y, jugador)) != OK)
        return estado; //Si las coordenadas tienen algun problmea no tiene sentido continuar.
        
    
    if( jugador == JUGADOR_UNO){
        if(jugador_uno.obtener_energia() < (double) 25){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }

        nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
        posicion_edificio = jugador_uno.buscar_edificio_por_nombre(nombre_edificio);
        orden_edificio = jugador_uno.buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);

        if(!jugador_uno.puede_repararse_edificio(posicion_edificio, orden_edificio)){
            return estado = ERROR_EDIFICIO_NO_REPARABLE;
        }
            
        
        estado = jugador_uno.verificar_condiciones_construccion(nombre_edificio, diccionario);

        if(estado == OK){
           
            jugador_uno.sumar_vida_edificio(posicion_edificio, orden_edificio); 
            jugador_uno.restar_materiales_reparacion(nombre_edificio, diccionario);
            jugador_uno.restar_energia((double)25); //desharcodear
        }
    }

    if( jugador == JUGADOR_DOS){
        if(jugador_dos.obtener_energia() < (double) 25){ //DESHARCODEAR
            return estado = ERROR_ENERGIA_INSUFICIENTE;
        }

        nombre_edificio = mapa.obtener_nombre_objeto_de_casillero_ocupado(coord_x, coord_y);
        posicion_edificio = jugador_dos.buscar_edificio_por_nombre(nombre_edificio);
        orden_edificio = jugador_dos.buscar_posicion_coordenadas( posicion_edificio, coord_x, coord_y);

        if(!jugador_dos.puede_repararse_edificio(posicion_edificio, orden_edificio))
            return estado = ERROR_EDIFICIO_NO_REPARABLE;
        
        estado = jugador_dos.verificar_condiciones_construccion(nombre_edificio, diccionario);

        if(estado == OK){
           
            jugador_dos.sumar_vida_edificio(posicion_edificio, orden_edificio); 
            jugador_dos.restar_materiales_reparacion(nombre_edificio, diccionario);
            jugador_dos.restar_energia((double)25); //desharcodear
        }
    }
    return estado;
}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_inventario();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_inventario();    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_objetivos(Jugador_t jugador){
    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_objetivos();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_objetivos();    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::listar_edificios_construidos(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.listar_edificios_construidos();
    if(jugador == JUGADOR_DOS)
        jugador_dos.listar_edificios_construidos();

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(){

    mapa.mostrar_mapa();

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::consultar_casillero_de_mapa(int coord_x, int coord_y) const{

    Estado_t estado = OK;

    return estado = mapa.consultar_casillero(coord_x,coord_y);

}

