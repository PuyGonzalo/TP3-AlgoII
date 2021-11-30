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

/*
// ------------------------------------------------------------------------------------------------------------


bool Bombardero::chequear_cumplimiento(  int &cant_energia,  Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_usadas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_usadas(bombas_usadas);

    return ( bombas_usadas > CANT_ANDYCOINS);
}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_usadas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_usadas(bombas_usadas);

    return std::to_string(bombas_usadas % CANT_BOMBAS_USADAS ) + "%";
   
}
*/