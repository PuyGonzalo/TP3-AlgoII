#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
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

        // pre:
        // pos:
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
        // pos: devuelve la cantidad de energia que tiene el jugador
        double obtener_energia();

        // pre: -
        // pos: devuelve la cantidad de andycoins que tiene el jugador
        double obtener_cantidad_andycoins();

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

        // pre:
        // pos:
        int buscar_edificio_por_nombre(string nombre);

        // pre:
        // pos:
        Estado_t verificar_condiciones_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        // pre:
        // pos:
        void restar_materiales_construccion(string nombre, const ABB<Datos_edificio,string> &diccionario);

        //pre: -
        //post: Devuelvo la condicion del objetivo si esta cumplido
        bool chequear_objetivos_secundarios();

        // pre: -
        // pos: muestra el inventario del jugador
        void mostrar_inventario();

        // pre: -
        // pos: muestra los edificios construidos por el jugador (FALTA RESTANTES HASTA MAXIMO - NECESITO DIC catalogo :( -))
        void listar_edificios_construidos();

        // pre:
        // pos:
        void demoler_edificio(string nombre_edificio, const ABB<Datos_edificio,string> &diccionario);


private:
        //pre: opcion entre 0 y 8
        //post: devuelve uno de los objetivos que salio en el "sorteo"
        Objetivo* sortear_objetivos(int opcion_objetivo);

};

#endif