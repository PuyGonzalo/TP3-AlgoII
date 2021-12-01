#include <iostream>
#include "bombardero.h"


// ------------------------------------------------------------------------------------------------------------


Bombardero::Bombardero(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_condiciones(){
    return CONDICIONES_BOMBARDERO;
}


// ------------------------------------------------------------------------------------------------------------


bool Bombardero::chequear_cumplimiento(  const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
   
   return (  inventario.obtener_bombas_usadas() > CANT_BOMBAS_USADAS);
}


// ------------------------------------------------------------------------------------------------------------

/*
string Bombardero::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('X');
    int bombas_usadas = 0;
    invetario.consulta(ubicacion)->obtener_bombas_usadas(bombas_usadas);

    return std::to_string(bombas_usadas % CANT_BOMBAS_USADAS ) + "%";
   
}
*/