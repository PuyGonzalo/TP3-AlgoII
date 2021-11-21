#include <iostream>
#include "betun.h"


Betun::Betun(char identificador) : Superficie(identificador) {

    this -> color = "ceniza";
    this -> transitable = true;
    this -> construible = false;
    this -> accesible = true;
    
}