#include <iostream>
#include "alto_nubes.h"


// ------------------------------------------------------------------------------------------------------------


Alto_nubes::Alto_nubes() : Objetivo(OBJ_MAS_ALTO_NUBES, false){}


// ------------------------------------------------------------------------------------------------------------


string Alto_nubes::obtener_condiciones(){
    return CONDICIONES_MAS_ALTO_NUBES;
}


// ------------------------------------------------------------------------------------------------------------


bool Alto_nubes::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    
    for(int i=0; i < mis_edificios.obtener_cantidad(); i++){
        if( mis_edificios.consulta_const(i) -> obtener_nombre() == STR_OBELISCO) 
            return (mis_edificios.consulta_const(i) -> obtener_cantidad_construidos() == 1);
    }
    return false;
}


// ------------------------------------------------------------------------------------------------------------


string Alto_nubes::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    int cantidad_construidos = 0; 

    for(int i=0; i < mis_edificios.obtener_cantidad(); i++){
        if( mis_edificios.consulta_const(i) -> obtener_nombre() == STR_OBELISCO) 
            cantidad_construidos++;
    }
    
    return PROGRESO_OBJ+ std::to_string( CANT_OBELISCOS-cantidad_construidos ) + " obelisco";
   
}
