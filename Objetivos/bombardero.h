#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../objetivo.h"

const int CANT_BOMBAS_USADAS_OBJETIVO = 5;
const string CONDICIONES_BOMBARDERO = "Haber usado 5 bombas";


class Bombardero: public Objetivo {
    public:
        // Metodos

        // pre:
        // pos:
        Bombardero();

        // pre:
        // pos:
        ~Bombardero(){};

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

