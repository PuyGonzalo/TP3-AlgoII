#include <iostream>
#include "edad_piedra.h"


// ------------------------------------------------------------------------------------------------------------


Edad_piedra::Edad_piedra(string nombre_obj, bool realizado) : Objetivo(nombre_obj, realizado){}

string Edad_piedra::obtener_condiciones(){
    return CONDICIONES_EDAD_PIEDRA;
}



// ------------------------------------------------------------------------------------------------------------


bool Edad_piedra::chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios){

    return (inventario.obtener_cantidad_de_piedra() > CANT_PIEDRA);
}

/*
// ------------------------------------------------------------------------------------------------------------


string Edad_piedra::obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo){
    int ubicacion = invectario.ubicacion_material_en_lista('S');
    int cant_piedras = invetario.consulta(ubicacion)->obtener_cantidad();
    return std::to_string( cant_piedras % CANT_PIEDRA ) + "%";
   
}
*/