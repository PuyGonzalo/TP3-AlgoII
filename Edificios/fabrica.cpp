#include "fabrica.h"


// ------------------------------------------------------------------------------------------------------------


Fabrica::Fabrica(char identificador, Jugador_t creador) : Edificio(identificador, creador) {

    this -> identificador_material_brindado = IDENTIF_METAL;
    this -> cantidad_material_brindado = CANTIDAD_METAL_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Fabrica::obtener_tipo_edificio(){
    return STR_FABRICA;
}


// ------------------------------------------------------------------------------------------------------------


char Fabrica::obtener_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Fabrica::obtener_cantidad_recurso(){
    
    return this -> cantidad_material_brindado;
}