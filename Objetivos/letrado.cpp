#include <iostream>
#include "letrado.h"


// ------------------------------------------------------------------------------------------------------------


Letrado::Letrado(string nombre_obj, bool realizado) : Objetivo(nombre_obj,realizado){}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_condiciones(){
    return CONDICIONES_LETRADO;
}



// ------------------------------------------------------------------------------------------------------------


bool Letrado::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_ESCUELA ) 
            return ( catalogo.consultar(i) -> cantidad_construidos == CANT_ESCUELAS);
    }
}


// ------------------------------------------------------------------------------------------------------------


string Letrado::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int cant_contruidos = 0;
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_ESCUELA ) 
           cant_contruidos =catalogo.consultar(i) -> cantidad_construidos;
    }
    
    return std::to_string( cant_contruidos % CANT_ESCUELAS ) + "%";
   
}