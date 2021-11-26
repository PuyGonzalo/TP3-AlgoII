#include "mina.h"


// ------------------------------------------------------------------------------------------------------------


Mina::Mina(char identificador, Jugador_t creador) : Edificio(identificador, creador) {

    this -> identificador_material_brindado = IDENTIF_PIEDRA;
    this -> cantidad_material_brindado = CANTIDAD_PIEDRA_BRINDADA;
}


// ------------------------------------------------------------------------------------------------------------


string Mina::obtener_tipo_edificio(){
    return STR_MINA;
}


// ------------------------------------------------------------------------------------------------------------


char Mina::obtener_recurso(){
    return this -> identificador_material_brindado;
}


// ------------------------------------------------------------------------------------------------------------


double Mina::obtener_cantidad_recurso(){
    return this -> cantidad_material_brindado;
}
