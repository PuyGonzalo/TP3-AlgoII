#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../objetivo.h"

const int CANT_BOMBAS_USADAS = 5;
const string CONDICIONES_BOMBARDERO = "Haber usado 5 bombas";


class Bombardero: public Objetivo {
    public:
        Bombardero();
        ~Bombardero(){};

        string obtener_condiciones();
        bool chequear_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
        string obtener_progreso( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
};

#endif

