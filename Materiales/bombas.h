#ifndef BOMBAS_H
#define BOMBAS_H

#include "../material.h"


class Bombas: public Material {

public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de bombas
    Bombas(double cantidad);
    ~Bombas(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (bombas)
    string obtener_tipo_material();

};


#endif // BOMBAS_H
