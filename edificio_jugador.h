#ifndef EDIFICIO_JUGADOR_H
#define EDIFICIO_JUGADOR_H

#include <string>
#include "lista.h"
#include "herramientas.h"
#include "errores.h"


using namespace std;

class Edificio_jugador{

private:
    // Atributos
    string nombre;
    char identificador;
    int cantidad_construidos;
    Lista<Coordenadas*> ubicacion;
    int vida;

public:
    // Metodos

    // pre: -
    // pos: Constructor por default
    Edificio_jugador();

    // pre: -
    // pos: Constructor por parametros
    Edificio_jugador(string nombre, char identificador, int vida);

    // pre: -
    // pos: Destruye los recursos utilizados
    ~Edificio_jugador();

    // pre:
    // pos:
    string obtener_nombre();

    // pre:
    // pos:
    char obtener_identificador();

    // pre:
    // pos:
    int obtener_cantidad_construidos();

    // pre:
    // pos:
    int obtener_vida();

    // pre:
    // pos:
    void agregar_coordenadas_a_lista(int coord_x, int coord_y);

    // pre:
    // pos:
    int buscar_coordenadas_en_lista(int coord_x, int coord_y);

    // pre:
    // pos:
    Estado_t quitar_coordenadas_a_lista(int coord_x, int coord_y);



};


#endif // EDIFICIO_JUGADOR_H