#include "bombardero.h"

Bombardero::Bombardero(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj ){

}

string Bombardero::obtener_nombre(){
    return nombre;
}

string Bombardero::obtener_condiciones(){
    return CONDICIONES_BOMBARDERO;
}

bool Bombardero::chequear_cumplimiento(const int &cant_energia,const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    if(cant_bombas_usadas < CANT_BOMBAS_USADAS)
        return false;
}

string Bombardero::obtener_progreso(){
    return std::to_string(cant_bombas_usadas % CANT_BOMBAS_USADAS ) + "%";
   
}