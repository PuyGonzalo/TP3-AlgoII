#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../objetivo.h"

const int CANT_ANDYCOINS_OBJETIVO = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = "Haber juntado 100.000 andycoins a lo largo de la partida";

class Comprar_andypolis : public Objetivo {

    public:
        Comprar_andypolis();
        ~Comprar_andypolis(){};

        string obtener_condiciones();
        
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        string obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
};

#endif

