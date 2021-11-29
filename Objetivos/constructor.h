#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "../objetivo.h"

const string CONDICIONES_CONSTRUCTOR = "Construir un edificio de cada tipo";

class Constructor: public Objetivo {
    private:

    public:
        Constructor(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};
#endif

