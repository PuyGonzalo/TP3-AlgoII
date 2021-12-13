#ifndef GRAFO_H
#define GRAFO_H

#include "mapa.h"
#include "vertice.h"
#include "lista.h"

const int POSICION_IMPOSIBLE = -1;

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
    // pos:
    void destruir_matriz_adyancencia();

    // pre: -
    // pos:
    void destruir_matriz_distancias();

    // pre: -
    // pos:
    void destruir_matriz_recorridos();

    // pre: -
    // pos:
    void destruir_vertices();

    // pre: -
    // pos:
    void asignar_datos_basicos(const Mapa &mapa, Jugador_t jugador);

    // pre: -
    // pos:
    void crear_vertices();

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

    // pre: -
    // pos: 
    void actualizar_grafo(const Mapa &mapa);

    // pre: -
    // pos:
    Estado_t procesamiento_del_movimiento(Coordenadas coordenadas_origen, int coord_destino_x, int coord_destino_y, double &energia_requerida, Lista<Coordenadas*> &camino);

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