#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "../objetivo.h"

const string CONDICIONES_CONSTRUCTOR = "Construir un edificio de cada tipo";

class Constructor: public Objetivo {
    
    public:
        Constructor();
        ~Constructor(){};

        string obtener_condiciones();
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios); 
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios);
};


#endif

