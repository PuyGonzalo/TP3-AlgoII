#include <iostream>
#include "bombardero.h"


// ------------------------------------------------------------------------------------------------------------


Bombardero::Bombardero() : Objetivo(OBJ_BOMBARDERO, false){}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_condiciones(){
    return CONDICIONES_BOMBARDERO;
}


// ------------------------------------------------------------------------------------------------------------


void Bombardero::actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas){
   
   this -> cumplido = (inventario.obtener_bombas_usadas() > CANT_BOMBAS_USADAS_OBJETIVO);

}


// ------------------------------------------------------------------------------------------------------------


string Bombardero::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas ){
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Falta/n usar " << CANT_BOMBAS_USADAS_OBJETIVO - inventario.obtener_bombas_usadas() << " bomba/s";

    return sstream.str();
   
}
