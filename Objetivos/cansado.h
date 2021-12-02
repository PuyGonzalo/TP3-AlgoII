#ifndef CANSADO_H
#define CANSADO_H

#include "../objetivo.h"

const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    
    public:
        Cansado(string nombre_obj, bool realizado);
        ~Cansado(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        //string obtener_progreso(  double &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

