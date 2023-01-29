// Actividad1_A01793006.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


//Configuracion del proyecto
#include <iostream>
#include <omp.h>

//Definicion de Variables
#define N 1000
#define chunk 100
#define mostrar 10

//Funcion para Imprimir el Arreglo
void imprimeArreglo(float* d);

//Creacion de arreglos

int main()
{
    std::cout << "Ejemplo de Paralelos!\n";
    //La variable A y B van a guardar un arreglo, mientras que C representa la suma de los conjuntos
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        //Se llenan los arreglos A & B con valores aleatorios
        a[i] = i * 5;
        b[i] = (i + 1) * 2;
    }
    int pedazos = chunk;
    //Pedazos define el tamaño de los hilos

    //Ddeclar el for como un proceso paralelo
#pragma omp parallel for \
    shared(a,b,c,pedazos)private(i)\
    schedule(static,pedazos)
    /*La programacion para atender los hilos de definio por el default estatico y con la longitud de los hilos,
    por lo que se ejecutara en pedazos de 100, es decir, cada hilo tiene 100 valores por lo que tendriamos
    10 hilos considerando que tenemos 1000 valores*/

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    /*El ciclo es ejecutado de manera paralela ej.c1 = a1 + b1, almacenando el resultado sin tener que esperar
    que el arrglo se ejecute de manera secuencial (completa) para obtener un resultado*/
    std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo A:" << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo B:" << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo C:" << std::endl;
    imprimeArreglo(c);
    //Se imprimen los primeros 10 registros del hilo
}
//Impresion del valor que esta ejecutando en ese momento el for paralelo
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << "-";
    std::cout << std::endl;
}