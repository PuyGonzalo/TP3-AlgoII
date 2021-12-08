#ifndef MINERO_H
#define MINERO_H

#include "../objetivo.h"

const int CANT_MINAS_OBJETIVO = 2;
const string CONDICIONES_MINERO = "Haber construido una mina de cada tipo.";

class Minero: public Objetivo {
    
    public:
        Minero();
        ~Minero(){};

        string obtener_condiciones();
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
};

#endif

