#ifndef ARMADO_H
#define ARMADO_H

#include "../objetivo.h"

const int CANT_BOMBAS_ALMACENADAS = 10;
const string CONDICIONES_ARMADO = "Tener 10 bombas en el inventario";

class Armado: public Objetivo {

    public:
        Armado();
        ~Armado(){};

        string obtener_condiciones();
        bool chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        //string obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador*> & catalogo);
};

#endif

