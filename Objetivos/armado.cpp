#include <iostream>
#include "armado.h"


// ------------------------------------------------------------------------------------------------------------


Armado::Armado() : Objetivo(OBJ_ARMADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}


// ------------------------------------------------------------------------------------------------------------


bool Armado::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return ( inventario.obtener_cantidad_de_bombas() < CANT_BOMBAS_ALMACENADAS );
 
}

/*
// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador*> & catalogo){
    int ubicacion = inventario.ubicacion_material_en_lista('X');
    int cantidad_bombas = inventario.consulta(ubicacion)->obtener_cantidad();

    return std::to_string( cantidad_bombas % CANT_BOMBAS_ALMACENADAS ) + "%";
   
}
*/