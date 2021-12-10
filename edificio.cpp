#include "edificio.h"


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(){

    this -> identificador = ' ';
    this -> creador = NADIE;
    this -> deposito = 0;

}


// ------------------------------------------------------------------------------------------------------------


Edificio::Edificio(char identificador, Jugador_t creador){

    this -> identificador = identificador;
    this -> creador = creador;
    this -> deposito = 0;

}


// ------------------------------------------------------------------------------------------------------------


double Edificio::recolectar_recursos(){

    double acumulado = this -> deposito;
    this -> deposito = 0;

    return acumulado;

}


// ------------------------------------------------------------------------------------------------------------


char Edificio::obtener_identificador(){
    return this -> identificador;
}


// ------------------------------------------------------------------------------------------------------------


Jugador_t Edificio::obtener_creador(){

    return creador;

}