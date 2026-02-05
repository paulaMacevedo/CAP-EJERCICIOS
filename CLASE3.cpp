#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define defineOP(operator)
//EJERCICIO 4
class BigSquaredMatrix{

    std :: vector<int> datos;
    int ancho;
    // constructor
    BigSquaredMatrix(int ancho){
        this->ancho = ancho;
        // reservar memoria de forma optima en c++
        datos = std:: vector<int>(ancho *ancho);
        //datos = (int*)malloc(sizeof(int)*ancho*ancho);
        //datos = new int [ancho *ancho];
    }
    // constructor copia --> POR DEFECTO
    BigSquaredMatrix(const BigSquaredMatrix& m): ancho (m.ancho),datos(ancho*ancho){
         for (int i =0; i<ancho*ancho;i++){
               datos[i]=m.datos[i];
            }
    }

    // constructor move
    BigSquaredMatrix(const BigSquaredMatrix&& m): ancho (m.ancho),datos(std :: move(m.datos)){
         
    }
    void operator=(const BigSquaredMatrix& m); // copy asigment
    void operator =(BigSquaredMatrix&& m); // move assigment
    // modificar
    void modificar (int fila, int col, int valor){
        datos[ancho *fila+col]=valor;
        int * fila = datos+fila *ancho;
        // datos es el puntero, fila es la posicion a la que voy y ancho lo q me muevo
        fila [col]= valor;
    }
    int getfila(int fila){ // modificar
        return datos.data() +fila*ancho;
    }
   const  int *operator (int fila) const{ // constante solo se puede leer no se puede modificar // leer
        #indef DEBUG
        if (fila >= ancho){
            throw..
        }
        #endif
        return datos.data()+fila*ancho;
        // nos va a dar el int * que tiene por dentro
    }
    B
    //insertar
    //eliminar
    // leer
    x nombre(param)

    // constructor que rellena con valores aleatorios de 0 a max
    // vamos a tener que llamar al constructor como si no lo hubieramos llamado antes
    BigSquaredMatrix(int ancho, int max): ancho(ancho), datos(ancho*ancho) { // una alternativa para incializar, si no siempre se puede poner lo del constructor de arriba
            for (int i =0; i<ancho*ancho;i++){
               datos[i]=rnd()%(max+1);
            }
    }
    // SI NO VOY A TOCAR VALORES LA MEJOR OPCION ES PONERLE CONST
    BigSquaredMatrix operator+=(const BigSquaredMatrix m){
        BigSquaredMatrix resultado (ancho);
        for (int i =0; i<ancho*ancho;i++){
            m.datos[i]= this->datos[i]+m.datos[i];
            
        }
        return resultado;

    }
    BigSquaredMatrix operator+(BigSquaredMatrix m){
        // si m es l-value lo copia y lo reserva en memoria nueva
        // si m es r-value, usa el constructor  move, y no reserva nada nuevo
        return m+=(this*);
    }
     BigSquaredMatrix operator+(const BigSquaredMatrix& m)&&{
        return (this*)+=m;
    }
    int foo (){
        BigSquaredMatrix m(10);//101 int (100*100 +1(anch0))
        m[3][7]=14;
        const BigSquaredMatrix m2(12);//145 (12*12+1) int +101=246
        int X = m[3][7];// 1 int +246 = 247
    }
    int main(){
        BigSquaredMatrix m (1000,1000); // 10000*100000ç
        BigSquaredMatrix m2 = m+m; // 1000+1000 para copiar m como parámetro, para resercar resultado dentro, para copiar resultado m2
        // invocamos al constructor copy
        BigSquaredMatrix m3(m);
        // invocamos al constructor move
        BigSquaredMatrix m4 (m+m);
        // r values
        BigSquaredMatrix m3 = (m2 +m)+m2; // 1000*1000 suma no otro 1000 ya que usamos el espacio de memoria de m2
    }
}
/*
mirar 
template <long I>
constexpr long factoriañ(){
return factorial <I-1>*I;}
*/