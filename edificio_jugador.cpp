#include "edificio_jugador.h"


Edificio_jugador::Edificio_jugador(){

    this -> nombre = "";
    this -> identificador = ' ';
    this -> cantidad_construidos = 0;
}


// ------------------------------------------------------------------------------------------------------------


Edificio_jugador::Edificio_jugador(string nombre, char identificador){

    this -> nombre = nombre;
    this -> identificador = identificador;
    this -> cantidad_construidos = 0; // Cuando lo creo no tengo construidos
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


// ------------------------------------------------------------------------------------------------------------



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



string Edificio_jugador::obtener_vida_edificios_str() const{

    stringstream sstream;

    if(cantidad_construidos != 0){
        for(int i = 0; i < vida.obtener_cantidad() ; ++i){  
            sstream << vida.consulta_const(i) << " ";
        }
    }

    return sstream.str();   

}

// ------------------------------------------------------------------------------------------------------------


int Edificio_jugador::obtener_vida( int posicion ) const{

    return this -> vida.consulta_const(posicion);

}


// ------------------------------------------------------------------------------------------------------------

/*
string Edificio_jugador::obtener_vida_str() const{

    stringstream sstream;

    for( int i=0; i < cantidad_construidos; i++){
        sstream << '(' << ubicaciones.consulta_const(i) -> coordenada_x
            << ',' << " " << ubicaciones.consulta_const(i) -> coordenada_y << ") ";
        }
    }

    return sstream.str();   

}*/


// ------------------------------------------------------------------------------------------------------------


bool Edificio_jugador::puede_repararse( int posicion){

    return (this -> vida.consulta_const( posicion) < 100);
    
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


void Edificio_jugador::agregar_vida(int cantidad){

    this->vida.alta(cantidad, vida.obtener_cantidad());
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


void Edificio_jugador::quitar_vida( int orden_edificio){

    ubicaciones.baja(orden_edificio);
}


// ------------------------------------------------------------------------------------------------------------


void Edificio_jugador::restar_cantidad_construidos(){
    this-> cantidad_construidos--;
}

void Edificio_jugador::restar_vida( int posicion ){

    this -> vida.modificar( vida.consulta(posicion)-50, posicion);
}