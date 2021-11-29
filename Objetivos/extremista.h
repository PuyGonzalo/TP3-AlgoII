#ifndef EXTREMISTA_H
#define EXTREMISTA_H



const int CANT_BOMBAS_COMPRADAS = 100;
const string CONDICIONES_EXTREMISTA = "Haber comprado 500 bombas en una partida";

class Extremista: public Objetivo {
    private:

    public:
        Extremista(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};
#endif

