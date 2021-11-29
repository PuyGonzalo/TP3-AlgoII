#ifndef OBJETIVOS_H
#define OBJETIVOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "lista.h"
#include "inventario.h"
#include "datos_edificio.h"

#include "armado.h"
#include "bombardero.h"
#include "cansado.h"
#include "comprar_andypolis.h"
#include "constructor.h"
#include "edad_piedra.h"
#include "energetico.h"
#include "extremista.h"
#include "letrado.h"
#include "minero.h"
#include "obelisco.h"

using namespace std;

const int CANT_OBJ_BOMBARDERO = 5;
const int CANT_OBJ_CANSADO = 0;
const int CANT_OBJ_ARMADO = 10;


const string OBJ_OBELISCO = "Objetivo Mas alto que las nubes";
const string OBJ_COMPRAR_ANDYNOPOLIS = " Objetivo Comprar Andynopolis";
const string OBJ_EDAD_PIEDRA = " Objetivo Edad de Piedra";
const string OBJ_BOMBARDERO = " Objetivo Bombardero";
const string OBJ_ENERGETICO = "Objetivo Energetico";
const string OBJ_LETRADO = "Objetivo Letrado";
const string OBJ_MINERO = "Objetivo Minero";
const string OBJ_CANSADO = " Objetivo Cansado";
const string OBJ_CONSTRUCTOR = "Objetivo Constructor";
const string OBJ_ARMADO = "Objetivo Armado";
const string OBJ_EXTREMISTA = "Objetivo Extremista";
const string PROGRESO_OBJ = " El objetivo tienen un progrse de : ";

enum objetivo_t{
    OPC_COMPRAR_ANDYNOPOLIS,
    OPC_EDAD_PIEDRA,
    OPC_BOMBARDERO,
    OPC_ENERGETICO,
    OPC_LETRADO,
    OPC_MINERO,
    OPC_CANSADO,
    OPC_CONSTRUCTOR,
    OPC_ARMADO,
    OPC_EXTREMISTA
};


class Objetivo{
    private:
        string nombre;
        bool cumplido;
        int cant_andycoins_gastados;
        int cant_bombas_compradas;
        int cant_bombas_usadas;
    
    public:
        Objetivo(string nombre_obj, bool realizado, int andycoins, int bombas_compradas , int bombas_usadas );

        Objetivo* sortear_objetivos();
        virtual string obtener_nombre() = 0;
        virtual string obtener_condiciones() = 0;
        virtual bool chequear_cumplimiento(const int &cant_energia, const Inventario & inventario, const Lista<Datos_edificio*> & catalogo) = 0; 
        virtual string obtener_progreso() = 0;
};


#endif