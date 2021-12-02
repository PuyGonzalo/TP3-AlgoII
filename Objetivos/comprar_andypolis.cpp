#include <iostream>
#include "comprar_andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Comprar_andypolis::Comprar_andypolis(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_condiciones(){
    return CONDICIONES_COMPRAR_ANDYPOLIS;
}


// ------------------------------------------------------------------------------------------------------------


bool Comprar_andypolis::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    double total = ( (double) inventario.obtener_andycoins_gastadas() ) + inventario.obtener_cantidad_de_andycoins();
    return ( total > CANT_ANDYCOINS);
}


// ------------------------------------------------------------------------------------------------------------

/*
string Comprar_andypolis::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('C');
    int andycoins_gastadas = 0;
    invetario.consulta(ubicacion)->obtener_andycoins_gastadas(andycoins_gastadas);

    return std::to_string(andycoins_gastadas % CANT_ANDYCOINS ) + "%";
   
}
*/