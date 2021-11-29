#include <iostream>
#include "bombardero.h"


// ------------------------------------------------------------------------------------------------------------


Bombardero::Bombardero(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){
    this -> cant_bombas_usadas = 0;
}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_condiciones(){
    return CONDICIONES_BOMBARDERO;
}


// ------------------------------------------------------------------------------------------------------------

/*
bool Bombardero::chequear_cumplimiento(const int &cant_energia,const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    if(cant_bombas_usadas < CANT_BOMBAS_USADAS)
        return false;
    else return true;
    // usar operador tri-noseqe return cant<a ? true:false algo asi 
}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_progreso(){
    return std::to_string(cant_bombas_usadas % CANT_BOMBAS_USADAS ) + "%";
   
}
*/