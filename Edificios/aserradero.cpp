#include "aserradero.h"



// ------------------------------------------------------------------------------------------------------------


Aserradero::Aserradero(char identificador, char creador) : Edificio(identificador, creador) {
    this -> identificador_material_brindado = IDENTIF_MADERA;
    this -> cantidad_material_brindado = CANTIDAD_MADERA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Aserradero::obtener_tipo_edificio(){
    
    return STR_ASERRADERO;
}


// ------------------------------------------------------------------------------------------------------------


char Aserradero::obtener_recurso(){

    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Aserradero::obtener_cantidad_recurso(){

    return this -> cantidad_material_brindado;
}
