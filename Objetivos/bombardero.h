#ifndef BOMBARDERO_H
#define BOMBARDERO_H

#include "../objetivo.h"

const int CANT_BOMBAS_USADAS = 5;
const string CONDICIONES_BOMBARDERO = "Haber usado 5 bombas";


class Bombardero: public Objetivo {
    private:
        int cant_bombas_usadas;

    public:
        Bombardero(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        // bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};

#endif

