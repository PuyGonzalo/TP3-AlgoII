#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj ){
}

string Comprar_andypolis::obtener_nombre(){
    return nombre;
}

string Comprar_andypolis::obtener_condiciones(){
    return CONDICIONES_COMPRAR_ANDYPOLIS;
}

bool Comprar_andypolis::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
    return (cant_andycoins_gastados > CANT_ANDYCOINS);
}

string Comprar_andypolis::obtener_progreso(){
    return std::to_string(cant_andycoins_gastados % CANT_ANDYCOINS ) + "%";
   
}