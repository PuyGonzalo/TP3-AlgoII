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

/* ERROR DE INCLUDES
// ------------------------------------------------------------------------------------------------------------


bool Comprar_andypolis::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    return (cant_andycoins_gastados > CANT_ANDYCOINS);
}


// ------------------------------------------------------------------------------------------------------------


string Comprar_andypolis::obtener_progreso(){
    return std::to_string(cant_andycoins_gastados % CANT_ANDYCOINS ) + "%";
   
}
*/