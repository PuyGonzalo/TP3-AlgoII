#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H

#include <sstream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include "parser.h"
#include "inventario.h"
#include "jugador.h"
//#include "mapa.h"
#include "errores.h"
#include "herramientas.h"

using namespace std;

const int MAX_EDIF_CONSTRUIBLES_INICIAL = 3;
const int AMPLIACION_EDIF_CONSTRUIBLES = 2;
const char DELIM_ESPACIO = ' ';

const string CONFIRMACION_AFIRMATIVA_CONSTRUCCION = "SI";
const string CONFIRMACION_NEGATIVA_CONSTRUCCION = "NO";


class Andypolis{

private:
    // Atributos
//    Mapa mapa;
//    Lista<Datos_edificio*> catalogo;
    Jugador jugador_uno;
    Jugador jugador_dos;


public:
    // Metodos

    // pre: archivos bien formados
    // pos: CONSTRUCTOR de andypolis a partir de todos los archivos
    Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats);

    // pre: -
    // pos: DESTRUCTOR de andypolis
    ~Andypolis(){};

    // pre: -
    // pos: muestra el inventario del jugador pedido
    void mostrar_inventario(Jugador_t jugador);


};


#endif // ANDYPOLIS_H