#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra() : Objetivo(OBJ_EDAD_PIEDRA, false){}


// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}



// ------------------------------------------------------------------------------------------------------------


bool Edad_piedra::chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios){

    return (inventario.obtener_cantidad_de_piedra() > CANT_PIEDRA);
}

/*
// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('S');
    int cant_piedras = invetario.consulta(ubicacion)->obtener_cantidad();
    return std::to_string( cant_piedras % CANT_PIEDRA ) + "%";
   
}
*/