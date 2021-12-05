#include <iostream>
#include "menu_jugador.h"


using namespace std;


// ------------------------------------------------------------------------------------------------------------


void mostrar_menu_jugador(Jugador_t jugador){
    cout << endl;

    string FONDO = "";

    if(jugador == JUGADOR_UNO){
        cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_JUGADOR_UNO << FIN_DE_FORMATO <<endl;
        FONDO = FONDO_COLOR_ROSA;
    }
    else if(jugador == JUGADOR_DOS){
        cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_JUGADOR_DOS << FIN_DE_FORMATO <<endl;
        FONDO = FONDO_COLOR_PURPURA_OSCURO;
    }

    cout << TAB << "╔════════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_1 << string(6, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_2 << string(3, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_3 << string(1, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_4 << string(2, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_5 << string(1, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_6 << string(21, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_7 << string(14, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_8 << string(17, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_9 << string(18, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_10 << string(4, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_11 << string(10, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_12 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_OPCION_13 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "╚════════════════════════════════════════╝" << endl;
}


// ------------------------------------------------------------------------------------------------------------


void procesar_juego(Andypolis& andypolis){

    // Esto lo hago para que la secuencia de la cantidad de materiales que se genera con cada corrida del programa sea mas aleatoria.
	srand( (unsigned int)time(NULL) );

    int opcion = 0;
	Estado_t estado = OK;

    Jugador_t jugador_A = NADIE , jugador_B = NADIE;
    sortear_jugadores(jugador_A, jugador_B);
    
    while(opcion != GUARDAR_SALIR){

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){
                mostrar_menu_jugador(jugador_A);
                estado = ingreso_menu(opcion, andypolis, jugador_A);
                if(estado != OK)
                    imprimir_error(estado);
            }
        }

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){
                mostrar_menu_jugador(jugador_B);
                estado = ingreso_menu(opcion, andypolis, jugador_B);
                if(estado != OK)
                    imprimir_error(estado);
            }      
        }

    }

}


// ------------------------------------------------------------------------------------------------------------


void sortear_jugadores(Jugador_t &jugador_A, Jugador_t &jugador_B){

    int primero = rand()%100; // entre 1 y 2 es muy malo el rand()

    if(primero < 50){
        jugador_A = JUGADOR_UNO;
        jugador_B = JUGADOR_DOS;
    }
    if(primero >= 50){
        jugador_A = JUGADOR_DOS;
        jugador_B = JUGADOR_UNO;
    }


}


// ------------------------------------------------------------------------------------------------------------


Estado_t ingreso_menu(int &opcion , Andypolis &andypolis, Jugador_t jugador){
    
    Estado_t estado = OK;
    string  opcion_elegida;


    cout << TAB << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION << FIN_DE_FORMATO <<endl;
    cout << '>' << ESPACIO; getline(cin, opcion_elegida); cout << FIN_DE_FORMATO;

    if(!es_un_numero(opcion_elegida))
        return ERROR_ENTRADA_INVALIDA;

    opcion = stoi(opcion_elegida);

    estado = procesar_opcion(opcion,andypolis,jugador);

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t procesar_opcion(int opcion_elegida, Andypolis &andypolis, Jugador_t jugador){

    Estado_t estado = OK;
    string str_edificio;
    string codigo_ingresado;


    switch (opcion_elegida) {

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa();
            estado = construir_edificio_por_nombre(andypolis, jugador);
            andypolis.mostrar_mapa();
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_construidos(jugador);
            break;

        case DEMOLER_EDIFICIO_POR_COORD: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa();
            estado = demoler_edificio_por_coordenada(andypolis, jugador);
            andypolis.mostrar_mapa();
            break;

        case ATACAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            //estado = demoler_edificio_por_coordenada(andypolis);
            break;

        case REPARAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            //andypolis.mostrar_andypolis();
            break;
        
        case COMPRAR_BOMBAS: 
            if(system(CLR_SCREEN));
            estado = comprar_bombas(andypolis, jugador);
            break;

        case CONSULTAR_COORDENADA: 
            if(system(CLR_SCREEN));
            //estado = comprar_bombas(andypolis, jugador);
            break;
        
        case MOSTRAR_INVENTARIO:
            if(system(CLR_SCREEN));
            andypolis.mostrar_inventario(jugador);
            break;

        case MOSTRAR_OBJETIVOS:
            if(system(CLR_SCREEN));
            andypolis.mostrar_objetivos(jugador);
            break;

        case RECOLETAR_RECURSOS_PRODUCIDOS:
            if(system(CLR_SCREEN));
            //estado = lluvia_de_recursos(andypolis);
            break;

        case MOVERSE_A_UNA_COORD:
            if(system(CLR_SCREEN));
            //estado = lluvia_de_recursos(andypolis);
            break;

        case FINALIZAR_TURNO:
            if(system(CLR_SCREEN));
            //estado = lluvia_de_recursos(andypolis);
            break;

        case GUARDAR_SALIR:
            if(system(CLR_SCREEN));
            cout << endl << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            break;

        default: 
            return ERROR_NUMERO_OPCION_INVALIDA;
    }

    return estado;
}