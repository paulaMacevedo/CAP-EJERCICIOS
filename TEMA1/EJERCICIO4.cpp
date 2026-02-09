#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdexcept>
#include <iostream>
// USOS DE ELEMENTOS DE TEMPLATES
// LO QUE NOS PIDEN
/*
Que sea matriz genérica, es decir que sea Matrix <T>
Que uso un único array lineal (1D) en orden por filas
Tiene que tener:
    Constructor normal
    Constructor copia
    Constructor move
    Operador = copia
    Operador = move
Tiene los operadores de acceso
    Lectura (const)
    escritura (no const)
Tenga operador suma
Minimice copias usando
    const &
    r-values (&&)
*/
// COMO ES CON TEMPLATE LO IMPLEMENTAMOS
template <typename T>
class Matrix {
    private:
    // declaramos las variables
    size_t n; // numero de elementos de la matriz
    std:: vector <T> data; // almacenamiento de los valores en un array
 
    //ahora vamos a hacer un constructor
    public:
        Matrix(size_t tamano):
        n(tamano), data(tamano *tamano){}
        // N va a indicar el tamaño de la matriz y data el espacio de memoria que vamos a tener que guardar, dato * dato hacemos las filas y columnas

    // realizamos el constructor copy
    Matrix(const Matrix &otro):
    n(otro.n), data(otro.data){}
    // con n copio el tamaño
    // con data copio todo el vector

    // constructor move-> Se usa cuando el objeto va a "morir" (rvalue)y podemos robar datos
    Matrix(Matrix&& otro) noexcept: // la matriz && otro es una matriz temporal q va a morir
    n(otro.n), data(std:: move(otro.data)){  // robamos las cosas, no copiamos simplemente asociamos un puntero interno
        otro.n=0; // dejamos el objeto antiguo vacio
    }

    // ahora vamos a realizar las asignacion por copia
    Matrix& operator=(const Matrix&& other){ // other matriz antigua
        if (this != &other){ // si nuestra matriz actual todavía no es igual, la vamos a copiar
            n = other.n;
            data= other.data;
        }
        return *this;
    }
    // ahora vamos a realizar la asignación por move
    Matrix& operator=(Matrix& other) noexcept{ // super importante el no except
        if (this != &other){
            n = other.n;
            data= std:: move(other.data); // se lo robabamos a la matrix principañ
            other.n=0;
        }
        return *this;
    }

    // Accedemos la escritura
    T& operator()(size_t i, size_t j){ // i fila j columna
    // El T& significa que devuelvo una referencia al dato no una copia
        if (i>=n || j >= n){ // si te sales del rango de la matriz te devuelve un error
            throw std:: out_of_range("indice fuera de rango");
        }
        return data[i*n+j]; // devolvemos el valor de la casilla
    }
    // operador lectura, es igual q la escritura a diferencia de que tiene un const y por ello no se va a poder modificar
    const T& operator()(size_t i, size_t j) const {
    if (i >= n || j >= n) {
        throw std::out_of_range("indice fuera de rango");
    }
    return data[i * n + j];
}

    // Creamos el operador suma
    Matrix operator+(const Matrix& other) const{
        if (n != other.n){
            throw std:: invalid_argument ("tamaño incompatibles");

        }
        Matrix result (n);// creamos una matriz nueva vacía del mismo tamaño
        for (int i =0; i< data.size(); ++i){
            result.data[i]= data[i]+ other.data[i]; // data es la primer matriz que vamos a sumar, del constructor y other es la segunda dada por la función
        }
        return result;
    }
    size_t size()const {
        return n;
    }

};