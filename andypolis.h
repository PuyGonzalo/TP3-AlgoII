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
#include "mapa.h"
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
    Mapa mapa;
//  Lista<Datos_edificio*> catalogo; VA A SER UN ARBOL
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
    // pos: carga las ubicaciones de materiales y los edificios de cada jugador
    Estado_t cargar_ubicaciones(ifstream& archivo_ubics);

    // pre: -
    // pos: carga los edificios de un jugador en particular
    Estado_t cargar_edificios_jugador(ifstream& archivo_ubics, Jugador_t jugador);

    // pre: -
    // pos: carga los materiales en el mapa
    Estado_t cargar_materiales_mapa(ifstream& archivo_ubics);

    // pre: -
    // pos: posiciona un jugador en el mapa
    Estado_t posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: muestra el inventario del jugador pedido
    void mostrar_inventario(Jugador_t jugador);

    // pre: -
    // pos: muestra el mapa
    void mostrar_mapa();


};


#endif // ANDYPOLIS_H