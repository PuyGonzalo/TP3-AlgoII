#ifndef LETRADO_H
#define LETRADO_H

#include "../objetivo.h"

const int CANT_ESCUELAS_MAXIMO = 5;
const string CONDICIONES_LETRADO = "Haber construido el máximo posible de escuelas.";

class Letrado: public Objetivo {

    public:
        Letrado();
        ~Letrado(){};

        string obtener_condiciones();
        void actualizar_cumplimiento(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};

#endif

