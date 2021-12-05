#include <iostream>
#include "minero.h"


// ------------------------------------------------------------------------------------------------------------


Minero::Minero():Objetivo( OBJ_MINERO, false){}


// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_condiciones(){
    return CONDICIONES_MINERO;
}



// ------------------------------------------------------------------------------------------------------------


bool Minero::chequear_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    int contador = 0;

    for(int i = 0 ; i < mis_edificios.obtener_cantidad() ; ++i){
        if(mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA || mis_edificios.consulta_const(i) -> obtener_nombre() == STR_MINA_ORO)
            contador++;
    }

    return(contador == 2); // CANTIDAD_DE_MINAS = 2;

}

/*
// ------------------------------------------------------------------------------------------------------------


string Minero::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
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