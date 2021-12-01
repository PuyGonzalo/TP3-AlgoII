#include <iostream>
#include "alto_nubes.h"


// ------------------------------------------------------------------------------------------------------------


Alto_nubes::Alto_nubes(string nombre_obj, bool realizado) : Objetivo(nombre_obj , realizado){}


// ------------------------------------------------------------------------------------------------------------


string Alto_nubes::obtener_condiciones(){
    return CONDICIONES_MAS_ALTO_NUBES;
}


// ------------------------------------------------------------------------------------------------------------


bool Alto_nubes::chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
    
    for(int i=0; i < mis_edificios.obtener_longitud(); i++){
        if( mis_edificios.consultar(i)->obtener_nombre() == STR_OBELISCO) 
            return (mis_edificios.consultar(i) -> obtener_cantidad_construidos() == 1);
    }
    return false;
}


// ------------------------------------------------------------------------------------------------------------

/*
string Alto_nubes::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & mis_edificios){

    int cant_contruidos = 0;
    for(int i=0; i < mis_edificios.obtener_longitud(); i++){
        if( mis_edificios.consultar(i) -> nombre_edificio ==STR_OBELISCO )
            cant_contruidos = mis_edificios.consultar(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_OBELISCOS ) + "%";
   
}
*/