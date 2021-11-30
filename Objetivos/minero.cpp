#include <iostream>
#include "minero.h"


// ------------------------------------------------------------------------------------------------------------


Minero::Minero(string nombre_obj, bool realizado):Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_condiciones(){
    return CONDICIONES_MINERO;
}

/* errores

// ------------------------------------------------------------------------------------------------------------


bool Minero::chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_MINA == catalogo.consulta(i) -> nombre)
            if(catalogo.consulta(i) -> cantidad_construidos)
            {
                for(int i=0; !catalogo.vacia(); i++){
                    if(STR_MINA_ORO == catalogo.consulta(i) -> nombre)
                        return true;
            }
            else 
                return false;
    }

    return false;
}

*/
// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo){
    int cant_minas = 0;
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_MINA == catalogo.consulta(i) -> nombre)
            if(catalogo.consulta(i) -> cantidad_construidos)
                cant_minas++;
    }
    
    for(int i=0; !catalogo.vacia(); i++){
        if(STR_MINA_ORO == catalogo.consulta(i) -> nombre)
            if(catalogo.consulta(i) -> cantidad_construidos)
                cant_minas++;
    }

    return std::to_string(cant_minas % CANT_MINAS ) + "%";
   
}
