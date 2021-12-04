#include "jugador.h"


// ------------------------------------------------------------------------------------------------------------

Jugador::Jugador(){

    this -> identificador = ' ';
    this -> jugador = NADIE;
    ubicacion.coordenada_x = -1;
    ubicacion.coordenada_y = -1;
    this -> objetivo_principal = new Alto_nubes(OBJ_MAS_ALTO_NUBES, false);
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


void Jugador::asignar_identificador(char identif){

    this -> identificador = identif;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::asignar_numero_jugador(Jugador_t jugador){

    this -> jugador = jugador;

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


void Jugador::sortear_objetivos_secundarios(){

    Lista<int> opciones_objetivos;
    int opcion_elegida;

    for(int i = 0 ; i < CANT_OBJETIVOS_SECUNDARIOS; ++i){
        opciones_objetivos.alta(i,i);
    }

    while( objetivos_secundarios.obtener_longitud() == CANT_OBJETIVOS_SORTEADOS){
        opcion_elegida = opciones_objetivos.bajar_aleatorio();
        objetivos_secundarios.insertar( (sortear_objetivos(opcion_elegida)) );
    }

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::agregar_material_al_inventario(Material* material){

    inventario.agregar_material_a_lista(material); // deberiamos sacarle el "lista"

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Jugador::comprar_bombas(){

    if( energia < 5)
        return ERROR_ENERGIA_INSUFICIENTE; 

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
            this -> mis_edificios.consulta(pos)->agregar_coordenadas_a_lista(coord_x, coord_y);

        }else{

            Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador, vida);
            this -> mis_edificios.alta(nuevo_edif, mis_edificios.obtener_cantidad());
            int pos_nuevo_edif = mis_edificios.obtener_cantidad() - 1;
            this -> mis_edificios.consulta(pos_nuevo_edif) -> agregar_coordenadas_a_lista(coord_x, coord_y);
        }
    }else{
        Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador, vida);
        this -> mis_edificios.alta(nuevo_edif, mis_edificios.obtener_cantidad());
        int pos_nuevo_edif = this -> mis_edificios.obtener_cantidad() - 1;
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

/* No se si va a ser util la dejo por si las dudas
int Jugador::buscar_edificio_por_nombre(string nombre){

    int pos = -1;
    bool encontrado = false;
    int i = 0;

    while(i < mis_edificios.obtener_longitud() && !encontrado){

        if(mis_edificios.consultar(i) -> obtener_nombre() == nombre){
            pos = i;
            encontrado = true;
        }

        ++i;
    }

    return pos;
}
*/


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivos_secundarios(){

    int cantidad_objetivos_secundarios_cumplidos = 0;
    
    for(int i = 0 ; i < objetivos_secundarios.obtener_longitud() ; ++i){
        if( objetivos_secundarios.consultar(i) -> chequear_cumplimiento(energia,inventario,mis_edificios) )
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
        << "¿Necesita reparacion?"
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
            << mis_edificios.consulta_const(i) -> obtener_vida() // no esta bien la de NECESITA REPARACION y hay que pasarlo a SI NO (o poner hp/hptotal)
            << left
            << setw(33)   
            << mis_edificios.consulta_const(i) -> obtener_ubicaciones_construidas_str()
            << endl;
    }

}


// ------------------------------------------------------------------------------------------------------------

Objetivo* Jugador::sortear_objetivos(int opcion_objetivo){

    Objetivo* aux = nullptr;

    switch(opcion_objetivo){
        
        case OPC_COMPRAR_ANDYNOPOLIS:
            aux = new Comprar_andypolis(OBJ_COMPRAR_ANDYNOPOLIS, false);
            break;

        case OPC_EDAD_PIEDRA:
            aux = new Edad_piedra(OBJ_EDAD_PIEDRA, false);
            break;
        
        case OPC_BOMBARDERO:
            aux = new Bombardero(OBJ_BOMBARDERO, false);
            break;
        
        case OPC_ENERGETICO:
            aux = new Energetico(OBJ_ENERGETICO, false);
            break;
        
        case OPC_LETRADO:
            aux = new Letrado(OBJ_LETRADO, false);
            break;
        
        case OPC_MINERO:
            aux = new Minero(OBJ_MINERO, false);
            break;
        
        case OPC_CANSADO:
            aux = new Cansado(OBJ_CANSADO, false);
            break;

        case OPC_CONSTRUCTOR:
            aux = new Constructor(OBJ_CONSTRUCTOR, false);
            break;

        case OPC_ARMADO:
            aux = new Armado(OBJ_ARMADO, false);
            break;
    }

    return aux;

}