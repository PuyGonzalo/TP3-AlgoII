#include <iostream>
#include "constructor.h"


// ------------------------------------------------------------------------------------------------------------


Constructor::Constructor() : Objetivo(OBJ_CONSTRUCTOR, false){}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_condiciones(){
    return CONDICIONES_CONSTRUCTOR;
}


// ------------------------------------------------------------------------------------------------------------


bool  Constructor::chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    if(mis_edificios.obtener_cantidad() == CANTIDAD_EDIFICIOS_OBJETIVO)
        return true;
    return false;
}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    


    return PROGRESO_OBJ + std::to_string( CANTIDAD_EDIFICIOS_OBJETIVO- mis_edificios.obtener_cantidad() ) + " edificios";
   
}
