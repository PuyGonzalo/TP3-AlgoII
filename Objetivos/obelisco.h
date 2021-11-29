#ifndef OBELISCO_H
#define OBELISCO_H



const string CONDICIONES_OBELISCO = "Construir el obelisco";
const int CANT_OBELISCOS = 1;

class Obelisco: public Objetivo {
    private:

    public:
        Obelisco(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas  );

        string obtener_nombre();
        string obtener_condiciones();
        bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo); 
        string obtener_progreso();
};

#endif

