#include <iostream>
#include "objetivo.h"


// ------------------------------------------------------------------------------------------------------------


Objetivo::Objetivo(string nombre_obj, bool realizado){
    this -> nombre = nombre_obj;
    this -> cumplido = realizado;
}


// ------------------------------------------------------------------------------------------------------------


string Objetivo::obtener_nombre(){
    return nombre;
}


// ------------------------------------------------------------------------------------------------------------

/* 
Objetivo* Objetivo::sortear_objetivos(){
  
    int opcion_objetivo = rand() % 10;

    Objetivo* aux = nullptr;

    switch(opcion_objetivo){
        
        case OPC_COMPRAR_ANDYNOPOLIS:
            aux = new Comprar_andypolis(OBJ_COMPRAR_ANDYNOPOLIS, false);
            break;

        case OPC_EDAD_PIEDRA:
            aux = new Edad_piedra(OBJ_EDAD_PIEDRA, false);
            break;
        
        case OPC_BOMBARDERO:
            aux = new Bombardero(OBJ_BOMBARDERO, false);
            break;
        
        case OPC_ENERGETICO:
            aux = new Energetico(OBJ_ENERGETICO, false);
            break;
        
        case OPC_LETRADO:
            aux = new Letrado(OBJ_LETRADO, false);
            break;
        
        case OPC_MINERO:
            aux = new Minero(OBJ_MINERO, false);
            break;
        
        case OPC_CANSADO:
            aux = new Cansado(OBJ_CANSADO, false);
            break;

        case OPC_CONSTRUCTOR:
            aux = new Constructor(OBJ_CONSTRUCTOR, false);
            break;

        case OPC_ARMADO:
            aux = new Armado(OBJ_ARMADO, false);
            break;
    }


    return aux;

}

*/