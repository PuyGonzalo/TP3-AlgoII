#include "energetico.h"

Energetico::Energetico(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado , andycoins,bombas_compradas, bombas_usadas,nombre_obj){
}

string Energetico::obtener_nombre(){
    return nombre;
}

string Energetico::obtener_condiciones(){
    return CONDICIONES_ENERGETICO;
}

bool Energetico::chequear_cumplimiento(const int &cant_energia,const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    return (cant_energia >= CANT_ENERGIA);
}

string Energetico::obtener_progreso(){
    return std::to_string(cant_energia % CANT_ENERGIA ) + "%";
   
}