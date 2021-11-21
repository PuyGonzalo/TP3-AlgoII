#include "yacimiento.h"


// ------------------------------------------------------------------------------------------------------------


Yacimiento::Yacimiento(char identificador, char creador) : Edificio(identificador, creador){}


// ------------------------------------------------------------------------------------------------------------


string Yacimiento::obtener_tipo_edificio(){
    return STR_YACIMIENTO;
}