#include <iostream>
#include "minero.h"


// ------------------------------------------------------------------------------------------------------------


Minero::Minero(string nombre_obj, bool realizado):Objetivo(nombre_obj, realizado){}


// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_condiciones(){
    return CONDICIONES_MINERO;
}



// ------------------------------------------------------------------------------------------------------------


bool Minero::chequear_cumplimiento(const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){
    /* Hago una lista
    bool construidos = true;
    for(int i=0; i < mis_edificios.obtener_longitud(); i++){

        
    }
    */
    return false;
}

/*
// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int cant_minas = 0;
    for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_MINA )
            if(catalogo.consultar(i) -> cantidad_construidos)
                cant_minas++;
    }
    
     for(int i=0; i < catalogo.obtener_longitud(); i++){
        if( catalogo.consultar(i) -> nombre_edificio ==STR_MINA_ORO ) 
            if(catalogo.consultar(i) -> cantidad_construidos)
                cant_minas++;
    }

    return std::to_string(cant_minas % CANT_MINAS ) + "%";
   
}
*/