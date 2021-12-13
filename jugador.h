#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <algorithm>
#include <random>
#include "edificio.h"
#include "herramientas.h"
#include "inventario.h"
#include "grafo.h"
#include "objetivo.h"
#include "vector.h"
#include "lista.h"
#include "ABB.h"

#include "edificio_jugador.h"
#include "Objetivos/armado.h"
#include "Objetivos/bombardero.h"
#include "Objetivos/cansado.h"
#include "Objetivos/comprar_andypolis.h"
#include "Objetivos/constructor.h"
#include "Objetivos/edad_piedra.h"
#include "Objetivos/energetico.h"
#include "Objetivos/extremista.h"
#include "Objetivos/letrado.h"
#include "Objetivos/minero.h"
#include "Objetivos/alto_nubes.h"


using namespace std;


const char IDENTIFICADOR_JUGADOR_UNO = 'J';
const char IDENTIFICADOR_JUGADOR_DOS = 'U';
const int CANT_OBJETIVOS_SORTEADOS = 3;
const int CANT_OBJETIVOS_SECUNDARIOS = 10;
const int CANT_MAX_ENERGIA = 100;
const double CANTIDAD_ENERGIA_NECESARIA_P_CONSTRUIR = 15;



class Jugador{
private:
        // Atributos
        char identificador;
        Jugador_t jugador;
        Coordenadas ubicacion;
        Lista<Edificio_jugador*> mis_edificios; //con mis ladrillos

        Grafo* grafo;
        Inventario inventario;
        Objetivo* objetivo_principal;
        Vector<Objetivo> objetivos_secundarios;
        double energia;

public:
        // Metodos

        // pre: -
        // pos: CONSTRUCTOR por default de un juegador
        Jugador();

        // pre: -
        // pos: DESTRUCTOR del jugador
        ~Jugador();

        // pre:
        // pos:
        void agregar_energia(double energia);

        // pre: que una funciona mas externa chequee que no quede negativa la energia
        // pos: resta energia
        void restar_energia(double energia);

        // pre: -
        // pos: asigna el identificador al jugador (con el que será visto en el mapa)
        void asignar_identificador(char identif);

        // pre: -
        // pos: asigna que jugador es (jugador 1 o 2)
        void asignar_numero_jugador(Jugador_t jugador);

        // pre: las coordenadas deben estar dentro del mapa (chequear en funcion superior)
        // pos: asigna la ubicacion en el mapa del jugador
        void asignar_ubicacion_jugador(int coord_x, int coord_y);

        // pre: -
        // pos: crea el grafo correspondiente al jugador
        void crear_grafo(const Mapa &mapa);

        // pre: -
        // pos: actualiza el grafo por si hubieron cambios
        void actualizar_grafo(const Mapa &mapa);

        // pre: -
        // pos: devuelve la cantidad de energia que tiene el jugador
        double obtener_energia();

        // pre: -
        // pos: devuelve la ubicacion que tiene el jugador
        Coordenadas obtener_ubicacion();

        // pre: -
        // pos: devuelve la cantidad de andycoins que tiene el jugador
        double obtener_cantidad_andycoins();

        // pre:
        // pos:
        int obtener_vida_edificio( int posicion_edificio, int orden_edificio);

        // pre:
        // pos:
        void sumar_vida_edificio( int posicion_edificio, int orden_edificio);

        // pre: -
        // pos: devuelve la cantidad de bombas que tiene el jugador
        double obtener_cantidad_bombas();

        // pre: -
        // pos: Creo los objetivos secundarios en el vector de objetivos_secundarios
        void sortear_objetivos_secundarios();

        // pre: -
        // pos: agrega un tipo de material al inventario del jugador
        void agregar_material_al_inventario(Material* material);

        // pre: -
        // pos: compra bombas para el jugador (y devuelve un error si no tiene las andycoins necesarias)
        Estado_t comprar_bombas();

        // pre:
        // pos:
        void agregar_edificio(string nombre, char identificador, int vida, int coord_x, int coord_y);

        // pre:
        // pos:
        int buscar_edificio_por_identificador(char identificador);

        // pre: Lista de edificios cargado desde el archivo
        // pos: Posicion del edificio en la lista.
        int buscar_edificio_por_nombre(string nombre);

        // pre:
        // pos:
        Estado_t verificar_condiciones_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre:
        // pos:
        Estado_t verificar_condiciones_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre:
        // pos:
        void restar_materiales_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre:
        // pos:
        void restar_materiales_reparacion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre:
        // pos:
        void restar_vida_edificio(int posicion_edificio, int orden_edificio);

        // pre:
        // pos:
        void restar_bombas();

        // pre:
        // pos:
        void aumentar_bombas_usadas();

        // pre:
        // pos:
        void recolectar_recursos(Mapa &mapa);

        // pre:
        // pos:
        void depositar_recursos(Mapa &mapa);

        // pre:
        // pos:
        Estado_t moverse_a_una_coord(int coord_x, int coord_y, Lista<Coordenadas*> &camino);

        // pre:
        // pos:
        void actualizar_estado_objetivos( int cant_maxima_escuelas);

        // pre:
        // pos: actualiza el estado de los objs del jugador y devuelve true si el jugador gano el juevo ya sea por objetivo principal o objetivos secundarios
        bool gane_el_juego( int cant_maxima_escuelas);

        // pre:
        // pos: devuelve verdadero si el jugador gano por objetivo principal (construir el obelisco)
        bool victoria_por_objetivo_principal();

        //pre: -
        //post: devuelve verdadero si el jugador gano por objetivos secundarios (cumplio 2 de los 3 asignados)
        bool victoria_por_objetivos_secundarios();

        // pre: -
        // pos: muestra el inventario del jugador
        void mostrar_inventario();

        // pre: -
        // pos: muestra los edificios construidos por el jugador (FALTA RESTANTES HASTA MAXIMO - NECESITO DIC catalogo :( -))
        void listar_edificios_construidos();

        // pre:
        // pos:
        void demoler_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y);

        // pre:
        // pos:
        void destruir_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario, int coord_x, int coord_y);
        
        // pre: El vector de objetivos_secundarios esta completo
        // pos: Se imprimen todos los objetivos secundarios y el objetivo principal por consola
        void mostrar_objetivos( int cant_maxima_escuelas);

        // pre:
        // pos: Devuelve la posicion en la lista de coordenadas
        int buscar_posicion_coordenadas( int posicion_edificio, int coord_x, int coord_y);

        // pre:
        // post:
        bool puede_repararse_edificio( int posicion, int orden_edificio);


private:
        //pre: opcion entre 0 y 8
        //post: devuelve uno de los objetivos que salio en el "sorteo"
        Objetivo* generar_objetivos_secundarios(int opcion_objetivo);

};

#endif