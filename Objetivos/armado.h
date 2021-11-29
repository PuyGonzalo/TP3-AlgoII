#ifndef ARMADO_H
#define ARMADO_H

#include "../objetivo.h"

const int CANT_BOMBAS_ALMACENADAS = 10;
const string CONDICIONES_ARMADO = "Tener 10 bombas en el inventario";

class Armado: public Objetivo {
    private:

    public:
        Armado(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};

#endif

