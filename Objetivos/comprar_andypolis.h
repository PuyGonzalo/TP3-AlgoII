#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H



const int CANT_ANDYCOINS = 100000;
const string CONDICIONES_COMPRAR_ANDYPOLIS = " Haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)";

class Comprar_andypolis: public Objetivo {
    private:

    public:
        Comprar_andypolis(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

