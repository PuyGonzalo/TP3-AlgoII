#include "datos_edificio.h"


Datos_edificio::Datos_edificio(){

    this -> nombre = " ";
    this -> costo_piedra = 0;
    this -> costo_madera = 0;
    this -> costo_metal = 0;
    this -> maximos_permitidos = 0;
}


// ------------------------------------------------------------------------------------------------------------


Datos_edificio::Datos_edificio(string nombre, double costo_piedra, double costo_madera, double costo_metal, int maximos_permitidos){

    this -> nombre = nombre;
    this -> costo_piedra = costo_piedra;
    this -> costo_madera = costo_madera;
    this -> costo_metal = costo_metal;
    this -> maximos_permitidos = maximos_permitidos;
}


// ------------------------------------------------------------------------------------------------------------


string Datos_edificio::obtener_nombre_edificio(){

    return this -> nombre;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_piedra(){

    return this -> costo_piedra;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_madera(){

    return this -> costo_madera;
}


// ------------------------------------------------------------------------------------------------------------


double Datos_edificio::obtener_costo_metal(){

    return this -> costo_metal;
}


// ------------------------------------------------------------------------------------------------------------


int Datos_edificio::obtener_maximos_permitidos(){

    return this -> maximos_permitidos;
}