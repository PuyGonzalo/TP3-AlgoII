#ifndef MINERO_H
#define MINERO_H


const int CANT_MINAS = 2;
const string CONDICIONES_MINERO = "Haber construido una mina de cada tipo.";

class Minero: public Objetivo {
    private:

    public:
        Minero(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia,  const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

