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

/*
// ------------------------------------------------------------------------------------------------------------


bool Extremista::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_compradas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_compradas(bombas_compradas);

    return( bombas_compradas < CANT_BOMBAS_COMPRADAS);
}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_compradas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_compradas(bombas_compradas);

    return std::to_string(bombas_compradas % CANT_BOMBAS_COMPRADAS ) + "%";
   
}
*/