#ifndef ESCUELA_H
#define ESCUELA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_ANDYCOINS_BRINDADAS = 25;

class Escuela: public Edificio {

private:
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR escuela
    Escuela(char identificador, char creador);

    // pre: -
    // pos: DESTRUCTOR escuela
    ~Escuela(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    char obtener_recurso();

    // pre: -
    // pos: no brinda material (se necesita por metodo virtual puro que se uso para devolver return =/= void)
    double obtener_cantidad_recurso();
};


#endif //ESCUELA_H
