#ifndef ALTO_NUBES_H
#define ALTO_NUBES_H

#include "../objetivo.h"

const string CONDICIONES_MAS_ALTO_NUBES = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Alto_nubes: public Objetivo {

    public:

        // Metodos

        // pre:
        // pos:
        Alto_nubes();

        // pre:
        // pos:
        ~Alto_nubes(){};
        
        // pre:
        // pos:
        string obtener_condiciones();

        // pre:
        // pos:
        void actualizar_cumplimiento(   const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios,int cant_maxima_escuelas);
};

#endif

