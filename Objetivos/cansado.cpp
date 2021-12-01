#include <iostream>
#include "cansado.h"


// ------------------------------------------------------------------------------------------------------------


Cansado::Cansado(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}


// ------------------------------------------------------------------------------------------------------------



bool Cansado::chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
    
    return (cant_energia == 0);
}


/*
// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){     
    return std::to_string((CANT_MAX_ENERGIA-cant_energia) % CANT_MAX_ENERGIA ) + "%";
   
}     
*/