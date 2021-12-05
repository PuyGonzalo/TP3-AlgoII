#include <iostream>
#include "extremista.h"


// ------------------------------------------------------------------------------------------------------------


Extremista::Extremista() : Objetivo(OBJ_EXTREMISTA, false){}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_condiciones(){
    return CONDICIONES_EXTREMISTA;
}


// ------------------------------------------------------------------------------------------------------------


bool Extremista::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return( inventario.obtener_bombas_compradas() < CANT_BOMBAS_COMPRADAS);
}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return PROGRESO_OBJ + std::to_string(CANT_BOMBAS_COMPRADAS  - inventario.obtener_bombas_compradas() ) + " bombas compradas";
   
}
