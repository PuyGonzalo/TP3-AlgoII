#include "mina_oro.h"

Mina_oro::Mina_oro(char identificador, char creador) : Edificio(identificador, creador){

    this -> identificador_material_brindado = IDENTIF_ANDYCOINS;
    this -> cantidad_material_brindado = CANTIDAD_ANDYCOINS_BRINDADAS;
}


// ------------------------------------------------------------------------------------------------------------


string Mina_oro::obtener_tipo_edificio(){

    return STR_MINA_ORO;
}


// ------------------------------------------------------------------------------------------------------------


char Mina_oro::obtener_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Mina_oro::obtener_cantidad_recurso(){

    return this -> cantidad_material_brindado;
}