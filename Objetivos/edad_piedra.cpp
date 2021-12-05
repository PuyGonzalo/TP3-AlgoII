#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra() : Objetivo(OBJ_EDAD_PIEDRA, false){}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}



// ------------------------------------------------------------------------------------------------------------


bool Edad_piedra::chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return (inventario.obtener_cantidad_de_piedra() > CANT_PIEDRA);
}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return PROGRESO_OBJ + std::to_string( CANT_PIEDRA - inventario.obtener_cantidad_de_piedra() ) + " piedras";
   
}
