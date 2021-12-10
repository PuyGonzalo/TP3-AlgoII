#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "nodo.h"

using namespace std;

template <typename Tipo>
class Pila {

private:
    //Atributos
    Nodo<Tipo>* tope;

public:
    //Metodos

    // pre: -
    // pos: CONSTRUCTOR. Me crea una pila vacia
    Pila();

    // pre: - 
    // pos: DESTRUCTOR de pila
    ~Pila();

    // pre: -
    // pos: Agrega d arriba de la pila
    void alta(Tipo d);

    // pre: -
    // pos: Devuelve el dato que esta arriba
    Tipo consulta();

    // pre: - 
    // pos: Devuelve el dato que esta arriba de la pila como const
    Tipo consulta_const() const; //Tiene sentido esto ? Lo dejo por las dudas

    // pre: -
    // pos: Devuelve el dato que esta arriba y lo saca de la pila
    Tipo baja();

    // pre: -
    // pos: Devuelve True si la pila esta vacio False en caso contrario
    bool vacia();

};


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Pila<Tipo>::Pila(){

    tope = NULL;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Pila<Tipo>::~Pila(){

    while(!vacia()){
        baja();
    }
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
void Pila<Tipo>::alta(Tipo d){

    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(d);
    nuevo_nodo -> cambiar_siguiente(tope);
    tope = nuevo_nodo;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Pila<Tipo>::consulta(){

    return tope -> obtener_dato();    
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Pila<Tipo>::consulta_const() const{

    return tope -> obtener_dato_const();  
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
Tipo Pila<Tipo>::baja(){

    Nodo<Tipo>* aux = tope;
    tope = aux -> obtener_siguiente();
    Tipo d = aux -> obtener_dato();
    delete aux;
    return d;
}


// -----------------------------------------------------------------------------------------


template <typename Tipo>
bool Pila<Tipo>::vacia(){

    return (tope == NULL);
}


// -----------------------------------------------------------------------------------------


#endif // PILA_H