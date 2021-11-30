#include <iostream>
#include "bombas.h"


// ------------------------------------------------------------------------------------------------------------


Bombas::Bombas(double cantidad) : Material(cantidad) {} // no tiene identif o ponemos '?'


// ------------------------------------------------------------------------------------------------------------


string Bombas::obtener_nombre_material(){

    return STR_BOMBAS;

}


// ------------------------------------------------------------------------------------------------------------


void Bombas::asignar_bomas_usadas(int cantidad){
    bombas_usadas = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


int Bombas::obtener_bombas_usadas(){
    return bombas_usadas;
}


// ------------------------------------------------------------------------------------------------------------


void Bombas::asignar_bomas_compradas(int cantidad){
    bombas_compradas = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


int Bombas::obtener_bombas_compradas(){
    return bombas_ucompradas;
}