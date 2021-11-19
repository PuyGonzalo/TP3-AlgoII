#ifndef ANDYCOINS_H
#define ANDYCOINS_H

#include "../material.h"


class Andycoins: public Material {

public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de andycoins
    Andycoins(double cantidad);
    ~Andycoins(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (andycoins)
    string obtener_tipo_material();

};


#endif // ANDYCOINS_H
