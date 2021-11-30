#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "errores.h"

using namespace std;

const string STR_PIEDRA = "piedra";
const string STR_MADERA = "madera";
const string STR_METAL = "metal";
const string STR_ANDYCOINS = "andycoins";
const string STR_BOMBAS = "bombas";

const char IDENTIF_PIEDRA = 'S';
const char IDENTIF_MADERA = 'W';
const char IDENTIF_METAL = 'I';
const char IDENTIF_ANDYCOINS = 'C';
const char IDENTIF_BOMBA = 'X';
// BOMBA NO TIENE IDENTIFICADOR -> PONER IDENTIF_BOMBA = "X" o PONERLO DIRECTO EN CONSTRUCTOR? 


class Material{

protected:
    // Atributos
    char identificador;
    double cantidad;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR con parametros
    Material(double cantidad);

    // pre: -
    // pos: CONSTRUCTOR por default
    Material(); 

    // pre: -
    // pos: DESTRUCTOR de material
    virtual ~Material(){};

    // pre: -
    // pos: obtiene el identificador del material
    char obtener_identificador();

    // pre: -
    // pos: obtiene la cantidad de un material
    double obtener_cantidad();

    // pre: -
    // pos: suma una cantidad de material
    void sumar_cantidad(double cantidad);

    // pre: no se deberia restar mas del valor actual de material que hay (validar antes de usar)
    // pos: resta una cantidad de material
    void restar_cantidad(double cantidad);

    // pre: -
    // pos: obtiene que tipo/nombre de material es
    virtual string obtener_nombre_material() = 0;
    // #### para mi PONERLE "NOMBRE en vez de tipo", no lo cambie para no romper el codigo q lo use

    //Para el objetivo bombardero
    virtual void asignar_bomas_usadas(int cantidad){};
    virtual void obtener_bombas_usadas(int &cantidad_usadas){};

    //Para el objetivo extremista:
    virtual void asignar_bomas_compradas(int cantidad){};
    virtual void obtener_bombas_compradas(int &cantidad_compradas){};

    //Para el objetivo comprar_andypolis:
    virtual void aumentar_andycoins_gastadas(int cantidad){};
    virtual void obtener_andycoins_gastadas(int &cantidad_andycoins){};
};


#endif // MATERIAL_H
