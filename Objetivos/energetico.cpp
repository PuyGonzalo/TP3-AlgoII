#include <iostream>
#include "energetico.h"


// ------------------------------------------------------------------------------------------------------------


Energetico::Energetico(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_condiciones(){
    return CONDICIONES_ENERGETICO;
}


// ------------------------------------------------------------------------------------------------------------

/* errores de include
bool Energetico::chequear_cumplimiento(  int &cant_energia,  Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    return (cant_energia >= CANT_ENERGIA);
}


// ------------------------------------------------------------------------------------------------------------

*/
string Energetico::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    return std::to_string(cant_energia % CANT_ENERGIA ) + "%"; 
   
}
//de donde saca cant_energia?
