#include "constructor.h"

Constructor::Constructor(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj){
}

string Constructor::obtener_nombre(){
    return nombre;
}

string Constructor::obtener_condiciones(){
    return CONDICIONES_CONSTRUCTOR;
}

bool Constructor::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    for(int i=0; !catalogo.vacia(); i++){
        if(catalogo.consulta(i) -> cantidad_construidos == 0)
            return false;
    }
}

string Constructor::obtener_progreso(){
    
    int construidos = 0;
    
    for(int i=0; !catalogo.vacia(); i++){
        if(catalogo.consulta(i) -> cantidad_construidos == 0)
            construidos++;
    }

    return std::to_string( construidos % i ) + "%";
   
}