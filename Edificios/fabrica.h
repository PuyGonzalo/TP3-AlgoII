#ifndef FABRICA_H
#define FABRICA_H

#include "../edificio.h"
#include "../material.h"

const double CANTIDAD_METAL_BRINDADA = 40;

class Fabrica: public Edificio {
private:
    // Atributos
    char identificador_material_brindado;
    double cantidad_material_brindado;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR fabrica
    Fabrica(char identificador, Jugador_t creador);

    // pre: -
    // pos: DESTRUCTOR fabrica
    ~Fabrica(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: obtiene el identificador del material que brinda
    char obtener_recurso();

    // pre: -
    // pos: obtiene la cantidad de material que brinda
    double obtener_cantidad_recurso();
};


#endif //FABRICA_H
