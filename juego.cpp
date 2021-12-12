#include <iostream>
#include "juego.h"


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


void mostrar_menu_partida_nueva(){

    string FONDO = "";
    
    cout << TAB << NEGRITA << MSJ_MENU_BIENVENIDA_PARTIDA_NUEVA << FIN_DE_FORMATO <<endl;
    FONDO = FONDO_COLOR_ANARANJADO;

    cout << TAB << "╔════════════════════════════════════════╗" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_1 << string(6, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_2 << string(10, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_3 << string(23, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_4 << string(19, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "║ " << FONDO << NEGRITA  << MSJ_MENU_PARTIDA_NUEVA_OPCION_5 << string(20, ' ') << FIN_DE_FORMATO << " ║" << endl;
    cout << TAB << "╚════════════════════════════════════════╝" << endl;

    //andypolis.mostrar_mapa(60,10);


}

// ------------------------------------------------------------------------------------------------------------


void partida_nueva(Andypolis& andypolis){
    int opcion = 0;
   	Estado_t estado = OK;
    
    while(opcion != GUARDAR_SALIR_PARTIDA_NUEVA && opcion != COMENZAR_PARTIDA_PARTIDA_NUEVA){
        
        if(opcion != GUARDAR_SALIR_PARTIDA_NUEVA && opcion != COMENZAR_PARTIDA_PARTIDA_NUEVA){
            mostrar_menu_partida_nueva();
            estado = ingreso_menu_partida_nueva(opcion, andypolis);
            if(estado != OK)
                imprimir_error(estado);
        }
    }

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


Estado_t ingreso_menu_partida_nueva(int &opcion , Andypolis &andypolis){
    
    Estado_t estado = OK;
    string  opcion_elegida;


    cout << TAB << SUBRAYADO << MSJ_MENU_INGRESO_OPCION<< FIN_DE_FORMATO <<endl;
    cout << '>' << ESPACIO; getline(cin, opcion_elegida); cout << FIN_DE_FORMATO;

    if(!es_un_numero(opcion_elegida))
        return ERROR_ENTRADA_INVALIDA;

    opcion = stoi(opcion_elegida);

    estado = procesar_opcion_partida_nueva(opcion,andypolis);

    return estado;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t procesar_opcion_partida_nueva(int opcion_elegida, Andypolis &andypolis){

    Estado_t estado = OK;
    //string str_edificio;
    //string codigo_ingresado;


    switch (opcion_elegida) {

        case MODIFICAR_EDIFICIO_POR_NOMBRE_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            estado = modificar_edificio_por_nombre(andypolis);
            break;

        case LISTAR_TODOS_LOS_EDIFICIOS_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            andypolis.listar_edificios_diccionario();
            break;

        case MOSTRAR_MAPA_PARTIDA_NUEVA: 
            if(system(CLR_SCREEN));
            andypolis.mostrar_mapa(16,1);
            break;

        case COMENZAR_PARTIDA_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            estado = consultar_ubicacion_jugadroes(andypolis);
            cout << endl << TAB << NEGRITA << FONDO_COLOR_VERDE << MSJ_PARTIDA_NUEVA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            procesar_juego(andypolis);
            break;

        case GUARDAR_SALIR_PARTIDA_NUEVA:
            if(system(CLR_SCREEN));
            //guargar_cambios_partida_nueva();
            cout << endl << TAB << NEGRITA << FONDO_COLOR_AZUL << MSJ_DESPEDIDA << FIN_DE_FORMATO <<endl;
            cout << endl << endl;
            break;

        default: 
            return ERROR_NUMERO_OPCION_INVALIDA;
    }

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
            andypolis.recolectar_recursos_jugador(jugador);
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
            andypolis.depositar_recursos_jugador(jugador);
            andypolis.agregar_energia_jugador(jugador, 20); // HARDCODEADOOO
            ++turno;
            break;

        case GUARDAR_SALIR:
            if(system(CLR_SCREEN));
            //guardar_cambios();
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


void guardar_cambios(Andypolis& andypolis, ofstream& archivo_salida_materiales, ofstream& archivo_salida_ubicaciones, ofstream& archivo_salida_edificios){

    cout << TAB << TAB << "¡Muchas gracias por jugar! Esperamos que lo hayan disfrutado ♥" << endl << endl
    << TAB << TAB << TAB << TAB << "# Ivan Lisman" << endl
    << TAB << TAB << TAB << TAB << "# El magnífico Ivan Lisman" << endl
    << TAB << TAB << TAB << TAB << "# Lazurro" << endl;

    	// Abro los archivos de escritura para guardar el juego
//	fstream archivo_materiales(PATH_ENTRADA_MATERIALES, ios::out | ios::trunc);
//  fstream archivo_ubicaciones(PATH_ENTRADA_UBICACIONES, ios::out | ios::trunc);

	// Guardo los cambios
//	guardar_cambios(andypolis, archivo_salida_materiales, archivo_salida_ubicaciones);

	// Cierros los archivos de escritura
//	archivo_salida_materiales.close();
//	archivo_salida_ubicaciones.close();

}



void inicializar_juego(){

    // Esto lo hago para que la secuencia de la cantidad de materiales que se genera con cada corrida del programa sea mas aleatoria.
	srand( (unsigned int)time(NULL) );

    // Abro archivos de lectura
	fstream archivo_ubicaciones(PATH_ENTRADA_UBICACIONES, ios::in);
	fstream archivo_materiales(PATH_ENTRADA_MATERIALES, ios::in);
    fstream archivo_edificios(PATH_ENTRADA_EDIFICIOS, ios::in);
    fstream archivo_mapa(PATH_ENTRADA_MAPA, ios::in);

	// NUEVA_PARTIDA:
    if( !archivo_ubicaciones.is_open() ){

        cout << "hola" << endl;
        fstream archivo_ubicaciones;
        crear_archivo_vacio(PATH_ENTRADA_UBICACIONES_NUEVA_PARTIDA, archivo_ubicaciones);

    }
    
	if( archivo_esta_vacio(archivo_ubicaciones) ){
        
		cout << "Archivo ubicaciones vacio" <<  endl; // Esto no deberia decirlo centrado y con algun color ? Tipo advertencia ? O ni siquiera decirlo...
		Andypolis andypolis(archivo_edificios, archivo_ubicaciones, archivo_mapa,archivo_materiales,true);
		partida_nueva(andypolis);
	}
	else{
        cout << "chau" << endl;
		Andypolis andypolis(archivo_edificios, archivo_ubicaciones, archivo_mapa,archivo_materiales,false);
		procesar_juego(andypolis);
	}

    // Cierro archivos de lectura 
    // Estos hay que cerrarlos ANTES porq la funcion que guarda los cambios necesita abrirlos como de escritura
    // Sino, podemos hacer una funcion aparte que se llame, abrir archivo de escritura y que pregunta si archivo este abierto (archivo.is_open())
    // En caso de estarlo lo cierra y lo abre nuevamente como de escritura.
    // Si vamos por esa opcion, esto quedaria pero estaria cerrando los archivos de escritura xD (no es mala ehhh)
	archivo_materiales.close(); 
	archivo_edificios.close();
    archivo_ubicaciones.close();
    archivo_mapa.close();
}