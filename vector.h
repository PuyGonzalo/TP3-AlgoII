#ifndef VECTOR_H
#define VECTOR_H

const int VECTOR_TAMANIO_INICIAL = 2;


template <typename D>
class Vector{
    
private:
    // Atributos
    D* datos;
    int longitud;
    int capacidad;

    // Metodos privados

    // pre: tam > 0
    // pos: Redimensiona el vector, si tam es mayor que la longitud inicial, deja los datos anteriores y completa con vacios, si es menor, corta los datos que exceden.
    void redimensionar(int nuevo_tam);

public:
    // Metodos

    // pre: -
    // pos: Construye un vector vacio
    Vector();

    // pre: tam > 0
    // pos: Construye un vector de longitud tam y datos vacios
    Vector(int tam = VECTOR_TAMANIO_INICIAL);

    // Constructor de copia (Dejar?)
    //Vector(const Vector<D>& vec);

    // pre: dato tiene que ser un Dato valido
    // pos: Inserta el dato, en la ultima posicion
    void insertar(D& dato);

    // pre: 0 <= pos < longitud, dato tiene que ser un Dato valido
    // pos: Inserta el dato, en la posicion "pos", la primera es la 0.
    void insertar_en_posicion( D& dato, int pos);

    // pre: 0 <= pos < longitud, y que el dato exista
    // pos: devuelve el dato que esta en pos
    D consultar(int pos);

    // pre: -
    // pos: Devuelve la longitud del vector
    int obtener_longitud();

    // Sobrecarga del operador =
    //void operator=(const Vector<D>& vec); // No se si me sirve para algo sinceramente

    // pre: -
    // pos: Libera recursos utilizados
    ~Vector();

};


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::Vector(){

    this -> longitud = 0;
    datos = nullptr;
}


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::Vector(int tam){
    
    this -> longitud = 0;
    this -> capacidad = tam;
    datos = new D[tam];
}


// -----------------------------------------------------------------------------------------


template <typename D>
Vector<D>::~Vector(){

    if(longitud > 0)
        delete[] datos;
}


// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::redimensionar(int nuevo_tam){

    D* aux;
    aux = new D[nuevo_tam];

    for(int i = 0; i < longitud; ++i){
        aux[i] = datos[i];
    }

    if(nuevo_tam < longitud)
        longitud = nuevo_tam;

    delete[] datos;

    capacidad = nuevo_tam;

    datos = aux;
}


// -----------------------------------------------------------------------------------------

/*
template <typename D>
void Vector<D>::operator=(const Vector<D>& vec){

    D* aux;    

    if(this -> longitud != vec.longitud){

        aux = new D[longitud];
        delete[] datos;
        datos = aux;
        this -> capacidad = vec.capacidad;
        this -> longitud = vec.longitud;

    }

    for(int i = 0; i < this -> longitud; ++i)
        this -> datos[i] = vec.datos[i];
}
*/

// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::insertar(D& dato){

    if(longitud == capacidad)
        this -> redimensionar(capacidad+1);
    
    datos[longitud] = dato;
    longitud++;
}


// -----------------------------------------------------------------------------------------


template <typename D>
void Vector<D>::insertar_en_posicion( D& dato, int pos){

    datos[pos] = dato;
}


// -----------------------------------------------------------------------------------------


template <typename D>
D Vector<D>::consultar(int pos){

    return datos[pos];
}


// -----------------------------------------------------------------------------------------


template <typename D>
int Vector<D>::obtener_longitud(){

    return this -> longitud;
}


#endif //VECTOR_H