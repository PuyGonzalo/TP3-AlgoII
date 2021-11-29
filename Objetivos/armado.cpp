#include <iostream>
#include "armado.h"


// ------------------------------------------------------------------------------------------------------------


Armado::Armado(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}

/* banda de errores
// ------------------------------------------------------------------------------------------------------------


bool Armado::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    if(inventario.obtener_cantidad_de_bombas()<CANT_BOMBAS_ALMACENADAS)
        return false;
}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_progreso(){
    return std::to_string(inventario.obtener_cantidad_de_bombas()%CANT_BOMBAS_ALMACENADAS)+"%";
   
}
*/