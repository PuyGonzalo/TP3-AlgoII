#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>
#include "inventario.h"
#include "jugador.h"
#include "errores.h"
#include "herramientas.h"
#include "andypolis.h"
#include "menu_jugador.h"



using namespace std;

const string PATH_ENTRADA_MATERIALES = "Archivos/materiales.txt"; // Cambio el formato de archivos, ojo
const string PATH_ENTRADA_EDIFICIOS = "Archivos/edificios.txt";
const string PATH_ENTRADA_UBICACIONES = "Archivos/ubicaciones.txt";
const string PATH_ENTRADA_MAPA = "Archivos/mapa.txt";
const string PATH_ENTRADA_MATERIALES_NUEVA_PARTIDA = "Archivos/materiales_nueva_partida.txt";
const string PATH_ENTRADA_UBICACIONES_NUEVA_PARTIDA = "Archivos/ubicaciones_nueva_partida.txt";
int main (void){
    if(system(CLR_SCREEN)) return 1;

	// Esto lo hago para que la secuencia de la cantidad de materiales que se genera con cada corrida del programa sea mas aleatoria.
	srand( (unsigned int)time(NULL) );
	
    // Abro archivos de lectura
	ifstream archivo_entrada_ubicaciones(PATH_ENTRADA_UBICACIONES_NUEVA_PARTIDA);
	ifstream archivo_entrada_materiales(PATH_ENTRADA_MATERIALES_NUEVA_PARTIDA);
    ifstream archivo_entrada_edificios(PATH_ENTRADA_EDIFICIOS);
    ifstream archivo_entrada_mapa(PATH_ENTRADA_MAPA);

	// NUEVA_PARTIDA:
	archivo_entrada_ubicaciones.seekg(0, ios::end);
	// Si el archivo esta vacio tellg() me devuelve cero!
	if( !archivo_entrada_ubicaciones.tellg() ){
	
		cout << "Archivo ubicaciones vacio" <<  endl;
		Andypolis nuevo_andypolis(archivo_entrada_edificios,  archivo_entrada_mapa,archivo_entrada_materiales);
		partida_nueva(nuevo_andypolis);
		return 0;
	}
	/*else{
		Andypolis andypolis(archivo_entrada_edificios, archivo_entrada_ubicaciones, archivo_entrada_mapa,archivo_entrada_materiales);
	}*/
		
 	// ########## JUEGO
	 Andypolis andypolis(archivo_entrada_edificios, archivo_entrada_ubicaciones, archivo_entrada_mapa,archivo_entrada_materiales);
	procesar_juego(andypolis);

    // Cierro archivos de lectura
	archivo_entrada_materiales.close(); 
	archivo_entrada_edificios.close();
    archivo_entrada_ubicaciones.close();
    archivo_entrada_mapa.close();


	// Abro los archivos de escritura para guardar el juego
//	ofstream archivo_salida_materiales(PATH_ENTRADA_MATERIALES, ios::trunc);
//  ofstream archivo_salida_ubicaciones(PATH_ENTRADA_UBICACIONES, ios::trunc);

	// Guardo los cambios
//	guardar_cambios(andypolis, archivo_salida_materiales, archivo_salida_ubicaciones);

	// Cierros los archivos de escritura
//	archivo_salida_materiales.close();
//	archivo_salida_ubicaciones.close();

    return 0;
}
