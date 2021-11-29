#include "extremista.h"

Extremista::Extremista(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj){
    nombre = OBJ_EXTREMISTA;
    cumplido = false;
}

string Extremista::obtener_nombre(){
    return nombre;
}

string Extremista::obtener_condiciones(){
    return CONDICIONES_EXTREMISTA;
}

bool Extremista::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    if(cant_bombas_compradas < CANT_BOMBAS_COMPRADAS)
        return false;
}

string Extremista:obtener_progreso(){
    return std::to_string(cant_bombas_compradas % CANT_BOMBAS_COMPRADAS ) + "%";
   
}