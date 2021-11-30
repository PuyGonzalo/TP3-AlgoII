#ifndef CANSADO_H
#define CANSADO_H

#include "../objetivo.h"

const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    private:

    public:
        Cansado(string nombre_obj, bool realizado);
        ~Cansado(){};

        string obtener_condiciones();
        bool chequear_cumplimiento(  int &cant_energia,  Inventario & inventario,   Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Lista<Datos_edificio*> & catalogo);
};

#endif

