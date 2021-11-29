#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H

#include "../objetivo.h"

const int CANT_PIEDRA = 50000;
const string CONDICIONES_EDAD_PIEDRA = "Tener en el inventario 50000 piedras";


class Edad_piedra: public Objetivo {
    private:

    public:
        Edad_piedra(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};

#endif

