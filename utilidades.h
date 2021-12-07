#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <cstdlib>
#include "andypolis.h"
#include "errores.h"
#include "herramientas.h"


using namespace std;



const string MSJ_INGRESO_EDIFICIO_CONSTRUIR = "Ingresa el nombre del edifico a construir:";


// -------------------------------------------- FUNCIONES --------------------------------------------

// pre:
// pos:
Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador);

// pre:
// pos:
Estado_t construir_edificio_por_nombre(Andypolis &andypolis, Jugador_t jugador);

// pre:
// pos:
Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador);

// pre:
// pos:
Estado_t atacar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador);

// pre: -
// pos: funcion para el menu para pedirle al usuario datos para consultar un casillero de andypolis
Estado_t consultar_coordenada(const Andypolis &andypolis);

#endif // UTILIDADES_H