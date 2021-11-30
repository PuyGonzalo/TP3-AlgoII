#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}

string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}

/* errores

// ------------------------------------------------------------------------------------------------------------


bool Edad_piedra::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    return (inventario.obtener_cantidad_de_piedra() > CANT_PIEDRA);
}

*/
// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    return std::to_string(inventario.obtener_cantidad_de_piedra() % CANT_PIEDRA ) + "%";
   
}
