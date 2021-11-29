#include <iostream>
#include "vertice.h"


// ------------------------------------------------------------------------------------------------------------

Vertice::Vertice(int indice, int pos_x, int pos_y){

    this -> indice = indice;
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;

}

// ------------------------------------------------------------------------------------------------------------

Vertice::Vertice(){

    this -> indice = -1;
    this -> pos_x = -1;
    this -> pos_y = -1;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_indice(){

    return this -> indice;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_posx(){

    return this -> pos_x;

}


// ------------------------------------------------------------------------------------------------------------


int Vertice::obtener_posy(){
    
    return this -> pos_y;

}

// ------------------------------------------------------------------------------------------------------------


Lista<int> Vertice::obtener_lista_conexiones(){

    return this -> lista_conexiones;

}


// ------------------------------------------------------------------------------------------------------------


Lista<int> Vertice::obtener_lista_pesos(){

    return this -> lista_pesos;

}


// ------------------------------------------------------------------------------------------------------------


void Vertice::conectar_vertice(int indice, int peso){

    int posicion_en_lista_nueva_conexion = this -> lista_conexiones.obtener_cantidad(); // ME LO EVITO USANDO PILA/COLA EN VEZ DE LISTA... 
    this -> lista_conexiones.alta(indice, posicion_en_lista_nueva_conexion);
    
    int posicion_en_lista_nuevo_peso = this -> lista_pesos.obtener_cantidad();
    this -> lista_conexiones.alta(peso, posicion_en_lista_nuevo_peso);

}