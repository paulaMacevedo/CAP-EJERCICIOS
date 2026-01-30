#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class BigSquaredMatrix{

    int *datos;
    int ancho;
    // constructor
    BigSquaredMatrix(int ancho){
        this->ancho = ancho;
        datos = (int*)malloc(sizeof(int)*ancho*ancho);
        //datos = new int [ancho *ancho];
    }
    // modificar
    void modificar (int fila, int col, int valor){
        datos[ancho *fila+col]=valor;
        int * fila = datos+fila *ancho;
        // datos es el puntero, fila es la posicion a la que voy y ancho lo q me muevo
        fila [col]= valor;
    }
    int *operator(int fila){
        return datos +fila*ancho;
    }
    //insertar
    //eliminar


}