#include <iostream>
#include "energetico.h"


// ------------------------------------------------------------------------------------------------------------


Energetico::Energetico() : Objetivo(OBJ_ENERGETICO, false){}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_condiciones(){
    return CONDICIONES_ENERGETICO;
}


// ------------------------------------------------------------------------------------------------------------


bool Energetico::chequear_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    
    return (cant_energia == CANT_ENERGIA_MAXIMA);
}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_progreso(   const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    return PROGRESO_OBJ + std::to_string(CANT_ENERGIA_MAXIMA - cant_energia ) + " energia"; 
   
}
