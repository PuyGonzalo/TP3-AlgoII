#ifndef EXTREMISTA_H
#define EXTREMISTA_H

#include "../objetivo.h"

const int CANT_BOMBAS_COMPRADAS = 100;
const string CONDICIONES_EXTREMISTA = "Haber comprado 500 bombas en una partida";

class Extremista: public Objetivo {

    public:
        Extremista(string nombre_obj, bool realizado);
        ~Extremista(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};
#endif

