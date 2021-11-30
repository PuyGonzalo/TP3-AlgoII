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


void Bombas::obtener_bombas_usadas(int &cantidad_usadas){
    cantidad_usadas = this -> bombas_usadas;
}


// ------------------------------------------------------------------------------------------------------------


void Bombas::asignar_bomas_compradas(int cantidad){
    bombas_compradas = cantidad;
}


// ------------------------------------------------------------------------------------------------------------


void Bombas::obtener_bombas_compradas(int &cantidad_compradas){
    bombas_compradas = this -> bombas_compradas;
}