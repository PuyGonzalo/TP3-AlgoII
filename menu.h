#ifndef MENU_H
#define MENUH

#include <iostream>
#include <string>
#include "manejo_archivos.h"


using namespace std;

class Menu{

private:

    // Atributos
    string ingreso_usuario;
    bool partida_nueva; // Aca esta bien?
    bool jugador_ganador;
    int cantidad_de_turnos;

public:

    // Metodos

    // pre: -
    // pos: Constructor por default
    Menu();

    // pre: -
    // pos: Destructor
    ~Menu(){};



};


#endif // MENU_H