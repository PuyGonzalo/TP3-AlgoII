#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}

string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}


/*
// ------------------------------------------------------------------------------------------------------------


bool Edad_piedra::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('S');
    int cant_piedras = invetario.consulta(ubicacion)->obtener_cantidad();
    return (cant_piedras > CANT_PIEDRA);
}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('S');
    int cant_piedras = invetario.consulta(ubicacion)->obtener_cantidad();
    return std::to_string( cant_piedras % CANT_PIEDRA ) + "%";
   
}
*/