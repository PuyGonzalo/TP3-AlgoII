#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "../objetivo.h"

const string CONDICIONES_CONSTRUCTOR = "Construir un edificio de cada tipo";

class Constructor: public Objetivo {
    
    public:
        // Metodos

        // pre:
        // pos:
        Constructor();

        // pre:
        // pos:
        ~Constructor(){};

        // pre:
        // pos:
        string obtener_condiciones();

        // pre:
        // pos:
        void actualizar_cumplimiento( const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas); 
        
        // pre:
        // pos:
        string obtener_progreso(  const double &cant_energia, const Inventario &inventario, const Lista<Edificio_jugador*> &mis_edificios ,int cant_maxima_escuelas);
};


#endif

