#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// en archivo .h

template<typename T>
std:: vector <T> suma (std:: vector <T> a, std:: vector <T> b);
// vamos a tener que definir el tipo para que el programa en suma.c sepa que tipo es y pueda ejecutar
typedef suma<int> sumaInt;
// ventaja : mantengo la separación en .h/.c, el codigo se compila una vez
// desventaja: tengo que pensar en cada template que quiero usar, si quiero emplear siempre que quiero usar, si fuera float, copiamos la misma linea sustituyendo <int> por float

// en archivo suma.c;
template<typename T>
// el inline indica que si se encuentra dos veces en el compilador que se quede con la primera que se encuentre (no tiene porque ser la primera que genere)
inline std:: vector<T> suma (std:: vector<t> a, std:: vector<T> b){
    for (int i =0; i<a.size(); i++){
        a[i]=a[i]+b[i];
        return a;
    }

}
template <typedef T>
T& std:: vector<T>:: operator[](const size_t i);
// EJEMPLO : en vector.h todo esta en el .h
A = (B+C) + (D+E);
A = (B.operator + (C)).operator+(D.operator+(E));
// llama al operador asignación
// llama al operador suma
// llama al operador []..

for (...)
A[i]=B[i]+C[i]...

// ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡IMPORTANTE!!!!!!!!!!!!!!!!!!!
// El que las funciones este disponibles para todas las unidades de compilación
    // permite que se puedan "copiar y pegar en lugares de subrutinas"->inline



// en prinicpal .c
int main(){

}
///////////////////////////////////////////////////7777
// para inicializar el valor, en el constructor  :centro (centro), radio (Radio){}
// inicializar tras los : es mñas rápido siempre que se pueda hacer
// Siempre podemmos construir con lista de incialización{}
// A menudo no haceb falta constructores
// Si tenemos rederencias i oyberos entre los miembros de nuestra clase, hacen falta:
    // constructor copia
    // constructor move
    //A menudo constructir vacio ()
    // El destructor (Sólo su hay reservas con malloc/new o polimorfismo)
    