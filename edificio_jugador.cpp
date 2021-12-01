#include "edificio_jugador.h"


Edificio_jugador::Edificio_jugador(){

    this -> nombre = "";
    this -> identificador = ' ';
    this -> cantidad_construidos = 0;
    this -> vida = 0;
}


// ------------------------------------------------------------------------------------------------------------


Edificio_jugador::Edificio_jugador(string nombre, char identificador, int vida){

    this -> nombre = nombre;
    this -> identificador = identificador;
    this -> cantidad_construidos = 0; // Cuando lo creo no tengo construidos
    this -> vida = vida;
}


// ------------------------------------------------------------------------------------------------------------


Edificio_jugador::~Edificio_jugador(){

    for(int i = 0; i < ubicacion.obtener_cantidad(); ++i)
        delete ubicacion.consulta(i);

}


// ------------------------------------------------------------------------------------------------------------


string Edificio_jugador::obtener_nombre() const{

    return this -> nombre;
}

char Edificio_jugador::obtener_identificador(){

    return this -> identificador;
}


// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::obtener_cantidad_construidos(){

    return this -> cantidad_construidos;
}


// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::obtener_vida(){

    return this -> vida;
}


// ------------------------------------------------------------------------------------------------------------


void Edificio_jugador::agregar_coordenadas_a_lista(int coord_x, int coord_y){

    Coordenadas* nueva_coord = new Coordenadas;

    nueva_coord -> coordenada_x = coord_x;
    nueva_coord -> coordenada_y = coord_y;

    ubicacion.alta(nueva_coord, this -> cantidad_construidos);

    this -> cantidad_construidos++;
}


// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::buscar_coordenadas_en_lista(int coord_x, int coord_y){
    
    int i = 0;
    int posicion = -1;
    bool encontrado = false;

    while( i < ubicacion.obtener_cantidad() && !encontrado){
        
        if(ubicacion.consulta(i) -> coordenada_x == coord_x && ubicacion.consulta(i) -> coordenada_y == coord_y){
            encontrado = true;
            posicion = i;
        }

        ++i;
    }

    return posicion;
}


// ------------------------------------------------------------------------------------------------------------


Estado_t Edificio_jugador::quitar_coordenadas_a_lista(int coord_x, int coord_y){

    Estado_t estado = OK;

    int pos = buscar_coordenadas_en_lista(coord_x, coord_y);

    if(pos != -1){
        ubicacion.baja(pos);
    }
    else{
        estado = ERROR_POSICION_INEXISTENTE;
    }

    return estado;
}


// ------------------------------------------------------------------------------------------------------------
