#include <iostream>
#include "extremista.h"


// ------------------------------------------------------------------------------------------------------------


Extremista::Extremista(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){
    this -> cant_bombas_compradas = 0;
}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_condiciones(){
    return CONDICIONES_EXTREMISTA;
}


// ------------------------------------------------------------------------------------------------------------

/* error de includes 

bool Extremista::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    if(cant_bombas_compradas < CANT_BOMBAS_COMPRADAS)
        return false;
    return true; // IDEM EL OTRO, tal vez queda mas fachero usar (cond?) retu tru: false
}


// ------------------------------------------------------------------------------------------------------------

*/
string Extremista::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    return std::to_string(cant_bombas_compradas % CANT_BOMBAS_COMPRADAS ) + "%";
   
}
