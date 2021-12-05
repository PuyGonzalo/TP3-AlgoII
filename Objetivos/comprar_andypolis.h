#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../objetivo.h"

const int CANT_ANDYCOINS = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = " Haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)";

class Comprar_andypolis : public Objetivo {

    public:
        Comprar_andypolis();
        ~Comprar_andypolis(){};

        string obtener_condiciones();
        
        bool chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        //string obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

