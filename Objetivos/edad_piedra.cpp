#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra() : Objetivo(OBJ_EDAD_PIEDRA, false){}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}



// ------------------------------------------------------------------------------------------------------------


void Edad_piedra::actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    this -> cumplido = (inventario.obtener_cantidad_de_piedra() > CANT_PIEDRA_OBJETIVO);

}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Falta juntar " << CANT_PIEDRA_OBJETIVO - inventario.obtener_cantidad_de_piedra() << " de piedra";

    return sstream.str();
   
}
