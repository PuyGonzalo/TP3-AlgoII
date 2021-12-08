#ifndef MENU_JUGADOR_H
#define MENU_JUGADOR_H

#include <sstream>
#include <string>
#include <ctime>
#include "errores.h"
#include "formatos.h"
#include "andypolis.h"
#include "utilidades.h"
#include "herramientas.h"
#include "gotoxy.h"


using namespace std;


const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 13;

enum Opciones_menu{
	CONSTRUIR_EDIFICIO_POR_NOMBRE = 1,
	LISTAR_EDIFICIOS_CONSTRUIDOS = 2,
	DEMOLER_EDIFICIO_POR_COORD = 3,
	ATACAR_EDIFICIO_POR_COORD = 4,
	REPARAR_EDIFICIO_POR_COORD = 5,
	COMPRAR_BOMBAS = 6,
	CONSULTAR_COORDENADA = 7,
	MOSTRAR_INVENTARIO = 8,
	MOSTRAR_OBJETIVOS = 9,
	RECOLETAR_RECURSOS_PRODUCIDOS = 10,
	MOVERSE_A_UNA_COORD = 11,
	FINALIZAR_TURNO = 12,
	GUARDAR_SALIR = 13,
};


const string MSJ_MENU_BIENVENIDA_JUGADOR_UNO = R"(
     ___  __   __  _______  _______  ______   _______  ______      ____  
    |   ||  | |  ||       ||   _   ||      | |       ||    _ |    |    | 
    |   ||  | |  ||    ___||  |_|  ||  _    ||   _   ||   | ||     |   | 
    |   ||  |_|  ||   | __ |       || | |   ||  | |  ||   |_||_    |   | 
 ___|   ||       ||   ||  ||       || |_|   ||  |_|  ||    __  |   |   | 
|       ||       ||   |_| ||   _   ||       ||       ||   |  | |   |   | 
|_______||_______||_______||__| |__||______| |_______||___|  |_|   |___|)";

const string MSJ_MENU_BIENVENIDA_JUGADOR_DOS = R"(
     ___  __   __  _______  _______  ______   _______  ______      _______ 
    |   ||  | |  ||       ||   _   ||      | |       ||    _ |    |       |
    |   ||  | |  ||    ___||  |_|  ||  _    ||   _   ||   | ||    |____   |
    |   ||  |_|  ||   | __ |       || | |   ||  | |  ||   |_||_    ____|  |
 ___|   ||       ||   ||  ||       || |_|   ||  |_|  ||    __  |  | ______|
|       ||       ||   |_| ||   _   ||       ||       ||   |  | |  | |_____ 
|_______||_______||_______||__| |__||______| |_______||___|  |_|  |_______|)";


const string MSJ_MENU_OPCION_1 = "1. Construir edificio por nombre";
const string MSJ_MENU_OPCION_2 = "2. Listar mis edificios construidos";
const string MSJ_MENU_OPCION_3 = "3. Demoler un edificio por coordenada";
const string MSJ_MENU_OPCION_4 = "4. Atacar un edificio por coordenada";
const string MSJ_MENU_OPCION_5 = "5. Reparar un edificio por coordenada";
const string MSJ_MENU_OPCION_6 = "6. Comprar bombas";
const string MSJ_MENU_OPCION_7 = "7. Consultar coordenadas";
const string MSJ_MENU_OPCION_8 = "8. Mostrar inventario";
const string MSJ_MENU_OPCION_9 = "9. Mostrar objetivos";
const string MSJ_MENU_OPCION_10 = "10. Recolectar recursos producidos";
const string MSJ_MENU_OPCION_11 = "11. Moverse a una coordenada";
const string MSJ_MENU_OPCION_12 = "12. Finalizar turno";
const string MSJ_MENU_OPCION_13 = "13. Guardar y salir";

const string MSJ_MENU_INGRESO_OPCION = "Elija una opcion";


const string MSJ_INGRESO_EDIFICIO_DEMOLER = "Ingresa el nombre del edificio a demoler:";
const string MSJ_DESPEDIDA = "¡Hasta la proxima!";


//####################################################### FUNCIONES #################################################################

// Como pos general: en caso de tener Estado_t se devuelve OK si la funcion se ejecuto correctamente y un error en caso contrario

// pre: - 
// pos: muestra el menu
void mostrar_menu_jugador(Jugador_t jugador, Andypolis& andypolis);

// pre: -
// pos hace todo el proceso de juego (seguir jugando hasta que el usuario quiera irse e iniciar el aleatorio)
void procesar_juego(Andypolis& andypolis); 

// pre: -
// pos: asigna quien va a ir primero (jugador A) y quien ira segundo (jugador B) en el primer par de turnos
void sortear_jugadores(Jugador_t &jugador_A, Jugador_t &jugador_B);

// pre: -
// pos: valida y procesa la opcion (existe para modularizar mejor)
Estado_t ingreso_menu(int &opcion , Andypolis &andypolis, Jugador_t jugador);

// pre: ingreso_menu() ya valida el puntero nulo
// pos: realiza la opcion del menu que el usuario elija
Estado_t procesar_opcion(int opcion_elegida, Andypolis &andypolis, Jugador_t jugador);

// pre: -
// pos: suma una cantidad "secreta" de un material dependiendo que codigo se ponga
Estado_t menu_secreto(Inventario inventario, string codigo);

// pre: -
// pos: guarda todos los cambios que haya realizado el jugador
void guardar_cambios(Andypolis& andypolis, ofstream& archivo_salida_materiales, ofstream& archivo_salida_ubicaciones);


#endif //MENU_JUGADOR_H
