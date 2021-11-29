#include <iostream>
#include "grafo.h"


// ------------------------------------------------------------------------------------------------------------


Grafo::Grafo(const Mapa &mapa, Jugador_t jugador){

    this -> jugador = jugador;
    this -> cantidad_filas = mapa.obtener_filas();
    this -> cantidad_columnas = mapa.obtener_columnas();
    this -> cantidad_vertices = cantidad_filas*cantidad_columnas;

    // Creo el grafo (vertices "al aire")
    grafo = new Vertice**[cantidad_filas];
    for(int i = 0; i < cantidad_filas ; ++i){
        grafo[i] = new Vertice*[cantidad_columnas];
    }

    int k = 0;
    for(int i = 0 ; i < cantidad_filas; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            grafo[i][j] = new Vertice(k,i,j);
            ++k;
        }
    }

    inicializar_matriz_adyacencia();

    conectar_esquinas(mapa);
    conectar_orillas(mapa);
    conectar_centros(mapa);

    cargar_matriz_adyacencia();

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::inicializar_matriz_adyacencia(){

    matriz_adyacencia = new int*[cantidad_vertices];
    for(int i = 0 ; i < cantidad_vertices ; ++i)
        matriz_adyacencia[i] = new int[cantidad_vertices];

    for(int i = 0 ; i < cantidad_vertices ; ++i){
        for(int j = 0 ; j < cantidad_vertices ; ++j){
            if(i == j)
                matriz_adyacencia[i][j] = 0;
            else
                matriz_adyacencia[i][j] = INFINITO;   
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::cargar_matriz_adyacencia(){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            for(int k = 0 ; k < grafo[i][j] -> obtener_lista_conexiones().obtener_cantidad() ; ++k){
                int indice_vertice_origen = grafo[i][j] -> obtener_indice();
                int indice_vertice_destino = grafo[i][j] -> obtener_lista_conexiones().consulta(k);
                matriz_adyacencia[indice_vertice_origen][indice_vertice_destino] = grafo[i][j] -> obtener_lista_pesos().consulta(k);
            }
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::conectar_esquinas(const Mapa &mapa){

    // aaaaaaaaaaaaa que feo
    int indices[4] = {
        grafo[0][0] -> obtener_indice(),
        grafo[0][cantidad_columnas-1] -> obtener_indice(),
        grafo[cantidad_filas-1][0] -> obtener_indice(),
        grafo[cantidad_filas-1][cantidad_columnas-1] -> obtener_indice()
    };

    int pesos[4] = {
        mapa.obtener_peso_casillero(0,0,jugador),
        mapa.obtener_peso_casillero(0,cantidad_columnas-1,jugador),
        mapa.obtener_peso_casillero(cantidad_filas-1,0,jugador),
        mapa.obtener_peso_casillero(cantidad_filas-1,cantidad_columnas-1,jugador)
    };

//    int indice = grafo[0][0] -> obtener_indice();
//    int peso = mapa.obtener_peso_casillero(0,0,jugador);
    grafo[0][0]->conectar_vertice(indices[0],pesos[0]);

//    int indice = grafo[0][cantidad_columnas-1] -> obtener_indice();
//    int peso = mapa.obtener_peso_casillero(0,cantidad_columnas-1,jugador);
    grafo[0][cantidad_columnas-1]->conectar_vertice(indices[1],pesos[1]);

//    int indice = grafo[cantidad_filas-1][0] -> obtener_indice();
//    int peso = mapa.obtener_peso_casillero(cantidad_filas-1,0,jugador);
    grafo[cantidad_filas-1][0]->conectar_vertice(indices[2],pesos[2]);

//    int indice = grafo[cantidad_filas-1][cantidad_columnas-1] -> obtener_indice();
//    int peso = mapa.obtener_peso_casillero(cantidad_filas-1,cantidad_columnas-1,jugador);
    grafo[cantidad_filas-1][cantidad_columnas-1]->conectar_vertice(indices[3],pesos[3]);

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::conectar_orillas(const Mapa &mapa){

    // un metodo para c/u? y que el metodo sea conectar_vertice(indice,peso,indice,peso,indice,peso) o algo asi?

    // orilla de arriba
    for(int j = 1 ; j < cantidad_columnas-1 ; ++j){
        int indice_izq = grafo[0][j-1] -> obtener_indice();
        int peso_izq = mapa.obtener_peso_casillero(0,j-1,jugador);
        grafo[0][j] -> conectar_vertice(indice_izq, peso_izq);

        int indice_der = grafo[0][j+1] -> obtener_indice();
        int peso_der = mapa.obtener_peso_casillero(0,j+1,jugador);
        grafo[0][j] -> conectar_vertice(indice_der, peso_der);

        int indice_abajo = grafo[1][j] -> obtener_indice();
        int peso_abajo = mapa.obtener_peso_casillero(0,j,jugador);
        grafo[0][j] -> conectar_vertice(indice_abajo, peso_abajo);
    }

    // orilla de abajo
    for(int j = 1 ; j < cantidad_columnas-1 ; ++j){

        int indice_arriba = grafo[cantidad_filas-2][j] -> obtener_indice();
        int peso_arriba = mapa.obtener_peso_casillero(cantidad_filas-2,j,jugador);
        grafo[cantidad_filas-1][j] -> conectar_vertice(indice_arriba, peso_arriba);

        int indice_izq = grafo[cantidad_filas-1][j-1] -> obtener_indice();
        int peso_izq = mapa.obtener_peso_casillero(cantidad_filas-1,j-1,jugador);
        grafo[cantidad_filas-1][j] -> conectar_vertice(indice_izq, peso_izq);

        int indice_der = grafo[cantidad_filas-1][j+1] -> obtener_indice();
        int peso_der = mapa.obtener_peso_casillero(cantidad_filas-1,j+1,jugador);
        grafo[cantidad_filas-1][j] -> conectar_vertice(indice_der, peso_der);
    }

    // orilla del izquierda
    for(int i = 1 ; i < cantidad_columnas-1 ; ++i){
        int indice_arriba = grafo[i-1][0] -> obtener_indice();
        int peso_arriba = mapa.obtener_peso_casillero(i-1,0,jugador);
        grafo[i][0] -> conectar_vertice(indice_arriba, peso_arriba);

        int indice_der = grafo[i][1] -> obtener_indice();
        int peso_der = mapa.obtener_peso_casillero(i,1,jugador);
        grafo[i][0] -> conectar_vertice(indice_der, peso_der);

        int indice_abajo = grafo[i+1][0] -> obtener_indice();
        int peso_abajo = mapa.obtener_peso_casillero(i+1,0,jugador);
        grafo[i][0] -> conectar_vertice(indice_abajo, peso_abajo);

    }

    // orilla de la derecha
    for(int i = 1 ; i < cantidad_columnas-1 ; ++i){
        int indice_arriba = grafo[i-1][cantidad_columnas-1] -> obtener_indice();
        int peso_arriba = mapa.obtener_peso_casillero(i-1,cantidad_columnas-1,jugador);
        grafo[i][cantidad_columnas-1] -> conectar_vertice(indice_arriba,peso_arriba);

        int indice_izq = grafo[i][cantidad_columnas-2]-> obtener_indice();
        int peso_izq = mapa.obtener_peso_casillero(i,cantidad_columnas-2,jugador);
        grafo[i][cantidad_columnas-1] -> conectar_vertice(indice_izq,peso_izq);

        int indice_abajo = grafo[i+1][cantidad_columnas-1] -> obtener_indice();
        int peso_abajo = mapa.obtener_peso_casillero(i+1,cantidad_columnas-1,jugador);
        grafo[i][cantidad_columnas-1] -> conectar_vertice(indice_abajo,peso_abajo);

    }


}


// ------------------------------------------------------------------------------------------------------------


void Grafo::conectar_centros(const Mapa &mapa){

    for(int i = 1 ; i < cantidad_filas-1 ; ++i){
        for(int j = 1 ; j < cantidad_columnas-1 ; ++j){
            int indice_arriba = grafo[i-1][j] -> obtener_indice();
            int peso_arriba = mapa.obtener_peso_casillero(i-1,j,jugador);
            grafo[i][j] -> conectar_vertice(indice_arriba,peso_arriba);

            int indice_izq = grafo[i][j-1] -> obtener_indice();
            int peso_izq = mapa.obtener_peso_casillero(i,j-1,jugador);
            grafo[i][j] -> conectar_vertice(indice_izq,peso_izq);

            int indice_der = grafo[i][j+1] -> obtener_indice();
            int peso_der = mapa.obtener_peso_casillero(i,j+1,jugador);
            grafo[i][j] -> conectar_vertice(indice_der,peso_der);

            int indice_abajo = grafo[i+1][j] -> obtener_indice();
            int peso_abajo = mapa.obtener_peso_casillero(i+1,j,jugador);
            grafo[i][j] -> conectar_vertice(indice_abajo,peso_abajo);
        }
    }

}


// -----------------------------------DEBUUGEEOO----------------------------------------------------------------------


void Grafo::imprimir_matriz_ady(){

    for(int i = 0 ; i < cantidad_vertices ; ++i){
        for(int j = 0 ; j < cantidad_vertices ; ++j){
            if(matriz_adyacencia[i][j] == INFINITO)
                cout << "Inf" << '\t';
            else
                cout << matriz_adyacencia[i][j] << '\t';
        }
        cout << endl;
    }


}