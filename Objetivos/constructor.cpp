#include <iostream>
#include "constructor.h"


// ------------------------------------------------------------------------------------------------------------


Constructor::Constructor(string nombre_obj, bool realizado) : Objetivo(nombre_obj,realizado){}


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

/*
// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    
    int  construidos = 0;
    int i;
   
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if(catalogo.consultar(i) -> cant_contruidos == 0 )
             construidos++;
    }

    return std::to_string(  construidos % i ) + "%";
   
}
*/