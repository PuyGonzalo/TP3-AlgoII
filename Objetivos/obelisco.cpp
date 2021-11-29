#include <iostream>
#include "obelisco.h"


// ------------------------------------------------------------------------------------------------------------


Obelisco::Obelisco(string nombre_obj, bool realizado) : Objetivo(nombre_obj , realizado){}


// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_condiciones(){
    return CONDICIONES_OBELISCO;
}

/* errores

// ------------------------------------------------------------------------------------------------------------


bool Obelisco::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_OBELISCO == catalogo.consulta(i) -> nombre)
            return (catalogo.consulta(i) -> cantidad_construidos == 0);
    }
    return false;
}


// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_progreso(){

    int cant_contruidos = 0;
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_OBELISCO == catalogo.consulta(i) -> nombre)
           cant_contruidos = catalogo.consulta(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_OBELISCOS ) + "%";
   
}


*/