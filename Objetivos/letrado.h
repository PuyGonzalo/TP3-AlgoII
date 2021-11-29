#ifndef LETRADO_H
#define LETRADO_H



const int CANT_ESCUELAS = 5;
const string CONDICIONES_LETRADO = "Haber construido el máximo posible de escuelas.";

class Letrado: public Objetivo {
    private:

    public:
        Letrado(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

