#ifndef ENERGETICO_H
#define ENERGETICO_H



const int CANT_ENERGIA = 100;
const string CONDICIONES_ENERGETICO = "Haber terminado un turno con 100 puntos de energía";

class Energetico: public Objetivo {
    private:

    public:
        Energetico(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};


#endif

