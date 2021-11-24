#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include "edificio.h"
#include "herramientas.h"
#include "inventario.h"

using namespace std;


const char IDENTIFICADOR_JUGADOR_UNO = 'J';
const char IDENTIFICADOR_JUGADOR_DOS = 'U';


const int CANT_OBJETIVOS_SECUNDARIOS = 3;

const int CANT_OBJ_EDAD_PIEDRA = 50000;
const int CANT_OBJ_COMPRAR_ANDYPOLIS = 100000;
const int CANT_OBJ_BOMBARDERO = 5;
const int CANT_OBJ_CANSADO = 0;
const int CANT_OBJ_ARMADO = 10;

enum Objetivo_t{
    OBJ_OBELISCO,
    OBJ_COMPRAR_ANDYNOPOLIS,
    OBJ_EDAD_PIEDRA,
    OBJ_BOMBARDERO,
    OBJ_ENERGETICO,
    OBJ_LETRADO,
    OBJ_MINERO,
    OBJ_CANSADO,
    OBJ_CONSTRUCTOR,
    OBJ_ARMADO,
    OBJ_EXTREMISTA
};



class Jugador{
private:
        // Atributos
        char identificador;
        Jugador_t jugador;
//      int andycoins_gastados;
        Inventario inventario;
        Coordenadas ubicacion;
//      Objetivo_t objetivos_secundarios[CANT_OBJETIVOS_SECUNDARIOS];
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


//        Jugador();
//        Jugador(char id,int andycoins_gastados,Inventario invent, Coordenadas ubi,Objetivo_t objetivos, Lista<Datos_edificio*> edificios,  double cant_energia);

 //       char obtener_identificador();
//        int obtener_andycoins_gastados();
//        Inventario obtener_inventario();
//        Coordenadas obtener_ubicacion();
//        Objetivo_t obtener_objetivos_secundarios();
//        Lista<Datos_edificio*> obtener_catalogo();
//        double obtener_energia();

//        void setear_identificador( char id);
 //       void setear_andycoins_gastados( int cant_andycoins);
//        void setear_inventario( Inventario invent);
//        void setear_ubicacion( Coordenadas ubi);
//        void setear_objetivos_secundarios( Objetivo_t objetivos);
//        void setear_catalogo( Lista<Datos_edificio*> catalog);
 //       void setear_energia(  double cant_energia);
/*
        void sortear_objetivos_secundarios();
        void chequear_objetivos_secundarios();

        bool chequear_objetivo_obelisco();
        bool chequear_objetivo_comprar_andypolis();
        bool chequear_objetivo_edad_piedra();
        bool chequear_objetivo_bombardero();
        bool chequear_objetivo_energetico();
        bool chequear_objetivo_letrado();
        bool chequear_objetivo_minero();
        bool chequear_objetivo_cansado();
        bool chequear_objetivo_constructor();
        bool chequear_objetivo_armado();
        bool chequear_objetivo_extremista();
*/
};

#endif