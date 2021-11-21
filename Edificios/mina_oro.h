#ifndef MINA_ORO_H
#define MINA_ORO_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_ANDYCOINS_BRINDADAS = 50;

class Mina_oro: public Edificio {

private:
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR escuela
    Mina_oro(char identificador, char creador);

    // pre: -
    // pos: DESTRUCTOR escuela
    ~Mina_oro(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: 
    char obtener_recurso();

    // pre: -
    // pos: 
    double obtener_cantidad_recurso();
};

#endif //MINA_ORO