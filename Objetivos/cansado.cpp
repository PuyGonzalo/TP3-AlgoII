#include <iostream>
#include "cansado.h"


// ------------------------------------------------------------------------------------------------------------


Cansado::Cansado(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}


// ------------------------------------------------------------------------------------------------------------

/* ERROR DE INCLUDES 

bool Cansado::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    return (cant_energia == 0);
}



// ------------------------------------------------------------------------------------------------------------


string Cansado::obtener_progreso(){     
    return std::to_string((CANT_MAX_ENERGIA-cant_energia) % CANT_MAX_ENERGIA ) + "%";
   
}           CANT MAX ENERGIA??? que es eso?

*/