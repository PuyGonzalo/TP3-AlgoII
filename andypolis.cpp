#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats)
: mapa(archivo_mapa){
    
    jugador_uno.asignar_identificador(IDENTIFICADOR_JUGADOR_UNO);
    jugador_uno.asignar_numero_jugador(JUGADOR_UNO);
    jugador_dos.asignar_identificador(IDENTIFICADOR_JUGADOR_DOS);
    jugador_dos.asignar_numero_jugador(JUGADOR_DOS);
    

    // INVENTARIO (meter en metodo)
    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugador_uno.agregar_material_a_lista(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugador_dos.agregar_material_a_lista(material_leido_dos);
        
    }

    // UBICACIONES
/*
    Para esto es mejor primero implementar el mapa. Una vez hecho eso, habria que ir poniendo los materiales en el mapa hasta
    leer un "1", comparar con stoi() contra JUGADOR 1 y ahi llamar tal vez un metodo "cargar_edificios_jugador(Jugador_t jug)"
    y obvio lo mismo para "2" (y agregar las ubicaciones.
    Problema: no podemos llamar al constructor de jugador o inventario como en el TP anterior, vamos a tener que crearlo
    vacio e irlo llenando con setter, me parece una poronga porque medio que Andypolis termina construyendolos en vez de la 
    clase misma pero bueno, es la unica forma que veo si te van dando la info del jugador en 2 archivos distintos y tan
    descorrelacionados.
*/

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_inventario();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_inventario();
    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(){

    mapa.mostrar_mapa();

}