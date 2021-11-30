#include <iostream>
#include "objetivo.h"


// ------------------------------------------------------------------------------------------------------------


Objetivo::Objetivo(string nombre_obj, bool realizado){
    this -> nombre = nombre_obj;
    this -> cumplido = realizado;
}


// ------------------------------------------------------------------------------------------------------------


string Objetivo::obtener_nombre(){
    return nombre;
}
