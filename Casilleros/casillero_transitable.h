#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "../material.h"
#include "../casillero.h"
#include "../formatos.h"

class Casillero_transitable: public Casillero {

private:
    // Atributos
    Material* material_ocupado = nullptr; // al momento de crearse no tiene nada "en el piso"

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable
    Casillero_transitable(Superficie* superficie, int coord_x, int coord_y, bool ocupado);

    // pre: -
    // pos: CONSTRUCTOR de un casillero transitable default
    Casillero_transitable():Casillero(){};

    // pre: -
    // pos: DESTRUCTOR de un casillero transitable
    ~Casillero_transitable();

    // pre: -
    // pos: imprime una letra que representa el material que tiene "en el piso" y el color de la superficie del casillero
    void imprimir_casillero();

    // pre: -
    // pos: imprime un mensaje diciendo si tiene o no un material y que es un casillero transitable
    void consultar_casillero();

    // pre: -
    // pos: pone/"tira" un material en el casillero
    void poner_material(Material* material);

    // pre: debe ser un casillero ocupado (validado en funcionas mas externas)
    // pos: devuelve el nombre del material que esta ocupando el casillero
    string obtener_nombre_objeto_de_casillero();

    // pre: - 
    // pos: momentaneamente no tiene sentido pedirle info de un material a un casillero transitable (metodo virtual ret =/= void)
    char obtener_material_brindado_de_casillero(){return ' ';};

    // pre: - 
    // pos: momentaneamente no tiene sentido pedirle info de un material a un casillero transitable (metodo virtual ret =/= void)
    double obtener_cantidad_material_brindado_de_casillero(){return 0;};

};



#endif // CASILLERO_TRANSITABLE_H