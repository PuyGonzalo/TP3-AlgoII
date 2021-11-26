#include <iostream>
#include "andypolis.h"


// ------------------------------------------------------------------------------------------------------------


Andypolis::Andypolis(ifstream& archivo_edif, ifstream& archivo_ubics, ifstream& archivo_mapa, ifstream& archivo_mats)
: mapa(archivo_mapa){

    cargar_ubicaciones(archivo_ubics);

    // INVENTARIO (meter en metodo)
    string linea_leida;
    
    while(getline(archivo_mats, linea_leida)){

        Parser parser(linea_leida);
        Material* material_leido_uno = parser.procesar_entrada_material(JUGADOR_UNO);
        jugador_uno.agregar_material_a_lista(material_leido_uno);
        Material* material_leido_dos = parser.procesar_entrada_material(JUGADOR_DOS);
        jugador_dos.agregar_material_a_lista(material_leido_dos);
        
    }

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_ubicaciones(ifstream& archivo_ubics){

    string linea_leida;
    Estado_t estado = OK;
    Estado_t estado_edificios = OK;
    Estado_t estado_materiales = OK;

    while(getline(archivo_ubics, linea_leida)){
        
        Parser parser(linea_leida);

        if( parser.nombre_elemento_ubicaciones() == "1"){
            jugador_uno.asignar_identificador(JUGADOR_UNO);
            jugador_uno.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_UNO);
            while (getline(archivo_ubics, linea_leida)){
                Parser parser(linea_leida);
                if( parser.nombre_elemento_ubicaciones() == "2"){
                    jugador_dos.asignar_identificador(JUGADOR_DOS);
                    jugador_dos.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
                    mapa.posicionar_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y(),JUGADOR_DOS);
                    while (getline(archivo_ubics, linea_leida)){
                        Parser parser(linea_leida);
                        int coordenada_x = parser.obtener_coordenada_x();
                        int coordenada_y = parser.obtener_coordenada_y();
                        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_DOS), coordenada_x, coordenada_y);
                        // cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y); PARA C/JUG
                    }
                } else{
                    int coordenada_x = parser.obtener_coordenada_x();
                    int coordenada_y = parser.obtener_coordenada_y();
                    estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(JUGADOR_UNO), coordenada_x, coordenada_y);
                    // cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y); PARA C/JUG
                }
            }    
        } else {            
            int coord_x = parser.obtener_coordenada_x();
            int coord_y = parser.obtener_coordenada_y();
            Material* mat = parser.procesar_entrada_ubicaciones_materiales();
            estado = mapa.agregar_material_en_coordenadas(mat, coord_x, coord_y);
        }

        
/*
        if( parser.nombre_elemento_ubicaciones() == "1"){
            jugador_uno.asignar_identificador(JUGADOR_UNO);
            jugador_uno.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            estado_edificios = cargar_edificios_jugador(archivo_ubics, JUGADOR_UNO);    
        } else if( parser.nombre_elemento_ubicaciones() == "2"){
            jugador_dos.asignar_identificador(JUGADOR_DOS);
            jugador_dos.asignar_ubicacion_jugador(parser.obtener_coordenada_x(),parser.obtener_coordenada_y());
            estado_edificios = cargar_edificios_jugador(archivo_ubics, JUGADOR_DOS);
        } else{
            estado_materiales = cargar_materiales_mapa(archivo_ubics);
        }
*/

    }

    if (estado_materiales != OK){
        estado = estado_materiales;
    } else if (estado_edificios != OK){
        estado = estado_edificios;
    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------

Estado_t Andypolis::cargar_materiales_mapa(ifstream& archivo_ubics){

    Estado_t estado = OK;
    string linea_leida;

    while(getline(archivo_ubics, linea_leida)){
        
        Parser parser(linea_leida);
        int coord_x = parser.obtener_coordenada_x();
        int coord_y = parser.obtener_coordenada_y();
        Material* mat = parser.procesar_entrada_ubicaciones_materiales();
        estado = mapa.agregar_material_en_coordenadas(mat, coord_x, coord_y);

    }
    
    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::cargar_edificios_jugador(ifstream& archivo_ubics, Jugador_t jugador){

    Estado_t estado = OK;
    string linea_leida;
    int coordenada_x, coordenada_y;

    while(getline(archivo_ubics, linea_leida)){

        Parser parser(linea_leida);
        coordenada_x = parser.obtener_coordenada_x();
        coordenada_y = parser.obtener_coordenada_y();
        estado = mapa.asignar_edificio_en_coord(parser.procesar_entrada_ubicaciones_edificios(jugador), coordenada_x, coordenada_y);
        // cargar_coordenadas_en_catalogo(parser.nombre_edificio_ubicaciones(), coordenada_x, coordenada_y); PARA C/JUG

    }

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


Estado_t Andypolis::posicionar_jugador(int coord_x, int coord_y, Jugador_t jugador){

    Estado_t estado = OK;

    estado = mapa.posicionar_jugador(coord_x,coord_y,jugador);

    return estado;

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_inventario(Jugador_t jugador){

    if(jugador == JUGADOR_UNO)
        jugador_uno.mostrar_inventario();

    if(jugador == JUGADOR_DOS)
        jugador_dos.mostrar_inventario();
    

}


// ------------------------------------------------------------------------------------------------------------


void Andypolis::mostrar_mapa(){

    mapa.mostrar_mapa();

}