#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../objetivo.h"

const int CANT_ANDYCOINS_OBJETIVO = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = "Haber juntado 100.000 andycoins a lo largo de la partida";

class Comprar_andypolis : public Objetivo {

    public:

        // Metodos

        // pre:
        // pos:
        Comprar_andypolis();

        // pre:
        // pos:
        ~Comprar_andypolis(){};

        // pre:
        // pos:
        string obtener_condiciones();
        
        // pre:
        // pos:
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

