#include <iostream>
#include "andycoins.h"


// ------------------------------------------------------------------------------------------------------------


Andycoins::Andycoins(double cantidad) : Material(cantidad) {

    this -> identificador = IDENTIF_ANDYCOINS;
    
}


// ------------------------------------------------------------------------------------------------------------


string Andycoins::obtener_nombre_material(){

    return STR_ANDYCOINS;

}
void Andycoins::aumentar_andycoins_gastadas(int cantidad){
    andycoins_gastadas+=cantidad;
}
    
void Andycoins::obtener_andycoins_gastadas(int &cantidad_andycoins){
    cantidad_andycoins = this -> andycoins_gastadas;
}

