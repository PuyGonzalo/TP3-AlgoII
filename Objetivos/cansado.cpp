#include <iostream>
#include "cansado.h"


// ------------------------------------------------------------------------------------------------------------


Cansado::Cansado(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}


// ------------------------------------------------------------------------------------------------------------


/*
bool Cansado::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    return (cant_energia == 0);
}



// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){     
    return std::to_string((CANT_MAX_ENERGIA-cant_energia) % CANT_MAX_ENERGIA ) + "%";
   
}     
*/