#include "planta_electrica.h"


// ------------------------------------------------------------------------------------------------------------


Planta_electrica::Planta_electrica(char identificador, char creador) : Edificio(identificador, creador){

    this -> cantidad_energia_brindada = CANTIDAD_ENERGIA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Planta_electrica::obtener_tipo_edificio(){

    return STR_P_ELECTRICA;
}