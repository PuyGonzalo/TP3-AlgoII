#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include "edificio.h"
#include "herramientas.h"
#include "inventario.h"
#include "grafo.h"
#include "objetivo.h"

using namespace std;


const char IDENTIFICADOR_JUGADOR_UNO = 'J';
const char IDENTIFICADOR_JUGADOR_DOS = 'U';
const int CANT_OBJETIVOS = 3;
const int CANT_MAX_ENERGIA = 100;



class Jugador{
private:
        // Atributos
        char identificador;
        Jugador_t jugador;
<<<<<<< HEAD
        Grafo grafo;
//      int andycoins_gastados;
=======
        Grafo grafo;
>>>>>>> 39bc6ab1491dd8ff01c92dafbe4d408e49b79174
        Inventario inventario;
        Coordenadas ubicacion;
        Lista<Objetivos*> objetivos;
//      Lista<Datos_edificio*> catalogo;
//      double energia;

public:
        // Metodos

        // pre: -
        // pos: CONSTRUCTOR por parametros de un jugador
        Jugador(char id, Jugador_t jugador);

        // pre: -
        // pos: CONSTRUCTOR por default de un juegador
        Jugador();

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
        // pos: muestra el inventario del jugador
        void mostrar_inventario();

        // pre: -
        // pos: agrega un material a la lista de materiales del jugador
        void agregar_material_a_lista(Material* material);

        void sortear_objetivos();

        bool chequear_objetivos();


//        Jugador();
//        Jugador(char id,Inventario invent, Coordenadas ubi,Objetivo_t objetivos, Lista<Datos_edificio*> edificios,  double cant_energia);

 //       char obtener_identificador();
//        int obtener_andycoins_gastados();
//        Inventario obtener_inventario();
//        Coordenadas obtener_ubicacion();
//        Objetivo_t obtener_objetivos_secundarios();
//        Lista<Datos_edificio*> obtener_catalogo();
//        double obtener_energia();

//        void setear_identificador( char id);
//        void setear_inventario( Inventario invent);
//        void setear_ubicacion( Coordenadas ubi);
//        void setear_objetivos_secundarios( Objetivo_t objetivos);
//        void setear_catalogo( Lista<Datos_edificio*> catalog);
 //       void setear_energia(  double cant_energia);
/*
*/
};

#endif