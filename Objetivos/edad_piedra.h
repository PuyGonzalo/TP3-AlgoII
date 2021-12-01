#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../objetivo.h"

const int CANT_PIEDRA = 50000;
const string CONDICIONES_EDAD_PIEDRA = "Tener en el inventario 50000 piedras";


class Edad_piedra: public Objetivo {
    
    public:
        Edad_piedra(string nombre_obj, bool realizado);
        ~Edad_piedra(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};

#endif

