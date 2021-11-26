#include "edificio.h"


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(){

    this -> identificador = ' ';
    this -> creador = NADIE;

}


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(char identificador, Jugador_t creador){

    this -> identificador = identificador;
    this -> creador = creador;

}


// ------------------------------------------------------------------------------------------------------------


char Edificio::obtener_identificador(){
    return this -> identificador;
}


// ------------------------------------------------------------------------------------------------------------


Jugador_t Edificio::obtener_creador(){

    return creador;

}