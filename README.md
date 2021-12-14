# Trabajo Practico 3 - Algoritmos y Programacion II
## Grupo: Soldados de MC
### Integrantes:
- Puy Gonzalo, Padrón: 99784
- Ivan Lisman, Padrón: 100001
- Maximiliano Pintos, Padrón: 99711 


Repositorio para el Trabajo Práctico número 3 de Algoritmos y Programación II (95.12)

---

## Aclaraciones

### Compilación

El programa tiene varias sub-carpetas, por lo tanto para compilar utilizar la siguiente linea de comando

~~~
g++ -o <nombre_ejecutable> *.cpp Materiales/*.cpp Edificios/*.cpp Casilleros/*.cpp Superficies/*.cpp Objetivos/*.cpp -Wall -Werror -Wconversion -pedantic -pedantic-errors
~~~

<span style="color:red">Por favor, tener en cuenta las siguientes consideraciones a la hora de compilar:</span>


- **Los archivos `*.txt` deben estar en la carpeta "Archivos".**
- **Por un tema de diseño y consigna del mismo TP, por favor asegurarse que los archivos estén hechos en LINUX. Si se hacen en Windows, puede haber un problema por la diferencia entre los 'end of line' de cada sistema operativo.**
-  **NO mover los `.cpp` de las correspondientes sub-carpetas.**

### Funcionamiento del programa

- En cuanto a los atributos de cada casillero, se cuenta con una superficie con atributos booleanos que van a dictar las características finales del casillero. Esto se realizó de esta manera ya que. Por ejemplo, un Lago es inaccesible porque se decidió que ese terreno, momentáneamente, no es accesible, no que un Casillero Inaccesible lo es porque tiene un Lago.

- Se utilizó el algoritmo de Floyd-Warshall para realizar el camino minimo.

- Las coordenadas se representan de la siguiente manera:

<p align="center">
  <img src="https://user-images.githubusercontent.com/39422659/141196632-0186b85f-0ac1-4cce-a1b0-d592ad979fb8.png" />
</p>

- `HERRAMIENTAS` son funciones que sirven para realizar ciertos tipos de validaciones necesarias

- `UTILIDADES` engloba funciones que sirvieron para mejorar el encapsulamiento y la modularizacion del proyecto a la hora de usar un menu.


## Diagrama UML del proyecto

<p align="center">
  <img src="https://user-images.githubusercontent.com/39422659/145930120-f4e2d89f-5c12-43fc-8732-33c054e63fd1.jpg" />
</p>


