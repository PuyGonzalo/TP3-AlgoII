#ifndef LETRADO_H
#define LETRADO_H

#include "../objetivo.h"

const int CANT_ESCUELAS = 5;
const string CONDICIONES_LETRADO = "Haber construido el máximo posible de escuelas.";

class Letrado: public Objetivo {
    private:

    public:
        Letrado(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};

#endif

