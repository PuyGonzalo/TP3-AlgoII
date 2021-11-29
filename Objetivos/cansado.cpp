#include "cansado.h"

Cansado::Cansado(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ): Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj) {

}

string Cansado::obtener_nombre(){
    return nombre;
}

string Cansado::obtener_condiciones(){
    return CONDICIONES_CANSADO;
}

bool Cansado::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    return (cant_energia == 0);
}


string Cansado::obtener_progreso(){
    return std::to_string((CANT_MAX_ENERGIA-cant_energia) % CANT_MAX_ENERGIA ) + "%";
   
}