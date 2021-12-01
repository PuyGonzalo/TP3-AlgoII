#ifndef MINERO_H
#define MINERO_H

#include "../objetivo.h"

const int CANT_MINAS = 2;
const string CONDICIONES_MINERO = "Haber construido una mina de cada tipo.";

class Minero: public Objetivo {
    private:

    public:
        Minero(string nombre_obj, bool realizado);
        ~Minero(){};

        string obtener_condiciones();
        bool chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

