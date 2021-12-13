#ifndef CANSADO_H
#define CANSADO_H

#include "../objetivo.h"

const double CANT_ENERGIA_OBJETIVO = 100;
const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    
    public:
        // Metodos
        
        // pre:
        // pos:
        Cansado();

        // pre:
        // pos:
        ~Cansado(){};

        // pre:
        // pos:
        string obtener_condiciones();

        // pre:
        // pos:
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

