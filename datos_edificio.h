#ifndef DATOS_EDIFICIO_H
#define DATOS_EDIFICIO_H

#include <string>

using namespace std;


class Datos_edificio {

    // Atributos
private:
    string nombre; // Por ahora lo dejo, puede volar a la mierda
    double costo_piedra;
    double costo_madera;
    double costo_metal;
    int maximos_permitidos;
    //bool brinda_material; // Puede o no quedar, veremos

public:
    // Metodos

    // pre:
    // pos:
    Datos_edificio();

    // pre:
    // pos:
    Datos_edificio(string nombre, double costo_piedra, double costo_madera, double costo_metal, int maximos_permitidos);

    // pre:
    // pos:
    ~Datos_edificio(){};

    // pre:
    // pos:
    string obtener_nombre_edificio();

    // pre:
    // pos:
    double obtener_costo_piedra();

    // pre:
    // pos:
    double obtener_costo_madera();

    // pre:
    // pos:
    double obtener_costo_metal();

    // pre:
    // pos:
    int obtener_maximos_permitidos();

};

#endif // DATOS_EDIFICIO_H