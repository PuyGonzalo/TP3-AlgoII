#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <cstdlib>
#include "andypolis.h"
#include "errores.h"
#include "herramientas.h"


using namespace std;



const string MSJ_INGRESO_EDIFICIO_CONSTRUIR = "Ingresa el nombre del edifico a construir:";

const string MSJ_INGRESO_EDIFICIO_MODIFICAR = "Ingresa el nombre del edifico a modificar:";


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

// pre:
// pos:
Estado_t reparar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador);

// pre: -
// pos: funcion para el menu para pedirle al usuario datos para consultar un casillero de andypolis
Estado_t consultar_coordenada(const Andypolis &andypolis);

// -------------------------------- NUEVA PARTIDA ---------------------------------------------------


// pre:
// pos:
Estado_t modificar_edificio_por_nombre(Andypolis &andypolis);

// pre:
// pos:
Estado_t validar_cantidad_materiales(string piedra, string  madera, string metal);

// pre:
// pos:
void crear_archivo_vacio(string ruta_archivo, fstream& archivo);

// pre:
// pos:
bool archivo_esta_vacio(fstream& archivo);

// pre:
// pos:
Estado_t consultar_ubicacion_jugadroes(Andypolis& andypolis);



#endif // UTILIDADES_H