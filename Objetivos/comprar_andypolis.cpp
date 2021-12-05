#include <iostream>
#include "comprar_andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Comprar_andypolis::Comprar_andypolis() : Objetivo(OBJ_COMPRAR_ANDYNOPOLIS, false){}


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


string Comprar_andypolis::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
     double total = ( (double) inventario.obtener_andycoins_gastadas() ) + inventario.obtener_cantidad_de_andycoins();

    return PROGRESO_OBJ + std::to_string( CANT_ANDYCOINS - total ) + " andycoins";
   
}
