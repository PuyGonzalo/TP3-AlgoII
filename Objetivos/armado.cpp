#include <iostream>
#include "armado.h"


// ------------------------------------------------------------------------------------------------------------


Armado::Armado(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}

/*
// ------------------------------------------------------------------------------------------------------------


bool Armado::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = inventario.ubicacion_material_en_lista('X');
    int cantidad_bombas = inventario.consulta(ubicacion)->obtener_cantidad();

    if( cantidad_bombas < CANT_BOMBAS_ALMACENADAS )
        return false;
}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = inventario.ubicacion_material_en_lista('X');
    int cantidad_bombas = inventario.consulta(ubicacion)->obtener_cantidad();

    return std::to_string( cantidad_bombas % CANT_BOMBAS_ALMACENADAS ) + "%";
   
}
*/