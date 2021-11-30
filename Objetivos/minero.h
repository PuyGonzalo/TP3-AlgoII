#ifndef MINERO_H
#define MINERO_H

#include "../objetivo.h"

const int CANT_MINAS = 2;
const string CONDICIONES_MINERO = "Haber construido una mina de cada tipo.";

class Minero: public Objetivo {
    private:

    public:
        Minero(string nombre_obj, bool realizado);
        ~Minero(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  int &cant_energia,    Inventario & inventario,   Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo);
};

#endif

