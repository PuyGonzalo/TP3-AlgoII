#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <sstream>
//#include "lista.h"
#include "errores.h"
#include "herramientas.h"

using namespace std;

const string STR_MINA = "mina";
const string STR_ASERRADERO = "aserradero";
const string STR_FABRICA = "fabrica";
const string STR_ESCUELA = "escuela";
const string STR_OBELISCO = "obelisco";
const string STR_P_ELECTRICA = "planta electrica";
const string STR_MINA_ORO = "mina oro";

// VER DESPUES SI DEJAMOS ESTO O LO SACAMOS Y HACEMOS UNA CLASE.

/*
struct Datos_edificio{
    string nombre; // si no se usa sacar 
    double costo_piedra;
    double costo_madera;
    double costo_metal;
    int cantidad_construidos;
    int maximos_permitidos;
    bool brinda_material;
};
*/

class Edificio{

protected:
    // Atributos
    char identificador;
    Jugador_t creador;


public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR edificio
    Edificio();

    // pre: identificador valido (entre los que hay en la consigna)
    // pos: CONSTRUCTOR con parametro
    Edificio(char identificador, Jugador_t creador);

    // pre: -
    // pos: DESTRUCTOR de edificios
    virtual ~Edificio(){};

    // pre: -
    // pos: devuelve el tipo/nombre del edificio
    virtual string obtener_tipo_edificio() = 0;

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales) el identificador del material que brinda el edificio
    virtual char obtener_recurso() = 0;

    // pre: -
    // pos: obtiene (en caso de poder brindar materiales) la cantidad de material que brinda el edificio
    virtual double obtener_cantidad_recurso() = 0;

    // pre: -
    // pos: devuelve el identificador del edificio
    char obtener_identificador();

    // pre: -
    // pos: devuelve el creador del edificio
    Jugador_t obtener_creador();

};


#endif // EDIFICIO_H