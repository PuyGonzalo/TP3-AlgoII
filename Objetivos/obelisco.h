#ifndef OBELISCO_H
#define OBELISCO_H

#include "../objetivo.h"

const string CONDICIONES_OBELISCO = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Obelisco: public Objetivo {
    private:

    public:
        Obelisco(string nombre_obj, bool realizado);

        string obtener_condiciones();
        // error de includes
        //bool chequear_cumplimiento(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo);
};

#endif

