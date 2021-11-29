#include <iostream>
#include "letrado.h"


// ------------------------------------------------------------------------------------------------------------


Letrado::Letrado(string nombre_obj, bool realizado) : Objetivo(nombre_obj,realizado){}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_condiciones(){
    return CONDICIONES_LETRADO;
}

/*  me tira banda de errores

// ------------------------------------------------------------------------------------------------------------


bool Letrado::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_ESCUELA== catalogo.consulta(i) -> nombre)
            return (catalogo.consulta(i) -> cantidad_construidos == CANT_ESCUELAS);
    }
}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_progreso(){
    int cant_contruidos = 0;
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_ESCUELA== catalogo.consulta(i) -> nombre)
           cant_contruidos = catalogo.consulta(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_ESCUELAS ) + "%";
   
}

*/