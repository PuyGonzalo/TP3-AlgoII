#include <iostream>
#include "bombas.h"


// ------------------------------------------------------------------------------------------------------------


Bombas::Bombas(double cantidad) : Material(cantidad) {} // no tiene identif o ponemos '?'


// ------------------------------------------------------------------------------------------------------------


string Bombas::obtener_nombre_material(){

    return STR_BOMBAS;

}
