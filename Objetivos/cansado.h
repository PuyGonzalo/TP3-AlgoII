#ifndef CANSADO_H
#define CANSADO_H

#include "../objetivo.h"

const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    
    public:
        Cansado();
        ~Cansado(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
};

#endif

