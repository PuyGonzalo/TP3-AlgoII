#include <iostream>
#include "armado.h"


// ------------------------------------------------------------------------------------------------------------


Armado::Armado() : Objetivo(OBJ_ARMADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}


// ------------------------------------------------------------------------------------------------------------


void Armado::actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    this -> cumplido = (inventario.obtener_cantidad_de_bombas() < CANT_BOMBAS_OBJETIVO);
 
}


// ------------------------------------------------------------------------------------------------------------


string Armado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Falta/n comprar " << CANT_BOMBAS_OBJETIVO - inventario.obtener_cantidad_de_bombas() << " bomba/s";

    return sstream.str();
   
}
