#include <iostream>
#include "menu_jugador.h"


using namespace std;


// ------------------------------------------------------------------------------------------------------------


void mostrar_menu_jugador(Jugador_t jugador, Andypolis& andypolis){

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

    //andypolis.mostrar_mapa(60,10);


}


// ------------------------------------------------------------------------------------------------------------


void procesar_juego(Andypolis& andypolis){


    int opcion = 0;
    int turno = 0;
	Estado_t estado = OK;

    Jugador_t jugador_A = NADIE , jugador_B = NADIE;
    sortear_jugadores(jugador_A, jugador_B);
    
    while(opcion != GUARDAR_SALIR){
        
        if(!(turno%2))
            andypolis.lluvia_de_recursos();

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){ // agregar que si el jugador tiene 0 se finaliza automatico (molesto para debug)
                mostrar_menu_jugador(jugador_A, andypolis);                // if(energia == 0) opcion = FINALIZAR_TURNO es lo mas logico (asi check objetivos)
                estado = ingreso_menu(opcion, andypolis, jugador_A, turno);
                if(estado != OK && estado != ESTADO_JUGADOR_GANADOR)
                    imprimir_error(estado);
                else if(estado == ESTADO_JUGADOR_GANADOR)
                    opcion = GUARDAR_SALIR; // tal vez haya que comentarla porque puede ser molesto para debug

            }
        }

        if(opcion != GUARDAR_SALIR){
            opcion = 0;
            while(opcion != GUARDAR_SALIR && opcion != FINALIZAR_TURNO){
                mostrar_menu_jugador(jugador_B, andypolis);
                estado = ingreso_menu(opcion, andypolis, jugador_B, turno);
                if(estado != OK && estado != ESTADO_JUGADOR_GANADOR)
                    imprimir_error(estado);
                else if(estado == ESTADO_JUGADOR_GANADOR)
                    opcion = GUARDAR_SALIR; // tal vez haya que comentarla porque puede ser molesto para debug
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


Estado_t ingreso_menu(int &opcion , Andypolis &andypolis, Jugador_t jugador, int &turno){
    
    Estado_t estado = OK;
    string  opcion_elegida;


    cout << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION
    << " (Tiene " << andypolis.obtener_energia_jugador(jugador) << " de energia)" 
    << FIN_DE_FORMATO <<endl;
    cout << '>' << ESPACIO; getline(cin, opcion_elegida); cout << FIN_DE_FORMATO;

    if(!es_un_numero(opcion_elegida))
        return ERROR_ENTRADA_INVALIDA;

    opcion = stoi(opcion_elegida);

    estado = procesar_opcion(opcion,andypolis,jugador,turno);

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t procesar_opcion(int opcion_elegida, Andypolis &andypolis, Jugador_t jugador, int &turno){

    Estado_t estado = OK;
    string str_edificio;
    string codigo_ingresado;


    switch (opcion_elegida) {

        case CONSTRUIR_EDIFICIO_POR_NOMBRE:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(16,1);
            estado = construir_edificio_por_nombre(andypolis, jugador);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_construidos(jugador);
            break;

        case DEMOLER_EDIFICIO_POR_COORD: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(16,1);
            estado = demoler_edificio_por_coordenada(andypolis, jugador);
            break;

        case ATACAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(16,1);
            estado = atacar_edificio_por_coordenada(andypolis, jugador);
            break;

        case REPARAR_EDIFICIO_POR_COORD:
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(16,1);
            estado = reparar_edificio_por_coordenada(andypolis, jugador);
            break;
        
        case COMPRAR_BOMBAS: 
            if(system(CLR_SCREEN));
            estado = comprar_bombas(andypolis, jugador);
            break;

        case CONSULTAR_COORDENADA: 
            if(system(CLR_SCREEN));
            estado = consultar_coordenada(andypolis);
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
            if(andypolis.gano_el_jugador(jugador)){
                mostrar_pantalla_final(jugador);
                return ESTADO_JUGADOR_GANADOR;
            }
            andypolis.agregar_energia_jugador(jugador, 20); // HARDCODEADOOO
            ++turno;
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


// ------------------------------------------------------------------------------------------------------------



void mostrar_pantalla_final(Jugador_t jugador){


    cout << NEGRITA << TAB << MSJ_FELICITACIONES_FINAL << FIN_DE_FORMATO << endl;
    if(jugador == JUGADOR_UNO)
        cout << NEGRITA << TAB << TAB << MSJ_MENU_BIENVENIDA_JUGADOR_UNO << FIN_DE_FORMATO << endl;
    else if(jugador == JUGADOR_DOS)
        cout << NEGRITA << TAB << TAB << MSJ_MENU_BIENVENIDA_JUGADOR_DOS << ARTE_PANTALLA_FINAL << FIN_DE_FORMATO << endl;
    
    cout << endl << endl;

}



// ------------------------------------------------------------------------------------------------------------


void guardar_cambios(Andypolis& andypolis, ofstream& archivo_salida_materiales, ofstream& archivo_salida_ubicaciones){

    cout << TAB << TAB << "¡Muchas gracias por jugar! Esperamos que lo hayan disfrutado ♥" << endl << endl
    << TAB << TAB << TAB << TAB << "# Ivan Lisman" << endl
    << TAB << TAB << TAB << TAB << "# El magnífico Ivan Lisman" << endl
    << TAB << TAB << TAB << TAB << "# Lazurro" << endl;

}

