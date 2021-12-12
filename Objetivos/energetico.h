#ifndef ENERGETICO_H
#define ENERGETICO_H

#include "../objetivo.h"

const int CANT_ENERGIA_MAXIMA = 100;
const string CONDICIONES_ENERGETICO = "Haber terminado un turno con 100 puntos de energía";


class Energetico: public Objetivo {

    public:
        Energetico();
        ~Energetico(){};

        string obtener_condiciones();
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};


#endif

