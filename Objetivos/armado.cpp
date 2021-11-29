#include "armado.h"

Armado::Armado(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado, andycoins, bombas_compradas,bombas_usadas,nombre_obj ){
}

string Armado::obtener_nombre(){
    return nombre;
}

string Armado::obtener_condiciones(){
    return CONDICIONES_ARMADO;
}

bool Armado::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    if(inventario.obtener_cantidad_de_bombas()<CANT_BOMBAS_ALMACENADAS)
        return false;
}

string Armado::obtener_progreso(){
    return std::to_string(inventario.obtener_cantidad_de_bombas()%CANT_BOMBAS_ALMACENADAS)+"%";
   
}