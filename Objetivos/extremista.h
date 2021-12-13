#ifndef EXTREMISTA_H
#define EXTREMISTA_H

#include "../objetivo.h"

const int CANT_BOMBAS_COMPRADAS_OBJETIVO = 500;
const string CONDICIONES_EXTREMISTA = "Haber comprado 500 bombas en una partida";

class Extremista: public Objetivo {

    public:

        // Metodos

        // pre:
        // pos:
        Extremista();

        // pre:
        // pos:
        ~Extremista(){};

        // pre:
        // pos:
        string obtener_condiciones();

        // pre:
        // pos:
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};


#endif //EXTREMISTA_H

