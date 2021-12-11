#include <iostream>
#include "utilidades.h"



// -------------------------------------------------------------------------------------------


Estado_t comprar_bombas(Andypolis &andypolis, Jugador_t jugador){

    if( andypolis.obtener_energia_jugador(jugador) < 5)
        return ERROR_ENERGIA_INSUFICIENTE; 

    return andypolis.comprar_bombas(jugador);

}


// -------------------------------------------------------------------------------------------


Estado_t construir_edificio_por_nombre(Andypolis &andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 15) // deshardc
        return ERROR_ENERGIA_INSUFICIENTE;

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


Estado_t modificar_edificio_por_nombre(Andypolis &andypolis){

    string nombre;
    string madera, metal, piedra;
    Estado_t estado = OK;

    cout << TAB << SUBRAYADO << MSJ_INGRESO_EDIFICIO_MODIFICAR << FIN_DE_FORMATO << endl;
    cout << "> ";
    getline(cin, nombre);
    if(!andypolis.esta_edificio(nombre))
        estado = ERROR_EDIFICIO_INEXISTENTE;

    if(nombre == STR_OBELISCO)
        estado = ERROR_MODIFICAR_OBELISICO;


    cout << endl << TAB << SUBRAYADO << "Ingrese la cantidad de material que quiere modificar del edificio:" << FIN_DE_FORMATO << endl;
    cout << "Cantidad de piedra > "; getline(cin, piedra);
    cout << endl <<  "Cantidad de madera > "; getline(cin, madera);
    cout << endl <<  "Cantidad de madera > "; getline(cin, metal);

    if(!es_un_numero(piedra) || !es_un_numero(madera) || !es_un_numero(metal))
        estado = ERROR_MATERIALES_INVALIDOS;

    if( validar_cantidad_materiales(piedra, madera, metal) != OK )
        estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;    
     
    andypolis.modificar_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal));

    return estado;
}

// -------------------------------------------------------------------------------------------


Estado_t validar_cantidad_materiales(string piedra, string  madera, string metal){

    Estado_t estado = OK;

    if(stoi(piedra) > 50000 || stoi(madera) > 50000|| stoi(metal) > 50000)
        estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;
    
    if(stoi(piedra) < 0 || stoi(madera) < 0|| stoi(metal) < 0)
        estado = ERROR_CANTIDAD_MATERIALES_INVALIDOS;

    return estado;
}

// -------------------------------------------------------------------------------------------


Estado_t demoler_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 15)
        return ERROR_ENERGIA_INSUFICIENTE;

    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese la coordenadas del edificio que quiere demoler:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.destruir_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t atacar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 30) //DESHARCODEAR
        return ERROR_ENERGIA_INSUFICIENTE;


    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese la coordenadas del edificio que quiere atacar:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.atacar_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t reparar_edificio_por_coordenada(Andypolis& andypolis, Jugador_t jugador){

    if(andypolis.obtener_energia_jugador(jugador) < 25)
        return ERROR_ENERGIA_INSUFICIENTE;

    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese la coordenadas del edificio que quiere reparar:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;
    


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    return andypolis.reparar_edificio_de_coord(stoi(coord_x), stoi(coord_y), jugador);
}


// -------------------------------------------------------------------------------------------


Estado_t consultar_coordenada(const Andypolis &andypolis){

    Estado_t estado = OK;
    string coord_x, coord_y;

    cout << TAB << SUBRAYADO << "Ingrese las coordenadas que quiere consultar:" << FIN_DE_FORMATO << endl;
    cout << "Coordenada x > "; getline(cin, coord_x);
    cout << endl << "Coordenada y > "; getline(cin, coord_y); cout << endl;


    if(!es_un_numero(coord_x) || !es_un_numero(coord_y))
        return ERROR_PAR_COORDENADAS_INVALIDAS;


    estado = andypolis.consultar_casillero_de_mapa(stoi(coord_x),stoi(coord_y));

    return estado;

}