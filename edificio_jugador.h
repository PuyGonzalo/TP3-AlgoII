#ifndef EDIFICIO_JUGADOR_H
#define EDIFICIO_JUGADOR_H

#include <string>
#include <sstream>
#include "lista.h"
#include "herramientas.h"
#include "errores.h"
#include "formatos.h"


using namespace std;

class Edificio_jugador{

private:
    // Atributos
    string nombre;
    char identificador;
    int cantidad_construidos;
    Lista<Coordenadas*> ubicaciones;
    Lista<int> vida;

public:
    // Metodos

    // pre: -
    // pos: Constructor por default
    Edificio_jugador();

    // pre: -
    // pos: Constructor por parametros
    Edificio_jugador(string nombre, char identificador );

    // pre: -
    // pos: Destruye los recursos utilizados
    ~Edificio_jugador();

    // pre:
    // pos:
    string obtener_nombre() const;

    // pre:
    // pos:
    char obtener_identificador();

    // pre:
    // pos:
    int obtener_cantidad_construidos() const;

    // pre:
    // pos:
    string obtener_ubicaciones_construidas_str() const;

    // pre:
    // pos:
    string obtener_vida_edificios_str() const;

    // pre:
    // pos:
    int obtener_vida( int posicion ) const;

    // pre:
    // pos:
    //string obtener_vida_str() const;

    // pre:
    // pos: si no tiene 100 de vida es porque necesita repararse
    bool puede_repararse( int posicion );

    // pre:
    // pos:
    void agregar_coordenadas_a_lista(int coord_x, int coord_y);

    // pre:
    // pos:
    void agregar_vida(int cantidad);

    // pre:
    // pos: Devuelve la posicion en la lista de coordenadas
    int buscar_coordenadas_en_lista(int coord_x, int coord_y);

    // pre:
    // pos:
    void quitar_coordenadas_a_lista(int coord_x, int coord_y);

    // pre:
    // pos:
    void quitar_vida( int orden_edificio );

    // pre:
    // pos:
    void restar_cantidad_construidos();

    // pre:
    // pos:
    void restar_vida( int posicion );




};


#endif // EDIFICIO_JUGADOR_H