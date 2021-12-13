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

    // Pesos en el grafo
    inicializar_matriz_adyacencia();

    conectar_esquinas(mapa);
    conectar_orillas(mapa);
    conectar_centros(mapa);
    
    cargar_matriz_adyacencia();

    // Para camino minimo
    inicializar_matriz_distancias();
    inicializar_matriz_recorridos();

}


// ------------------------------------------------------------------------------------------------------------


Grafo::~Grafo(){

    for(int i = 0; i < cantidad_vertices ; ++i)
        delete [] matriz_adyacencia[i];
    delete [] matriz_adyacencia; // si quiero poner a nullptr tengo que ir 1 por una, no?

    for(int i = 0; i < cantidad_vertices ; ++i)
        delete [] matriz_distancias[i];
    delete [] matriz_distancias; // si quiero poner a nullptr tengo que ir 1 por una, no?

    for(int i = 0; i < cantidad_vertices ; ++i)
        delete [] matriz_recorridos[i];
    delete [] matriz_recorridos; // si quiero poner a nullptr tengo que ir 1 por una, no?

    for(int i = 0; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            delete grafo[i][j]; // tengo que ir 1 por 1 porque son estructuras complejas
            grafo[i][j] = nullptr;
        }
        delete [] grafo[i];
        grafo[i] = nullptr;
    }

    delete [] grafo;
    grafo = nullptr;

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


void Grafo::inicializar_matriz_distancias(){

    matriz_distancias = new int*[cantidad_vertices];
    for(int i = 0 ; i < cantidad_vertices ; ++i)
        matriz_distancias[i] = new int[cantidad_vertices];

    for(int i = 0 ; i < cantidad_vertices ; ++i){
        for(int j = 0 ; j < cantidad_vertices ; ++j){
                matriz_distancias[i][j] = matriz_adyacencia[i][j];
        }
    }

}



// ------------------------------------------------------------------------------------------------------------


