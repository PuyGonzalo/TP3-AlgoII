#ifndef YACIMIENTO_H
#define YACIMIENTO_H

#include "../edificio.h"

class Yacimiento: public Edificio {
public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR yacimiento
    Yacimiento(char identificador, char creador);

    // pre: -
    // pos: DESTRUCOTR yacimiento
    ~Yacimiento(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    char obtener_recurso(){return ' ';}

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    double obtener_cantidad_recurso(){return 0;}
};


#endif //YACIMIENTO_H
