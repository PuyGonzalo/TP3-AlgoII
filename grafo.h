#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "vertice.h"
#include "lista.h"


class Grafo{

private:
    // Atributos
    Jugador_t jugador;
    int** matriz_adyacencia;
    int** matriz_distancias;
    int** matriz_recorridos;
    Vertice*** grafo;
    int cantidad_vertices;
    int cantidad_filas;
    int cantidad_columnas;

public:
    // Metodos

    // pre: -
    // pos: CONSTRUCTOR del grafo de un jugador a partir del mapa
    Grafo (const Mapa &mapa, Jugador_t jugador); // pasar por const referencia?

    // pre: -
    // pos: DESTRUCTOR del grafo
    ~Grafo();

    // pre: -
    // pos: inicializa la matriz de adyacencia (para el grafo pedido en el TP)
    void inicializar_matriz_adyacencia();

    // pre: -
    // pos: inicializa la matriz de adyacencia (para el grafo pedido en el TP)
    void inicializar_matriz_recorridos();

    // pre: -
    // pos:
    void inicializar_matriz_distancias();

    // pre: -
    // pos: carga la matriz de adyacencia
    void cargar_matriz_adyacencia();

    // pre: -
    // pos: conecta los vertices "de las esquinas del mapa"
    void conectar_esquinas(const Mapa &mapa);

    // pre: -
    // pos: conecta los vertices "de las orillas del mapa"
    void conectar_orillas(const Mapa &mapa);

    // pre: -
    // pos: conecta los vertices "del centro del mapa"
    void conectar_centros(const Mapa &mapa);

    // pre:
    // post:
    void camino_minimo_floyd_warshall();

    // FUNCION PARA DEBUGGER
    void imprimir_matriz_ady();

    // pre:
    // post:
    void imprimir_matriz_recorridos();

    // pre:
    // pos:
    void imprimir_matriz_distancias();

    // pre:
    // pos:
    void imprimir_camino_minimo(int origen, int destino);
    

};





#endif // GRAFO_H