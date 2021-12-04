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


Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador);



#endif // UTILIDADES_H