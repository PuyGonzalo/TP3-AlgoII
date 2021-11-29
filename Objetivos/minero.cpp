#include "minero.h"

Minero::Minero(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  ):Objetivo(realizado,andycoins,bombas_compradas,bombas_usadas,nombre_obj){

}

string Minero::obtener_nombre(){
    return nombre;
}

string Minero::obtener_condiciones(){
    return CONDICIONES_MINERO;
}

bool Minero::chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo){
    
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

string Minero::obtener_progreso(){
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