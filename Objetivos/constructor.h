#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "../objetivo.h"

const string CONDICIONES_CONSTRUCTOR = "Construir un edificio de cada tipo";

class Constructor: public Objetivo {
    private:

    public:
        Constructor(string nombre_obj, bool realizado);
        ~Constructor(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador> & mis_edificios); 
        //string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Edificio_jugador> & catalogo);
};
#endif

