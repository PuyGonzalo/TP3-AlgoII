#include <iostream>
#include "bombardero.h"


// ------------------------------------------------------------------------------------------------------------


Bombardero::Bombardero() : Objetivo(OBJ_BOMBARDERO, false){}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_condiciones(){
    return CONDICIONES_BOMBARDERO;
}


// ------------------------------------------------------------------------------------------------------------


bool Bombardero::chequear_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
   
   return (  inventario.obtener_bombas_usadas() > CANT_BOMBAS_USADAS);
}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){


    return PROGRESO_OBJ + std::to_string( CANT_BOMBAS_USADAS - inventario.obtener_bombas_usadas() ) + " bombas usadas";
   
}
