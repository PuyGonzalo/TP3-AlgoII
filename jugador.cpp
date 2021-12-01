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

/*
Jugador::Jugador(char id, Jugador_t jugador){

    this -> jugador = jugador;
    this -> identificador = id;
    this -> objetivo_principal = new Alto_nubes(OBJ_MAS_ALTO_NUBES, false); 
}
*/

// ------------------------------------------------------------------------------------------------------------

Jugador::~Jugador(){
    
    delete objetivo_principal;
    delete grafo;

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::mostrar_inventario(){

    inventario.mostrar_inventario();

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


void Jugador::agregar_material_a_lista(Material* material){

    inventario.agregar_material_a_lista(material);

}


// ------------------------------------------------------------------------------------------------------------


void Jugador::agregar_edificio(string nombre, char identificador, int vida, int coord_x, int coord_y){

    
    if(this -> mis_edificios.obtener_longitud() > 0){
        
        int pos = buscar_edificio_por_identificador(identificador);

        if( pos != -1 ){
            this -> mis_edificios.consultar(pos) -> agregar_coordenadas_a_lista(coord_x, coord_y);

        }else{

            Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador, vida);
            this -> mis_edificios.insertar(nuevo_edif);
            int pos_nuevo_edif = mis_edificios.obtener_longitud() - 1;
            this -> mis_edificios.consultar(pos_nuevo_edif) -> agregar_coordenadas_a_lista(coord_x, coord_y);
        }
    }else{
        Edificio_jugador* nuevo_edif = new Edificio_jugador(nombre, identificador, vida);
        this -> mis_edificios.insertar(nuevo_edif);
        int pos_nuevo_edif = this -> mis_edificios.obtener_longitud() - 1;
        this -> mis_edificios.consultar(pos_nuevo_edif) -> agregar_coordenadas_a_lista(coord_x, coord_y);
    }
}


// ------------------------------------------------------------------------------------------------------------


int Jugador::buscar_edificio_por_identificador(char identificador){

    int pos = -1;
    bool encontrado = false;
    int i = 0;

    while(i < mis_edificios.obtener_longitud() && !encontrado){

        if(mis_edificios.consultar(i) -> obtener_identificador() == identificador){
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

/*
bool Jugador::chequear_objetivo(Objetivo *objetivo){
    return objetivos_secundarios.consultar(i).chequear_cumplimiento();
}*/


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