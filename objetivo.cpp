#include "objetivo.h"

Objetivo::Objetivo(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas){
    nombre = nombre_obj;
    cumplido = realizado;
    cant_andycoins_gastados = andycoins;
    cant_bombas_compradas = bombas_compradas;
    cant_bombas_usadas = bombas_usadas;
}

Objetivo* Objetivo::sortear_objetivos(){
    
    int opcion_objetivo = rand() % 10;

    Objetivo** aux = nullptr;

    switch(opcion_objetivo){
        
        case OPC_COMPRAR_ANDYNOPOLIS:
            *aux = new Comprar_andypolis(OBJ_COMPRAR_ANDYNOPOLIS, false, 0, 0, 0);
            break;

        case OPC_EDAD_PIEDRA:
            *aux = new Edad_piedra(OBJ_EDAD_PIEDRA, false, 0, 0, 0);
            break;
        
        case OPC_BOMBARDERO:
            *aux = new Bombardero(OBJ_BOMBARDERO, false, 0, 0, 0);
            break;
        
        case OPC_ENERGETICO:
            aux = new Energetico(OBJ_ENERGETICO, false, 0, 0, 0);
            break;
        
        case OPC_LETRADO:
            aux = new Letrado(OBJ_LETRADO, false, 0, 0, 0);
            break;
        
        case OPC_MINERO:
            aux = new Minero(OBJ_MINERO, false, 0, 0, 0);
            break;
        
        case OPC_CANSADO:
            aux = new Cansado(OBJ_CANSADO, false, 0, 0, 0);
            break;

        case OPC_CONSTRUCTOR:
            aux = new Constructor(OBJ_CONSTRUCTOR, false, 0, 0, 0);
            break;

        case OPC_ARMADO:
            aux = new Armado(OBJ_ARMADO, false, 0, 0, 0);
            break;
    }

    return *aux;
}