#include <iostream>
#include "extremista.h"


// ------------------------------------------------------------------------------------------------------------


Extremista::Extremista(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Extremista::obtener_condiciones(){
    return CONDICIONES_EXTREMISTA;
}


// ------------------------------------------------------------------------------------------------------------


bool Extremista::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return( inventario.obtener_bombas_compradas() < CANT_BOMBAS_COMPRADAS);
}


// ------------------------------------------------------------------------------------------------------------

/*
string Extremista::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_compradas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_compradas(bombas_compradas);

    return std::to_string(bombas_compradas % CANT_BOMBAS_COMPRADAS ) + "%";
   
}
*/