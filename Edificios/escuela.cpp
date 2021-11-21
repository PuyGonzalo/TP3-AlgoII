#include "escuela.h"


// ------------------------------------------------------------------------------------------------------------


Escuela::Escuela(char identificador, char creador) : Edificio(identificador, creador){

    this -> identificador_material_brindado = IDENTIF_ANDYCOINS;
    this -> cantidad_material_brindado = CANTIDAD_ANDYCOINS_BRINDADAS;
}


// ------------------------------------------------------------------------------------------------------------


string Escuela::obtener_tipo_edificio(){

    return STR_ESCUELA;
}


// ------------------------------------------------------------------------------------------------------------


char Escuela::obtener_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Escuela::obtener_cantidad_recurso(){

    return this -> cantidad_material_brindado;
}