#ifndef ALTO_NUBES_H
#define ALTO_NUBES_H

#include "../objetivo.h"

const string CONDICIONES_MAS_ALTO_NUBES = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Alto_nubes: public Objetivo {

    public:
        Alto_nubes();
        ~Alto_nubes(){};

        string obtener_condiciones();
        void actualizar_cumplimiento(   const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas); 
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas);
};

#endif

