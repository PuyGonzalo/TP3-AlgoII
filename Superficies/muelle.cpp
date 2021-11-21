#include <iostream>
#include "muelle.h"


Muelle::Muelle(char identificador) : Superficie(identificador) {

    this -> color = "marron";
    this -> transitable = true;
    this -> construible = false;
    this -> accesible = true;
    
}