#ifndef ARMADO_H
#define ARMADO_H

#include "../objetivo.h"

const int CANT_BOMBAS_OBJETIVO = 10;
const string CONDICIONES_ARMADO = "Tener 10 bombas en el inventario";

class Armado: public Objetivo {

    public:
        Armado();
        ~Armado(){};

        string obtener_condiciones();
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas); 
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas);
};

#endif

