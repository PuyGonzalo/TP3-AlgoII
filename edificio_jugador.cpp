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

    for(int i = 0; i < ubicaciones.obtener_cantidad(); ++i)
        delete ubicaciones.consulta(i);

}


// ------------------------------------------------------------------------------------------------------------


string Edificio_jugador::obtener_nombre() const{

    return this -> nombre;
}

char Edificio_jugador::obtener_identificador(){

    return this -> identificador;
}


// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::obtener_cantidad_construidos() const{

    return this -> cantidad_construidos;
}


string Edificio_jugador::obtener_ubicaciones_construidas_str() const{

    stringstream sstream;

    if(cantidad_construidos != 0){
        for(int i = 0; i < ubicaciones.obtener_cantidad() ; ++i){  
            sstream << '(' << ubicaciones.consulta_const(i) -> coordenada_x
            << ',' << " " << ubicaciones.consulta_const(i) -> coordenada_y << ") ";
        }
    }

    return sstream.str();   

}

// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::obtener_vida() const{

    return this -> vida;

}


// ------------------------------------------------------------------------------------------------------------


bool Edificio_jugador::necesita_reparacion(){

    return (this -> vida < 100); // ESTO ESTA MAL.. LOS DE 50 NO ES QUE NECESITEN REPARACION POR ESTAR <100...
    
}


// ------------------------------------------------------------------------------------------------------------


void Edificio_jugador::agregar_coordenadas_a_lista(int coord_x, int coord_y){

    Coordenadas* nueva_coord = new Coordenadas;

    nueva_coord -> coordenada_x = coord_x;
    nueva_coord -> coordenada_y = coord_y;

    ubicaciones.alta(nueva_coord, this -> cantidad_construidos);

    this -> cantidad_construidos++;
}


// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::buscar_coordenadas_en_lista(int coord_x, int coord_y){
    
    int i = 0;
    int posicion = -1;
    bool encontrado = false;

    while( i < ubicaciones.obtener_cantidad() && !encontrado){
        
        if(ubicaciones.consulta(i) -> coordenada_x == coord_x && ubicaciones.consulta(i) -> coordenada_y == coord_y){
            encontrado = true;
            posicion = i;
        }

        ++i;
    }

    return posicion;
}


// ------------------------------------------------------------------------------------------------------------


void Edificio_jugador::quitar_coordenadas_a_lista(int coord_x, int coord_y){
    /*
    Estado_t estado = OK;

    int pos = buscar_coordenadas_en_lista(coord_x, coord_y);

    if(pos != -1){
        ubicaciones.baja(pos);
    }
    else{
        estado = ERROR_POSICION_INEXISTENTE;
    }

    return estado;
    */

   int pos = buscar_coordenadas_en_lista(coord_x, coord_y);

    ubicaciones.baja(pos);
}


// ------------------------------------------------------------------------------------------------------------


void Edificio_jugador::restar_cantidad_construidos(){
    this-> cantidad_construidos--;
}