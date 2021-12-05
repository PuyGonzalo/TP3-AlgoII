#include <iostream>
#include "armado.h"


// ------------------------------------------------------------------------------------------------------------


Armado::Armado() : Objetivo(OBJ_ARMADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}


// ------------------------------------------------------------------------------------------------------------


bool Armado::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return ( inventario.obtener_cantidad_de_bombas() < CANT_BOMBAS_ALMACENADAS );
 
}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){


    return PROGRESO_OBJ + std::to_string( CANT_BOMBAS_ALMACENADAS - inventario.obtener_cantidad_de_bombas()) + " bombas";
   
}
