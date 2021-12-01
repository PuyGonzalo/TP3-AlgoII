#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H

#include "../objetivo.h"

const int CANT_ANDYCOINS = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = " Haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)";

class Comprar_andypolis : public Objetivo {
    private:
        int cant_andycoins_gastados;

    public:
        Comprar_andypolis(string nombre_obj, bool realizado);
        ~Comprar_andypolis(){};

        string obtener_condiciones();
        
        bool chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

