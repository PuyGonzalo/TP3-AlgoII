#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "../edificio.h"

const double CANTIDAD_ENERGIA_BRINDADA = 15;

class Planta_electrica: public Edificio {

private:
    // Atributos
    double cantidad_energia_brindada;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR planta electrica 
    Planta_electrica(char identificador, char creador);

    // pre: -
    // pos: DESTRUCTOR planta electrica 
    ~Planta_electrica(){};

    // pre: -
    // pos: obtiene el tipo de edificio que es (su "nombre")
    string obtener_tipo_edificio();

    // pre: -
    // pos: Energia no tiene un identificador, asi que este metodo simplemente devuelve un espacio en blanco
    char obtener_recurso(){return ' ';}

    // pre: -
    // pos: Devuelve la cantidad de energia que devuelve la planta electrica.
    double obtener_cantidad_recurso();
};


#endif //PLANTA_ELECTRICA_H
