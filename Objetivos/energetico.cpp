#include <iostream>
#include "energetico.h"


// ------------------------------------------------------------------------------------------------------------


Energetico::Energetico(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_condiciones(){
    return CONDICIONES_ENERGETICO;
}


// ------------------------------------------------------------------------------------------------------------


bool Energetico::chequear_cumplimiento(  const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
    
    return (cant_energia == CANT_ENERGIA_MAXIMA);
}

/*
// ------------------------------------------------------------------------------------------------------------


string Energetico::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    return std::to_string(cant_energia % CANT_ENERGIA ) + "%"; 
   
}
*/