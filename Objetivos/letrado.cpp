#include <iostream>
#include "letrado.h"


// ------------------------------------------------------------------------------------------------------------


Letrado::Letrado() : Objetivo(OBJ_LETRADO, false){}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_condiciones(){
    return CONDICIONES_LETRADO;
}



// ------------------------------------------------------------------------------------------------------------


bool Letrado::chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    /* Hay que usar el ABB?
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio == STR_ESCUELA ) 
            return ( catalogo.consultar(i) -> cantidad_construidos == CANT_ESCUELAS_MAXIMO);
    }
*/
    return false;
}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){
    /*int cant_contruidos = 0;
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_ESCUELA ) 
           cant_contruidos =catalogo.consultar(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_ESCUELAS ) + "%";
   */
    return PROGRESO_OBJ + " Letrado";
}
