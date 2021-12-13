#ifndef LETRADO_H
#define LETRADO_H

#include "../objetivo.h"

const int CANT_ESCUELAS_MAXIMO = 5;
const string CONDICIONES_LETRADO = "Haber construido el máximo posible de escuelas.";

class Letrado: public Objetivo {

    public:

        // Metodos

        // pre:
        // pos:
        Letrado();

        // pre:
        // pos:
        ~Letrado(){};

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

#endif

