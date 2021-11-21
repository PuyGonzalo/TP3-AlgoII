#include "jugador.h"


// ------------------------------------------------------------------------------------------------------------


Jugador::Jugador(){
    identificador = 0;
    andycoins_gastados = 0;
    inventario = 0;
    ubicacion = 0;
    objetivos_secundarios[CANT_OBJETIVOS_SECUNDARIOS] = 0;
    catalogo = 0;
    energia = 0;

}


// ------------------------------------------------------------------------------------------------------------


Jugador::Jugador(char id, int cant_gastados, Inventario invent, Coordenadas ubi,Objetivo_t objetivos, Lista<Datos_edificio*> edificios, int cant_energia){
    identificador = id;
    andycoins_gastados = cant_gastados;
    inventario = invent;
    ubicacion = ubi;
    objetivos_secundarios[CANT_OBJETIVOS_SECUNDARIOS] = objetivos;
    catalogo = edificios;
    energia = cant_energia;

}


// ------------------------------------------------------------------------------------------------------------


char Jugador::obtener_identificador(){
    return identificador;
}


// ------------------------------------------------------------------------------------------------------------


char Jugador::obtener_andycoins_gastados(){
    return andycoins_gastados;
}


// ------------------------------------------------------------------------------------------------------------



Inventario Jugador::obtener_inventario(){
    return inventario;
}


// ------------------------------------------------------------------------------------------------------------


Coordenadas Jugador::obtener_ubicacion(){
    return ubicacion;
}
        

// ------------------------------------------------------------------------------------------------------------


Objetivo_t Jugador::obtener_objetivos_secundarios(){
    return objetivos_secundarios;
}


// ------------------------------------------------------------------------------------------------------------


Lista<Datos_edificio*> Jugador::obtener_catalogo(){
    return catalogo;
}


// ------------------------------------------------------------------------------------------------------------


int Jugador::obtener_energia(){
    return energia;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::setear_identificador( char id){
    identificador = id;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::setear_andycoins_gastados( int cant_andycoins){
    andycoins_gastados = cant_andycoins;
}


// ------------------------------------------------------------------------------------------------------------



void Jugador::setear_inventario( Inventario invent){
    inventario = invent;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::setear_ubicacion( Coordenadas ubi){
    ubicacion = ubi;
}
        

// ------------------------------------------------------------------------------------------------------------


void Jugador::setear_objetivos_secundarios( Objetivo_t objetivos){
    objetivos_secundarios = objetivos;
}


// ------------------------------------------------------------------------------------------------------------


void Jugador::setear_catalogo( Lista<Datos_edificio*> catalog){
    catalogo = catalog;
}


// ------------------------------------------------------------------------------------------------------------


void setear_energia( int cant_energia){
    energia = cant_energia;
}


// ------------------------------------------------------------------------------------------------------------

/*
bool Jugador::chequear_objetivo_obelisco(){
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_OBELISCO == catalogo.consulta(i) -> nombre)
            return (catalogo.consulta(i) -> cantidad_construidos == 0);
    }
    return false;
}


// ------------------------------------------------------------------------------------------------------------


//(las monedas gastadastambién cuentan para este objetivo)
bool Jugador::chequear_objetivo_comprar_andypolis(){
    return (inventario.obtener_cantidad_de_piedra() + andycoins_gastados >= CANT_OBJ_COMPRAR_ANDYPOLIS);
}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_edad_piedra(){
    return (inventario.obtener_cantidad_de_andycoins() >= CANT_OBJ_EDAD_PIEDRA);
}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_bombardero(){
    Bombardero: haber usado 5 bombas. 
}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_energetico(){
    return (energia >= CANT_OBJ_ENERGETICO);
}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_letrado(){
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_ESCUELA== catalogo.consulta(i) -> nombre)
            return (catalogo.consulta(i) -> cantidad_construidos == catalogo.consulta(i) -> maximos_permitidos);
    }
}

// ------------------------------------------------------------------------------------------------------------


M//inero: haber construido una mina de cada tipo. 
// Este esta implementado bien feo
bool Jugador::chequear_objetivo_minero(){
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_MINA == catalogo.consulta(i) -> nombre)
            for(int i=0; !catalogo.vacia(); i++){
                if(STR_MINA_ORO == catalogo.consulta(i) -> nombre)
                    return true;
    }

    return false;

// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_cansado(){
    return (energia == CANT_OBJ_CANSADO);

}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_constructor(){
    for(int i=0; !catalogo.vacia(); i++){
        if(catalogo.consulta(i) -> cantidad_construidos == 0)
            return false;
    }
    return true;
}


// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_armado(){  
    return (inventario.obtener_cantidad_de_bombas() >= CANT_OBJ_ARMADO);
}

// ------------------------------------------------------------------------------------------------------------


bool Jugador::chequear_objetivo_extremista(){  
   Extremista: haber comprado 500 bombas en una partida.

}
*/