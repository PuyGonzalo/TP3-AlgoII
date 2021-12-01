#include <iostream>
#include "constructor.h"


// ------------------------------------------------------------------------------------------------------------


Constructor::Constructor(string nombre_obj, bool realizado) : Objetivo(nombre_obj,realizado){}


// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_condiciones(){
    return CONDICIONES_CONSTRUCTOR;
}


// ------------------------------------------------------------------------------------------------------------


bool  Constructor::chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
    /* mis edificios una lista???
    if(mis_edificios.obtener_longitud() != CANTIDAD_EDIFICIOS)
        return false;

    bool construidos = true;

    for(int i=0; i < mis_edificios.obtener_longitud(); i++){
        if(mis_edificios.consultar(i) -> cant_contruidos == 0 )
            construidos = false;
    }
*/
    return false;
}

/*
// ------------------------------------------------------------------------------------------------------------


string  Constructor::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    
    int  construidos = 0;
    int i;
   
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if(catalogo.consultar(i) -> cant_contruidos == 0 )
             construidos++;
    }

    return std::to_string(  construidos % i ) + "%";
   
}
*/