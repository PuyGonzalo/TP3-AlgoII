#include "jugador.h"


// ------------------------------------------------------------------------------------------------------------

Jugador::Jugador(){


    this -> identificador = ' ';
    this -> jugador = NADIE;
    ubicacion.coordenada_x = -1;
    ubicacion.coordenada_y = -1;
    this -> objetivo_principal = new Alto_nubes();
    energia = 50; // primer turno imagino que es cuando se crea..

}


// ------------------------------------------------------------------------------------------------------------


Jugador::~Jugador(){
    
    delete objetivo_principal;
    delete grafo;

    for(int i = 0 ; i < mis_edificios.obtener_cantidad() ; ++i)
        delete mis_edificios.consulta(i);
    
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::agregar_energia(double energia){
    if(this -> energia + energia >= 100) // deshardcodear
        this -> energia = 100;
    else this -> energia += energia;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::restar_energia(double energia){
    
    this -> energia -= energia;
    
}


// ------------------------------------------------------------------------------------------------------------

void Jugador::asignar_identificador(char identif){

    this -> identificador = identif;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::asignar_numero_jugador(Jugador_t jugador){

    this -> jugador = jugador;

}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::puede_repararse_edificio( int posicion_edificio, int orden_edificio){

    bool estado = false;

    if(this -> mis_edificios.consulta(posicion_edificio)->obtener_nombre() == STR_MINA ||
            this -> mis_edificios.consulta(posicion_edificio)->obtener_nombre() == STR_FABRICA){
        estado = this -> mis_edificios.consulta(posicion_edificio)->puede_repararse(orden_edificio); 
    }
    
    return estado;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::asignar_ubicacion_jugador(int coord_x, int coord_y){

    this -> ubicacion.coordenada_x = coord_x;
    this -> ubicacion.coordenada_y = coord_y;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::crear_grafo(const Mapa &mapa){

    this -> grafo = new Grafo(mapa,jugador);

}


// ------------------------------------------------------------------------------------------------------------


double Jugador::obtener_cantidad_andycoins(){

    return this -> inventario.obtener_cantidad_de_andycoins();

}


// ------------------------------------------------------------------------------------------------------------


double Jugador::obtener_cantidad_bombas(){

    return this -> inventario.obtener_cantidad_de_bombas();

}


// ------------------------------------------------------------------------------------------------------------


double Jugador::obtener_energia(){

    return this -> energia;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::restar_bombas(){

    this -> inventario.restar_cantidad_material('X', 1);
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::aumentar_bombas_usadas(){
    this -> inventario.aumentar_bombas_usadas(1);
}


// ------------------------------------------------------------------------------------------------------------


int Jugador::obtener_vida_edificio( int posicion_edificio, int orden_edificio){

    return this->mis_edificios.consulta_const(posicion_edificio)->obtener_vida(orden_edificio);

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::sumar_vida_edificio( int posicion_edificio, int orden_edificio){

    return this->mis_edificios.consulta_const(posicion_edificio)->sumar_vida(orden_edificio);

}


// ------------------------------------------------------------------------------------------------------------


int Jugador::buscar_posicion_coordenadas( int posicion_edificio, int coord_x, int coord_y){
    return this -> mis_edificios.consulta(posicion_edificio)->buscar_coordenadas_en_lista(coord_x, coord_y);
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::restar_vida_edificio( int posicion_edificio, int orden_edificio){

    return this->mis_edificios.consulta_const(posicion_edificio)->restar_vida(orden_edificio);
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::sortear_objetivos_secundarios(){

    // Decidir si usamos esta forma:

    /*
    Lista<int> opciones_objetivos;
    int opcion_elegida;
    int i ;

    for( i = 0 ; i < CANT_OBJETIVOS_SECUNDARIOS; ++i){
        opciones_objetivos.alta(i,i);
    }

    for( i=0; i < CANT_OBJETIVOS_SORTEADOS; i++){
        opcion_elegida = opciones_objetivos.bajar_aleatorio();
        objetivos_secundarios.insertar( (generar_objetivos_secundarios(opcion_elegida)) );
    }
    */
    
    
    

   // O esta:
   int arreglo_aux[] = {0,1,2,3,4,5,6,7,8,9};
   
   int n = sizeof(arreglo_aux) / sizeof(arreglo_aux[0]);

   shuffle(arreglo_aux, arreglo_aux + n, default_random_engine(random_device()()));

   for(int i=0; i < CANT_OBJETIVOS_SORTEADOS; i++){
        objetivos_secundarios.insertar( (generar_objetivos_secundarios(arreglo_aux[i])) );
    }
    
    /*
    for(int i=0; i < 10; ++i){
        cout << arreglo_aux[i] << endl;
    }
    cout << endl;
    */
    
    
    

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::mostrar_objetivos(){

    actualizar_estado_objetivos();

    cout
        << endl << TAB << NEGRITA << SUBRAYADO
        << left
        << setw(30)
        << "Objetivo"
        << left
        << setw(70)
        << "Descripcion"
        << left
        << setw(48)
        << "Progreso"
        << FIN_DE_FORMATO
        << endl;


        cout
            << TAB
            << left << setw(30) << objetivo_principal->obtener_nombre()
            << left << setw(70) <<  objetivo_principal->obtener_condiciones()
            << left << setw(48) << objetivo_principal->obtener_progreso(energia, inventario, mis_edificios) << endl;

        for( int i=0; i < CANT_OBJETIVOS_SORTEADOS; i++){
            cout
            << TAB
            << left << setw(30) << objetivos_secundarios.consultar(i)->obtener_nombre()
            << left << setw(70) <<  objetivos_secundarios.consultar(i)->obtener_condiciones()
            << left << setw(48) << objetivos_secundarios.consultar(i)->obtener_progreso(energia, inventario, mis_edificios) << endl;
        }

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::agregar_material_al_inventario(Material* material){

    inventario.agregar_material_a_lista(material); // deberiamos sacarle el "lista"

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Jugador::comprar_bombas(){

    string cantidad_a_comprar;

    cout << TAB << NEGRITA << SUBRAYADO << "Ingresa la cantidad de bombas que desea comprar:" << FIN_DE_FORMATO << endl;
    cout << '>' << ESPACIO; getline(cin, cantidad_a_comprar); cout << FIN_DE_FORMATO;

    if(!es_un_numero(cantidad_a_comprar))
        return ERROR_ENTRADA_INVALIDA;

    int cantidad = stoi(cantidad_a_comprar);

    // ingreso arriba, lo demas abajo (esto es para que me vuelva al menu si no tiene energia...)

    if( cantidad * PRECIO_BOMBA > inventario.obtener_cantidad_de_andycoins() ) // hay 3 returns aca pero tengo sueño, hacer funcion PRIVADA que chequee condic?
        return ERROR_ANDYCOINS_INSUFICIENTES;

    inventario.sumar_cantidad_material(IDENTIF_BOMBA,cantidad);
    inventario.restar_cantidad_material(IDENTIF_ANDYCOINS, cantidad*PRECIO_BOMBA);
    inventario.aumentar_bombas_compradas(cantidad);

    cout << TAB << TAB << NEGRITA << "Adquiriste " << cantidad << " bombas" << FIN_DE_FORMATO << endl;
    cout << TAB << NEGRITA << "Te quedan " << inventario.obtener_cantidad_de_andycoins() << " andycoins... ¡Cuidalas!" << FIN_DE_FORMATO << endl;

    this -> energia-=5; // const int ENERGIA_COMPRAR_BOMBAS = 5;

    return OK;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::agregar_edificio(string nombre, char identificador, int vida, int coord_x, int coord_y){

    
    if(this -> mis_edificios.obtener_cantidad() > 0){
        
        int pos = buscar_edificio_por_identificador(identificador);

        if( pos != -1 ){
            this->mis_edificios.consulta(pos) -> agregar_vida(vida);
            this -> mis_edificios.consulta(pos)->agregar_coordenadas_a_lista(coord_x, coord_y);

        }else{

            Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador);
            this -> mis_edificios.alta(nuevo_edif, mis_edificios.obtener_cantidad());
            int pos_nuevo_edif = mis_edificios.obtener_cantidad() - 1;
            this->mis_edificios.consulta(pos_nuevo_edif) -> agregar_vida( vida);
            this -> mis_edificios.consulta(pos_nuevo_edif) -> agregar_coordenadas_a_lista(coord_x, coord_y);
            
        }
    }else{
        Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador);
        this -> mis_edificios.alta(nuevo_edif, mis_edificios.obtener_cantidad());
        int pos_nuevo_edif = this -> mis_edificios.obtener_cantidad() - 1;
        this->mis_edificios.consulta(pos_nuevo_edif) -> agregar_vida( vida);
        this -> mis_edificios.consulta(pos_nuevo_edif) -> agregar_coordenadas_a_lista(coord_x, coord_y);
        
    }
}


// ------------------------------------------------------------------------------------------------------------


int Jugador::buscar_edificio_por_identificador(char identificador){

    int pos = -1;
    bool encontrado = false;
    int i = 0;

    while(i < mis_edificios.obtener_cantidad() && !encontrado){

        if(mis_edificios.consulta(i) -> obtener_identificador() == identificador){
            pos = i;
            encontrado = true;
        }

        ++i;
    }

    return pos;
}


// ------------------------------------------------------------------------------------------------------------


int Jugador::buscar_edificio_por_nombre(string nombre){

    int pos = -1;
    bool encontrado = false;
    int i = 0;

    while(i < mis_edificios.obtener_cantidad() && !encontrado){

        if(mis_edificios.consulta(i) -> obtener_nombre() == nombre){
            pos = i;
            encontrado = true;
        }

        ++i;
    }

    return pos;
}



// ------------------------------------------------------------------------------------------------------------


Estado_t Jugador::verificar_condiciones_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario){
    
    Estado_t estado;

    if(energia < CANTIDAD_ENERGIA_NECESARIA_P_CONSTRUIR)
        return estado = ERROR_ENERGIA_INSUFICIENTE;

    if(diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_piedra() < inventario.obtener_cantidad_de_piedra()
        && diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_madera() < inventario.obtener_cantidad_de_madera()
        && diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_metal() < inventario.obtener_cantidad_de_metal()){
            
        estado = OK;
    }else return estado = ERROR_MATERIALES_INSUFICIENTES; // no tiene sentido continuar si pasa esto, creo

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Jugador::verificar_condiciones_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario){
    
    Estado_t estado;

    if(energia < 25) //HARCADEO
        return estado = ERROR_ENERGIA_INSUFICIENTE;

    if(diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_piedra() /4 < inventario.obtener_cantidad_de_piedra()
        && diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_madera() /4 < inventario.obtener_cantidad_de_madera()
        && diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_metal() /4 < inventario.obtener_cantidad_de_metal()){
            
        estado = OK;
    }else return estado = ERROR_MATERIALES_INSUFICIENTES; // no tiene sentido continuar si pasa esto, creo

    int posicion_edificio = buscar_edificio_por_nombre(nombre);

    if(posicion_edificio != -1){ // Esto es, que ya hay un edificio de este tipo
        estado = ERROR_NO_HAY_CONSTRUIDOS;
    } else estado = OK; //Si no esta en los edificios del jugador, claramente no hay construidos y no se supero la cantidad maxima permitida

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::restar_materiales_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario){

    inventario.restar_cantidad_materiales_construccion(
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_piedra(),
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_madera(),
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_metal()    
    );
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::restar_materiales_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario){

    inventario.restar_cantidad_materiales_construccion(
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_piedra() /4,
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_madera() /4,
    diccionario.consultar_const(nombre) -> obtener_dato_const() -> obtener_costo_metal() /4    
    );
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::actualizar_estado_objetivos(){

    objetivo_principal -> actualizar_cumplimiento(energia,inventario,mis_edificios);

    for(int i = 0 ; i < objetivos_secundarios.obtener_longitud() ; ++i)
        objetivos_secundarios.consultar(i)->actualizar_cumplimiento(energia,inventario,mis_edificios);

}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::gane_el_juego(){

    actualizar_estado_objetivos();

    bool gane = false;

    if(victoria_por_objetivo_principal() || victoria_por_objetivos_secundarios())
        gane = true;

    return gane;

}

// ------------------------------------------------------------------------------------------------------------


bool Jugador::victoria_por_objetivo_principal(){

    return ( objetivo_principal -> chequear_cumplimiento() );

}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::victoria_por_objetivos_secundarios(){

    int cantidad_objetivos_secundarios_cumplidos = 0;
    
    for(int i = 0 ; i < CANT_OBJETIVOS_SORTEADOS ; ++i){
        if( objetivos_secundarios.consultar(i) -> chequear_cumplimiento() )
            cantidad_objetivos_secundarios_cumplidos++;
    }

    return (cantidad_objetivos_secundarios_cumplidos >= 2); // CANTIDAD_OBJ_SECUNDARIOS_PA_GANAR = 2

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::mostrar_inventario(){

    inventario.mostrar_inventario();

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::listar_edificios_construidos(){

        cout
        << NEGRITA << SUBRAYADO
        << left
        << setw(22)
        << "Nombre del edificio"
        << left
        << setw(13)
        << "Construidos"
        << left
        << setw(24)
        << "Vida del edificio"
        << left
        << setw(33)
        << "Coordenadas donde se encuentran"
        << FIN_DE_FORMATO
        << endl;

    for(int i = 0 ; i < mis_edificios.obtener_cantidad() ; ++i){
        cout
            << left
            << setw(22)
            << mis_edificios.consulta_const(i) -> obtener_nombre()
            << left
            << setw(13)
            << mis_edificios.consulta_const(i) -> obtener_cantidad_construidos()
            << left
            << setw(24)
            << mis_edificios.consulta_const(i) -> obtener_vida_edificios_str()
            << left
            << setw(33)   
            << mis_edificios.consulta_const(i) -> obtener_ubicaciones_construidas_str()
            << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------

Objetivo* Jugador::generar_objetivos_secundarios(int opcion_objetivo){

    Objetivo* aux = nullptr;

    switch(opcion_objetivo){
        
        case OPC_COMPRAR_ANDYNOPOLIS:
            aux = new Comprar_andypolis();
            break;

        case OPC_EDAD_PIEDRA:
            aux = new Edad_piedra();
            break;
        
        case OPC_BOMBARDERO:
            aux = new Bombardero();
            break;
        
        case OPC_ENERGETICO:
            aux = new Energetico();
            break;
        
        case OPC_LETRADO:
            aux = new Letrado();
            break;
        
        case OPC_MINERO:
            aux = new Minero();
            break;
        
        case OPC_CANSADO:
            aux = new Cansado();
            break;

        case OPC_CONSTRUCTOR:
            aux = new Constructor();
            break;

        case OPC_ARMADO:
            aux = new Armado();
            break;
        
        case OPC_EXTREMISTA:
            aux = new Extremista();
            break;
    }

    return aux;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::demoler_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y){

    int pos_edificio = buscar_edificio_por_nombre(nombre_edificio);
    int orden_edificio = buscar_posicion_coordenadas(pos_edificio, coord_x, coord_y);

    if(mis_edificios.consulta(pos_edificio)->obtener_cantidad_construidos() > 1){
        mis_edificios.consulta(pos_edificio)-> restar_cantidad_construidos();
        mis_edificios.consulta(pos_edificio) -> quitar_coordenadas_a_lista(coord_x, coord_y);
        mis_edificios.consulta(pos_edificio) -> quitar_vida(orden_edificio);
    }
    else{
        delete mis_edificios.consulta(pos_edificio);
        mis_edificios.baja(pos_edificio);
    }

    inventario.sumar_cantidad_materiales_construccion(
        diccionario.consultar_const(nombre_edificio)->obtener_dato_const()->obtener_costo_piedra() /2,
        diccionario.consultar_const(nombre_edificio)->obtener_dato_const()->obtener_costo_madera() /2,
        diccionario.consultar_const(nombre_edificio)->obtener_dato_const()->obtener_costo_metal() /2
    );

    restar_energia(15); //HARCODEADOOOOOO
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::destruir_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y){

    int pos_edificio = buscar_edificio_por_nombre(nombre_edificio);
    int orden_edificio = buscar_posicion_coordenadas(pos_edificio, coord_x, coord_y);

    if(mis_edificios.consulta(pos_edificio) -> obtener_cantidad_construidos() > 1){
        mis_edificios.consulta(pos_edificio) -> quitar_coordenadas_a_lista(coord_x, coord_y);
        mis_edificios.consulta(pos_edificio) -> quitar_vida(orden_edificio);
        mis_edificios.consulta(pos_edificio) -> restar_cantidad_construidos();
    }
    else{
        delete mis_edificios.consulta(pos_edificio);
        mis_edificios.baja(pos_edificio);
    }
}