void Grafo::inicializar_matriz_recorridos(){

    matriz_recorridos = new int*[cantidad_vertices];
    for(int i = 0 ; i < cantidad_vertices ; ++i)
        matriz_recorridos[i] = new int[cantidad_vertices];


    for(int i = 0 ; i < cantidad_vertices ; ++i){
        for(int j = 0 ; j < cantidad_vertices ; ++j){
                matriz_recorridos[i][j] = j;
        }
    }

    /* La inicializo como:
                            01234
                            01234
                            01234
                            01234
    */

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::cargar_matriz_adyacencia(){

    for(int i = 0 ; i < cantidad_filas ; ++i){
        for(int j = 0 ; j < cantidad_columnas ; ++j){
            for(int k = 0 ; k < grafo[i][j] -> obtener_cantidad_conexiones() ; ++k){
                int indice_vertice_origen = grafo[i][j] -> obtener_indice();
                int indice_vertice_destino = grafo[i][j] -> obtener_elemento_de_lista_conexiones(k);
                matriz_adyacencia[indice_vertice_origen][indice_vertice_destino] = grafo[i][j] -> obtener_elemento_de_lista_pesos(k);
            }
        }
    }

}


// ------------------------------------------------------------------------------------------------------------


void Grafo::conectar_esquinas(const Mapa &mapa){

    // Arriba-Izquierda
    grafo[0][0] -> conectar_vertice(
        grafo[0][1] -> obtener_indice(),
        mapa.obtener_peso_casillero(0,1,jugador)
    );

    grafo[0][0] -> conectar_vertice(
        grafo[1][0] -> obtener_indice(),
        mapa.obtener_peso_casillero(1,0,jugador)
    );

    // Arriba-Derecha
    grafo[0][cantidad_columnas-1] -> conectar_vertice(
        grafo[0][cantidad_columnas-2] -> obtener_indice(),
        mapa.obtener_peso_casillero(0,cantidad_columnas-2,jugador)
    );

    grafo[0][cantidad_columnas-1] -> conectar_vertice(
        grafo[1][cantidad_columnas-1] -> obtener_indice(),
        mapa.obtener_peso_casillero(1,cantidad_columnas-1,jugador)
    );

    // Abajo-Izquierda
    grafo[cantidad_filas-1][0] -> conectar_vertice(
        grafo[cantidad_filas-2][0] -> obtener_indice(),
        mapa.obtener_peso_casillero(cantidad_filas-2,0,jugador)
    );

    grafo[cantidad_filas-1][0] -> conectar_vertice(
        grafo[cantidad_filas-1][1] -> obtener_indice(),
        mapa.obtener_peso_casillero(cantidad_filas-1,1,jugador)
    );

    // Abajo-Derecha
    grafo[cantidad_filas-1][cantidad_columnas-1] -> conectar_vertice(
        grafo[cantidad_filas-2][cantidad_columnas-1] -> obtener_indice(),
        mapa.obtener_peso_casillero(cantidad_filas-2,cantidad_columnas-1,jugador)
    );

    grafo[cantidad_filas-1][cantidad_columnas-1] -> conectar_vertice(
        grafo[cantidad_filas-1][cantidad_columnas-2] -> obtener_indice(),
        mapa.obtener_peso_casillero(cantidad_filas-1,cantidad_columnas-2,jugador)
    );

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
        int peso_abajo = mapa.obtener_peso_casillero(1,j,jugador);
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


// ------------------------------------------------------------------------------------------------------------


void Grafo::camino_minimo_floyd_warshall(){
    // i: filas, j:columnas, k:pivotes
    int i, j, k;
    
    // La distancia de ir a un vertice hasta el mismo es cero:
    /*
    for( i=0; i < cantidad_vertices; i++){
        matriz_distancias[i][i] = 0;
    }
    */

    // Voy pivotenado con k, selecciono la columna y fila
    // a partir del valor en k busco el siguiente en i y j
    // si la suma de estos valor es mayor al de k me quedo con el de k
    // sino me quedo con la suma de i+j. Los pesos estan en la matriz de adyacencia

    for( k = 0; k < cantidad_vertices; ++k){

        for( i = 0; i < cantidad_vertices; ++i){

            for( j = 0; j < cantidad_vertices; ++j){

                int dt = matriz_distancias[i][k] + matriz_distancias[k][j];

                if( (dt < matriz_distancias[i][j]) ){

                    matriz_distancias[i][j] = dt;
                    matriz_recorridos[i][j] = matriz_recorridos[i][k];
                }
                else if( matriz_distancias[i][j] == INFINITO)
                    matriz_recorridos[i][j] = -1; // POSICION NO ENCONTRADA
            }   

        }
    }
}


// -----------------------------------DEBUUGEEOO----------------------------------------------------------------------

const int VERTICES_DEBUGGEO = 22;

void Grafo::imprimir_matriz_ady(){
    cout << TAB;
    for (int k = 0 ; k < VERTICES_DEBUGGEO ; ++k)
        cout << FONDO_COLOR_AMARILLO << k << TAB;
    cout << FIN_DE_FORMATO << endl;


    for(int i = 0 ; i < VERTICES_DEBUGGEO ; ++i){ 
                cout << FONDO_COLOR_AMARILLO << i << FIN_DE_FORMATO << TAB;
        for(int j = 0 ; j < VERTICES_DEBUGGEO ; ++j){
            if(matriz_adyacencia[i][j] == INFINITO)
                cout << "Inf" << '\t';
            else
                cout << matriz_adyacencia[i][j] << '\t';
        }
        cout << endl;
    }


}


// ------------------------------------------------------------------------------------------------------------


void Grafo::imprimir_matriz_recorridos(){
    cout << TAB;
    for (int k = 0 ; k < VERTICES_DEBUGGEO ; ++k)
        cout << FONDO_COLOR_AMARILLO << k << TAB;
    cout << FIN_DE_FORMATO << endl;

    for(int i = 0 ; i < VERTICES_DEBUGGEO ; ++i){ 
        cout << FONDO_COLOR_AMARILLO << i << FIN_DE_FORMATO << TAB;
        for(int j = 0 ; j < VERTICES_DEBUGGEO ; ++j){
            if(matriz_recorridos[i][j] == INFINITO)
                cout << "Inf" << '\t';
            else
                cout <<matriz_recorridos[i][j] << '\t';
        }
        cout << endl;
    }


}


// ------------------------------------------------------------------------------------------------------------


void Grafo::imprimir_matriz_distancias(){
    cout << TAB;
    for (int k = 0 ; k < VERTICES_DEBUGGEO ; ++k)
        cout << FONDO_COLOR_AMARILLO << k << TAB ;
    cout << FIN_DE_FORMATO << endl;

    for(int i = 0 ; i < VERTICES_DEBUGGEO ; ++i){
        cout << FONDO_COLOR_AMARILLO << i << FIN_DE_FORMATO << TAB;
        for(int j = 0 ; j < VERTICES_DEBUGGEO ; ++j){
            if(matriz_distancias[i][j] == INFINITO)
                cout << "Inf" << '\t';
            else
                cout <<matriz_distancias[i][j] << '\t';
        }
        cout << endl;
    }


}


// ------------------------------------------------------------------------------------------------------------


void Grafo::imprimir_camino_minimo(int origen, int destino){

    cout << "ESTE CAMINO CUESTA ENERGIA: " << matriz_distancias[origen][destino] << ' ';

    if(matriz_recorridos[origen][destino] == -1)
        cout << "no way negro" << endl;
    else{
        cout << origen;
        do{
            cout << "->" << matriz_recorridos[origen][destino];
            origen = matriz_recorridos[origen][destino];
            cout << '(' << matriz_distancias[origen][destino] << ')';
        }while(origen != destino);
    }

    cout << endl;


}