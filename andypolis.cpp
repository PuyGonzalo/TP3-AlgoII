#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats)
: mapa(archivo_mapa){

    cargar_diccionario(archivo_edif);
    cargar_inventarios(archivo_mats);
    cargar_ubicaciones(archivo_ubics);

    Grafo grafo(mapa,JUGADOR_UNO);
    grafo.imprimir_matriz_ady();
 
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

    // IMPLEMENTACION GONA 

    getline(archivo_ubics,linea_leida); // Leo la primer linea del archivo ubicaciones
    Parser parser(linea_leida);

    if(parser.nombre_elemento_ubicaciones() != "1"){
        
        // Si es distinto de 1 significa que hay materiales en el archivo ubicaciones
        // Entonces:

        archivo_ubics.seekg(pos_inicial_archivo); // Vuevlo a colocar el cursor de lectura en el inicio.
        estado_materiales = cargar_materiales_mapa(archivo_ubics);
        // El metodo de arriba me deja el archivo pipicucu, justo para leer el "1 (69, 420)" jugador 1.
        estado_edificios = cargar_edificios_jugador(archivo_ubics);
    }else{

        // Si la primera linea es la posiscion de un jugador, entonces no hay materiales en el archivo ubicaciones.
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
            jugador_uno.asignar_identificador(JUGADOR_UNO);
            jugador_uno.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_UNO);
        }else if(parser.nombre_elemento_ubicaciones() == "2"){
            jugador_dos.asignar_identificador(JUGADOR_DOS);
            jugador_dos.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_DOS);
            pos_archivo = archivo_ubics.tellg();
            fin_jugador_1 = true;
        }else{
            //(*)
            int coordenada_x = parser.obtener_coordenada_x();
            int coordenada_y = parser.obtener_coordenada_y();
            estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_UNO), coordenada_x, coordenada_y);
            // cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y); PARA C/JUG
        }

    }

    archivo_ubics.seekg(pos_archivo); // Esto lo deja justo para leer lo que sigue al "2 (420, 69)" jugador 2

    while(getline(archivo_ubics, linea_leida)){ // Se que todo lo que viene despues hasta eof son edificios del jugador 2.

        Parser parser(linea_leida);
        //(*)
        int coordenada_x = parser.obtener_coordenada_x();
        int coordenada_y = parser.obtener_coordenada_y();
        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_DOS), coordenada_x, coordenada_y);
        // cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y); PARA C/JUG

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


void Andypolis::cargar_inventarios(ifstream& archivo_mats){

    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugador_uno.agregar_material_a_lista(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugador_dos.agregar_material_a_lista(material_leido_dos);
        
    }
}


// ------------------------------------------------------------------------------------------------------------


Andypolis::~Andypolis(){


}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_inventario();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_inventario();
    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(){

    mapa.mostrar_mapa();

}