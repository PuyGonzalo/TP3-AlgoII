#include <iostream>
#include "utilidades.h"



// -------------------------------------------------------------------------------------------


Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador){

    return andypolis.comprar_bombas(jugador);

}


// -------------------------------------------------------------------------------------------


Estado_t construir_edificio_por_nombre(Andypolis &andypolis, Jugador_t jugador){
    string nombre;
    string coord_x, coord_y;
    //Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_INGRESO_EDIFICIO_CONSTRUIR << FIN_DE_FORMATO << endl;
    cout << "> ";
    getline(cin, nombre);
    if(!andypolis.esta_edificio(nombre))
        return ERROR_EDIFICIO_INEXISTENTE;


    cout << endl << TAB << SUBRAYADO << "Ingrese las coordenadas donde quiere construir el edificio:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y);

    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;
     
    return andypolis.construir_edificio(nombre, stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------

/*
Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese la coordenadas del edificio que quiere demoler:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.destruir_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}
*/

// -------------------------------------------------------------------------------------------