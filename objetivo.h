#ifndef OBJETIVOS_H
#define OBJETIVOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "lista.h"
#include "vector.h"
#include "inventario.h"
#include "edificio_jugador.h"
#include "edificio.h"

using namespace std;

const int CANT_OBJ_BOMBARDERO = 5;
const int CANT_OBJ_CANSADO = 0;
const int CANT_OBJ_ARMADO = 10;


const string OBJ_MAS_ALTO_NUBES = "Objetivo Mas alto que las nubes"; // para que queremos realmente esto?
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
const string PROGRESO_OBJ = " El objetivo tienen un progreso de : ";

enum Objetivo_secundario_t{
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

    protected:
        string nombre;
        bool cumplido;
    
    public:
        Objetivo(string nombre_obj, bool realizado);
        virtual ~Objetivo(){};

        string obtener_nombre();

        virtual string obtener_condiciones() = 0;
        virtual bool chequear_cumplimiento( const int &cant_energia,  const Inventario & inventario,  const Vector<Edificio_jugador*> & mis_edificios) = 0; 
        //virtual string obtener_progreso(  int &cant_energia,   Inventario & inventario,   Vector<Edificio_jugador*> & mis_edificios) = 0;
};


#endif