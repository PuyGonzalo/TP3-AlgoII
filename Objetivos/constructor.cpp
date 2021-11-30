#include <iostream>
#include "constructor.h"


// ------------------------------------------------------------------------------------------------------------


Constructor::Constructor(string nombre_obj, bool realizado) : Objetivo(nombre_obj,realizado){}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_condiciones(){
    return CONDICIONES_CONSTRUCTOR;
}


// ------------------------------------------------------------------------------------------------------------


bool  Constructor::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if(catalogo.consultar(i) -> cant_contruidos == 0 )
            return false;
    }
}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    int  construidos = 0;
    int i;
   
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if(catalogo.consultar(i) -> cant_contruidos == 0 )
             construidos++;
    }

    return std::to_string(  construidos % i ) + "%";
   
}

