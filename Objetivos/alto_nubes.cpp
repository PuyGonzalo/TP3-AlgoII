#include <iostream>
#include "alto_nubes.h"


// ------------------------------------------------------------------------------------------------------------


Alto_nubes::Alto_nubes(string nombre_obj, bool realizado) : Objetivo(nombre_obj , realizado){}


// ------------------------------------------------------------------------------------------------------------


string Alto_nubes::obtener_condiciones(){
    return CONDICIONES_MAS_ALTO_NUBES;
}

/*
// ------------------------------------------------------------------------------------------------------------


bool Alto_nubes::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_OBELISCO ) 
            return (catalogo.consultar(i) -> cantidad_construidos == 0);
    }
    return false;
}


// ------------------------------------------------------------------------------------------------------------


string Alto_nubes::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){

    int cant_contruidos = 0;
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_OBELISCO )
            cant_contruidos = catalogo.consultar(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_OBELISCOS ) + "%";
   
}
*/