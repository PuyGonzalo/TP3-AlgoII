#ifndef LETRADO_H
#define LETRADO_H

#include "../objetivo.h"

const int CANT_ESCUELAS_MAXIMO = 5;
const string CONDICIONES_LETRADO = "Haber construido el máximo posible de escuelas.";

class Letrado: public Objetivo {
    private:

    public:
        Letrado(string nombre_obj, bool realizado);
        ~Letrado(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

