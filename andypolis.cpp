#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats){
    
    jugador_uno.asignar_identificador('J');
    jugador_uno.asignar_numero_jugador(JUGADOR_UNO);
    jugador_dos.asignar_identificador('U');
    jugador_dos.asignar_numero_jugador(JUGADOR_DOS);
    
    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugador_uno.agregar_material_a_lista(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugador_dos.agregar_material_a_lista(material_leido_dos);
        
    }


}

void Andypolis::mostrar_inventario(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_inventario();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_inventario();
    

}