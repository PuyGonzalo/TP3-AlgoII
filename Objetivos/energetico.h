#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../objetivo.h"

const int CANT_ENERGIA_MAXIMA = 100;
const string CONDICIONES_ENERGETICO = "Haber terminado un turno con 100 puntos de energía";


class Energetico: public Objetivo {

    public:
        Energetico(string nombre_obj, bool realizado);
        ~Energetico(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios);
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};


#endif

