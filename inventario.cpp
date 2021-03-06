#include <iostream>
#include "inventario.h"


// ------------------------------------------------------------------------------------------------------------


Inventario::Inventario(){

    this -> jugador = NADIE;
    this -> cantidad_materiales = 0;
    this -> andycoins_gastadas = 0;
    this -> bombas_compradas = 0;
    this -> bombas_usadas = 0;

}


// ------------------------------------------------------------------------------------------------------------


Inventario::~Inventario(){

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::agregar_material_a_lista(Material* material){

    materiales.insertar(material);
    this -> cantidad_materiales++;

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::mostrar_inventario(){

    cout
    << endl << TAB << TAB << NEGRITA << SUBRAYADO
    << left
    << setw(10)
    << "Material"
    << left
    << setw(9)
    << "Cantidad"
    << FIN_DE_FORMATO
    << endl;


    for(int i = 0 ; i < cantidad_materiales ; ++i)
        cout
        << TAB << TAB
        << left << setw(10) << materiales.consultar(i) -> obtener_nombre_material()
        << left << setw(9) << materiales.consultar(i) -> obtener_cantidad() << endl;

}

// ------------------------------------------------------------------------------------------------------------

int Inventario::buscar_material(char identificador) const{

    int i = 0;
    int ubicacion = -1;
    bool material_encontrado = false;

    while(i < cantidad_materiales && !material_encontrado ){
        if(materiales.consultar_const(i) -> obtener_identificador() == identificador){
            ubicacion = i;
            material_encontrado = true;
        }
        ++i;
    }
    
    return ubicacion;
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_piedra() const{
    
    int ubicacion_material;
    ubicacion_material = buscar_material(IDENTIF_PIEDRA);

    return materiales.consultar_const(ubicacion_material) -> obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------

double Inventario::obtener_cantidad_de_madera(){
   
    int ubicacion_material;
    ubicacion_material = buscar_material(IDENTIF_MADERA);

    return materiales.consultar(ubicacion_material) -> obtener_cantidad();
}

// ------------------------------------------------------------------------------------------------------------


double Inventario::obtener_cantidad_de_metal(){
    
    int ubicacion_material;
    ubicacion_material = buscar_material(IDENTIF_METAL);

    return materiales.consultar(ubicacion_material) -> obtener_cantidad();
}


// ------------------------------------------------------------------------------------------------------------


double Inventario::obtener_cantidad_de_bombas() const{
    
    int ubicacion_material;
    ubicacion_material = buscar_material(IDENTIF_BOMBA);

    return materiales.consultar_const(ubicacion_material) -> obtener_cantidad();
}


// ------------------------------------------------------------------------------------------------------------


double Inventario::obtener_cantidad_de_andycoins() const{
    
    int ubicacion_material;
    ubicacion_material = buscar_material(IDENTIF_ANDYCOINS);

    return materiales.consultar_const(ubicacion_material) -> obtener_cantidad();
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::restar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal){
   
    int ubicacion_piedra, ubicacion_madera, ubicacion_metal;

    ubicacion_piedra = buscar_material(IDENTIF_PIEDRA);
    ubicacion_madera = buscar_material(IDENTIF_MADERA);
    ubicacion_metal = buscar_material(IDENTIF_METAL);

    materiales.consultar(ubicacion_piedra) -> restar_cantidad(costo_piedra);
    materiales.consultar(ubicacion_madera) -> restar_cantidad(costo_madera);
    materiales.consultar(ubicacion_metal) -> restar_cantidad(costo_metal);

}


// ------------------------------------------------------------------------------------------------------------


void Inventario::sumar_cantidad_materiales_construccion(double costo_piedra, double costo_madera, double costo_metal){
    int ubicacion_piedra, ubicacion_madera, ubicacion_metal;

    ubicacion_piedra = buscar_material(IDENTIF_PIEDRA);
    ubicacion_madera = buscar_material(IDENTIF_MADERA);
    ubicacion_metal = buscar_material(IDENTIF_METAL);

    materiales.consultar(ubicacion_piedra) -> sumar_cantidad(costo_piedra);
    materiales.consultar(ubicacion_madera) -> sumar_cantidad(costo_madera);
    materiales.consultar(ubicacion_metal) -> sumar_cantidad(costo_metal);

}

// ------------------------------------------------------------------------------------------------------------

void Inventario::sumar_cantidad_material(char identificador, double cantidad){
    
    int ubicacion = buscar_material(identificador);

    materiales.consultar(ubicacion) -> sumar_cantidad(cantidad);
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::restar_cantidad_material(char identificador, double cantidad){
    
    int ubicacion = buscar_material(identificador);

    materiales.consultar(ubicacion) -> restar_cantidad(cantidad);
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::guardar_inventario(ofstream& archivo_materiales){

    int i = 0;
    for(; i < cantidad_materiales-1 ; ++i){
        archivo_materiales << materiales.consultar(i) -> obtener_nombre_material()
        << ESPACIO <<
        materiales.consultar(i) -> obtener_cantidad() << '\n';
    }

    archivo_materiales << materiales.consultar(i) -> obtener_nombre_material()
    << ESPACIO <<
    materiales.consultar(i) -> obtener_cantidad();

}


// ------------------------------------------------------------------------------------------------------------


string Inventario::guardar_linea_inventario_en_string(int pos){

    stringstream ss;


    ss << materiales.consultar_const(pos) -> obtener_nombre_material() << "," << to_string((int) materiales.consultar_const(pos) -> obtener_cantidad()) << endl;

    return ss.str();
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::aumentar_andycoins_gastadas(int cantidad){
    andycoins_gastadas+=cantidad;
}
   

// ------------------------------------------------------------------------------------------------------------

 
int Inventario::obtener_andycoins_gastadas() const{
    return andycoins_gastadas;
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::aumentar_bombas_usadas(int cantidad){
    bombas_usadas += cantidad;
}


// ------------------------------------------------------------------------------------------------------------


int Inventario::obtener_bombas_usadas() const{
    return bombas_usadas;
}


// ------------------------------------------------------------------------------------------------------------


void Inventario::aumentar_bombas_compradas(int cantidad){
    bombas_compradas += cantidad;
}


// ------------------------------------------------------------------------------------------------------------


int Inventario::obtener_bombas_compradas() const{
    return bombas_compradas;
}


// ------------------------------------------------------------------------------------------------------------


int Inventario::obtener_cantidad_materiales(){
    return cantidad_materiales;
}