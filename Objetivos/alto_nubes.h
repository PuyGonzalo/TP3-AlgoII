#ifndef ALTO_NUBES_H
#define ALTO_NUBES_H

#include "../objetivo.h"

const string CONDICIONES_MAS_ALTO_NUBES = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Alto_nubes: public Objetivo {

    public:
        Alto_nubes(string nombre_obj, bool realizado);
        ~Alto_nubes(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(   const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,    Vector<Edificio_jugador> & mis_edificios);
};

#endif

