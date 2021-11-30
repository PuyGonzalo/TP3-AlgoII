#include <iostream>
#include "comprar_andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Comprar_andypolis::Comprar_andypolis(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){
    this -> cant_andycoins_gastados = 0;
}


// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_condiciones(){
    return CONDICIONES_COMPRAR_ANDYPOLIS;
}


// ------------------------------------------------------------------------------------------------------------


bool Comprar_andypolis::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('C');
    int andycoins_gastadas = 0;
    invetario.consulta(ubicacion)->obtener_andycoins_gastadas(andycoins_gastadas);

    return ( andycoins_gastadas> CANT_ANDYCOINS);
}

// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('C');
    int andycoins_gastadas = 0;
    invetario.consulta(ubicacion)->obtener_andycoins_gastadas(andycoins_gastadas);

    return std::to_string(andycoins_gastadas % CANT_ANDYCOINS ) + "%";
   
}
