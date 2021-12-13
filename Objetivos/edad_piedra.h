#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../objetivo.h"

const int CANT_PIEDRA_OBJETIVO = 50000;
const string CONDICIONES_EDAD_PIEDRA = "Tener en el inventario 50000 piedras";


class Edad_piedra: public Objetivo {
    
    public:

        // Metodos

        // pre:
        // pos:
        Edad_piedra();

        // pre:
        // pos:
        ~Edad_piedra(){};

        // pre:
        // pos:
        string obtener_condiciones();

        // pre:
        // pos:
        void actualizar_cumplimiento(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso(const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

