#ifndef CANSADO_H
#define CANSADO_H

const string CONDICIONES_CANSADO = "Terminar un turno con 0 de energía.";

class Cansado: public Objetivo {
    private:

    public:
        Cansado(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia,const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

