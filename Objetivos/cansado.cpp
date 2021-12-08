#include <iostream>
#include "cansado.h"


// ------------------------------------------------------------------------------------------------------------


Cansado::Cansado() : Objetivo(OBJ_CANSADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}


// ------------------------------------------------------------------------------------------------------------



void Cansado::actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    
    this -> cumplido = (cant_energia == 0);

}



// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){     
    
    if(this -> cumplido)
        return OBJ_CUMPLIDO;

    stringstream sstream;
    sstream << "Falta gastar " << cant_energia << " de energia";

    return sstream.str();
   
}     
