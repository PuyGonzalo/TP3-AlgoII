#ifndef ANDYCOINS_H
#define ANDYCOINS_H

#include "../material.h"


class Andycoins: public Material {
    private:
        int andycoins_gastadas;

    public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de andycoins
    Andycoins(double cantidad);
    ~Andycoins(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (andycoins)
    string obtener_nombre_material();

    //Para el objetivo comprar_andypolis:
    void aumentar_andycoins_gastadas(int cantidad);
    void obtener_andycoins_gastadas(int &cantidad_andycoins);

};


#endif // ANDYCOINS_H
