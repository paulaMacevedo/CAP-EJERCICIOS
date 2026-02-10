#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class nodo{
    public:
    int valor;
     nodo *Siguiente;
     nodo (int Nvalor){
        valor=Nvalor;
        Siguiente=NULL;
     }
};
int main (){
    srand(0);
    int nElementos =1000;
    int nIteraccion=50;
    // creamos las listas
    nodo *lista1= new nodo (rand()); // rand lo que hace es ir guardando los valores aleatorios
    nodo *lista2 = new nodo(rand());
    nodo *actual= lista1;
    // generamos las listas enlazadas añadiendo nuevo nodo, para indicar que avance
    for (int i=1;i<nElementos;i++){
        nodo *nuevo = new nodo (rand());
        actual->Siguiente=nuevo;
        actual=nuevo;
    }
    actual=lista2;
    // Es muy importante que empiezen desde 1
    for (int i =1; i<nElementos;i++){
        nodo *nuevo = new nodo(rand());
        actual->Siguiente=nuevo;
        actual=nuevo;
    }
    // generamos la lista que vamos donde vamos a ir guardando los resultados
    nodo *lista3;
    // como queremos cronomentrar el tiempoq que tarda vamos a inicializar el tiempo
    clock_t t1 = clock();
     #pragma omp parallel // EL PRAGMA TIENE QUE IR DENTRO DE LA FUNCIÓN QUE QUREMOS PARALELIZAR, NO PUEDE IR ANTES, SI LO PONEMOS AQUÍ NOS VA A AYUDAR A PARALELIZAR EL TIEMPO
    for(int iter = 0; iter < nIteraccion; iter++){
        // vamos accediendo a cada lista de su valor guardandolo en los espacios de una tercera
        nodo *suma1 = lista1; // suma apunta al primer nodo de la lista 1
        nodo *suma2= lista2; // suma apunta al primer nodo de la lista 2
        int resultado = suma1->valor+suma2->valor; // vamos guardando en la variable la suma de las variables
        // creamos el primer nodo de la lista resultado
        nodo *nuevo= new nodo (resultado);// VAMOS ALMACENANDO AQUI LOS RESULTADOS
        lista3=nuevo;
        nodo *suma3 = lista3; // es el puntero que va a avanzando por la lista de resultado
        for (int i =1; i<nElementos;i++){
            // vamos a recorrer todas las listas apra poder sumar su valor
            suma1= suma1->Siguiente;
            suma2= suma2->Siguiente;
            resultado= suma1->valor + suma2->valor;
            // creamos otro nodo que vamosa añadir a la lisya de nodos nuevo con el nuevo valor
            nuevo = new nodo(resultado);
            suma3->Siguiente=nuevo;
            suma3=nuevo;
        }
    }
    clock_t t2 = clock();
    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total: %g\n", elapsed);
	printf("por elemento: %g\n", elapsed/nElementos);
	return 0;
   
}