#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../objetivo.h"

const int CANT_BOMBAS_USADAS = 5;
const string CONDICIONES_BOMBARDERO = "Haber usado 5 bombas";


class Bombardero: public Objetivo {
    public:
        Bombardero(string nombre_obj, bool realizado);
        ~Bombardero(){};

        string obtener_condiciones();
        bool chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios);
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

