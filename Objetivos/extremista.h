#ifndef EXTREMISTA_H
#define EXTREMISTA_H

#include "../objetivo.h"

const int CANT_BOMBAS_COMPRADAS = 100;
const string CONDICIONES_EXTREMISTA = "Haber comprado 500 bombas en una partida";

class Extremista: public Objetivo {
    private:
        int cant_bombas_compradas;

    public:
        Extremista(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        //string obtener_progreso();
};
#endif

