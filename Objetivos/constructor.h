#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H



const string CONDICIONES_CONSTRUCTOR = "Construir un edificio de cada tipo";

class Constructor: public Objetivo {
    private:

    public:
        Constructor(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};
#endif

