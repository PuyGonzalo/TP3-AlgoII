#ifndef BOMBAS_H
#define BOMBAS_H

#include "../material.h"


class Bombas: public Material {
    private:
        int bombas_usadas;
        int bombas_compradas;
    public:
    
    // pre: -
    // pos: CONSTRUCTOR y DESTRUCTOR de bombas
    Bombas(double cantidad);
    ~Bombas(){};

    // pre: -
    // post: devuelve una string con el tipo de material que es (bombas)
    string obtener_nombre_material();

    //Para el objetivo bombardero
    void asignar_bomas_usadas(int cantidad);
    int obtener_bombas_usadas();

    //Para el objetivo extremista:
    void asignar_bomas_compradas(int cantidad);
    int obtener_bombas_compradas();

};


#endif // BOMBAS_H
