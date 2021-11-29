#ifndef BOMBARDERO_H
#define BOMBARDERO_H

const int CANT_BOMBAS_USADAS = 5;
const string CONDICIONES_BOMBARDERO = "Haber usado 5 bombas";

class Bombardero: public Objetivo {
    private:

    public:
        Bombardero(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

