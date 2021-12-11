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
#include "datos_edificio.h"
#include "errores.h"
#include "herramientas.h"
#include "ABB.h"
#include "grafo.h"

using namespace std;

const int MAX_EDIF_CONSTRUIBLES_INICIAL = 3;
const int AMPLIACION_EDIF_CONSTRUIBLES = 2;
const char DELIM_ESPACIO = ' ';

const string CONFIRMACION_AFIRMATIVA_CONSTRUCCION = "SI";
const string CONFIRMACION_NEGATIVA_CONSTRUCCION = "NO";


const int RAND_MAX_PIEDRA = 2;
const int RAND_MAX_MADERA = 3;
const int RAND_MAX_METAL = 4;
const int RAND_MAX_ANDYCOINS = 1;



class Andypolis{

private:
    // Atributos
    Mapa mapa;
    ABB<Datos_edificio,string> diccionario;
    Jugador jugador_uno;
    Jugador jugador_dos;


public:
    // Metodos

    // pre: archivos bien formados
    // pos: CONSTRUCTOR de andypolis a partir de todos los archivos
    Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats, bool partida_nueva);

    // pre: -
    // pos: DESTRUCTOR de andypolis
    ~Andypolis();

    // pre: -
    // pos: completa la informacion de los jugadores (excepto ubicacion, claro)
    void cargar_informacion_jugadores();

    // pre:
    // pos:
    void cargar_inventarios(ifstream& archivo_mats);

    // pre: bien formado
    // pos: carga el diccionario (no le deciamos catalogo? xd)
    void cargar_diccionario(ifstream& archivo_edif);

    // pre: -
    // pos: carga las ubicaciones de materiales y los edificios de cada jugador
    Estado_t cargar_ubicaciones(ifstream& archivo_ubics);

    // pre: -
    // pos: carga los materiales en el mapa
    Estado_t cargar_materiales_mapa(ifstream& archivo_ubics);

    // pre: -
    // pos: carga los edificios de un jugador en particular
    Estado_t cargar_edificios_jugador(ifstream& archivo_ubics);

    // pre: -
    // pos: posiciona un jugador en el mapa
    Estado_t posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador);

    // pre:
    // pos:
    void cargar_edificio_a_jugador(string nombre, char identificador, int coord_x, int coord_y, Jugador_t jugador);

    // pre:
    // pos: 
    double obtener_energia_jugador(Jugador_t jugador);

    // pre:
    // pos:
    void agregar_energia_jugador(Jugador_t jugador, double energia);

    // pre:
    // pos:
    Estado_t comprar_bombas(Jugador_t jugador);

    // pre:
    // pos:
    bool esta_edificio(string nombre);

    // pre:
    // pos:
    Estado_t construir_edificio(string nombre, int coord_x, int coord_y, Jugador_t jugador);

    // pre:
    // pos:
    void modificar_edificio(string nombre, int piedra_nuevo , int madera_nuevo, int metal_nuevo);

    // pre:
    // pos:
    string construir_string_edificio(string nombre, int coord_x, int coord_y);

    // pre:
    // pos:
    Estado_t destruir_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre:
    // pos:
    Estado_t atacar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre:
    // pos:
    Estado_t reparar_edificio_de_coord(int coord_x, int coord_y, Jugador_t jugador);

    // pre: -
    // pos: LLUVIA DE RECURSOS chocolate raaain
    Estado_t lluvia_de_recursos();

    // pre: -
    // pos: 
    void recolectar_recursos_jugador(Jugador_t jugador);

    // pre: -
    // pos: deposita los recursos de los edificios del jugador que termino su turno
    void depositar_recursos_jugador(Jugador_t jugador);

    // pre: -
    // pos: se fija si el jugador gano (claramente va a actualizar primero el estado de los objetivos)
    bool gano_el_jugador(Jugador_t jugador);

    // pre: -
    // pos: muestra el inventario del jugador pedido
    void mostrar_inventario(Jugador_t jugador);

    // pre: -
    // pos: mostrar edificios construidos (FALTA RESTANTES HASTA MAXIMO)
    void listar_edificios_construidos(Jugador_t jugador);

    // pre:
    // pos:
    void listar_edificios_diccionario();

    // pre: -
    // pos: muestra el mapa
    void mostrar_mapa(int pos_visual_x, int pos_visual_y);

    // pre: Objetivos del jugador han sido iniciliazados
    // pos: Se muestran por consola los objetivos del jugador junto con su progreso
    void mostrar_objetivos(Jugador_t jugador);

    // pre:
    // pos:
    Estado_t consultar_casillero_de_mapa(int coord_x, int coord_y) const;

    // pre:
    // pos:
    void sortear_ubicacion_jugadores();


};


#endif // ANDYPOLIS_H