#include <iostream>
#include "cansado.h"


// ------------------------------------------------------------------------------------------------------------


Cansado::Cansado() : Objetivo(OBJ_CANSADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}


// ------------------------------------------------------------------------------------------------------------



bool Cansado::chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    
    return (cant_energia == 0);
}



// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){     
    return PROGRESO_OBJ + std::to_string((100-cant_energia)) + " energia";
   
}     
