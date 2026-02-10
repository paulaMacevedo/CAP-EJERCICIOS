#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
// MÉTODO DE EJECUCCIÓN EN TERMINAL
//g++ CLASE6PARTE2.cpp -o CLASE6PARTE2 -O2 -fopenmp
int v1(){
   
    #pragma omp parallel
    {
        int tid = omp_get_thread_num(); // con esta función lo que vamos a hacer es asignar un numero a cada hilo
        int pid = omp_get_num_threads();
        printf("hola soy %d de un total de %d \n", tid,pid);
    }
}
/*
nt --> omp_ getNumThreads()-> nº total de hilos // MPI_GETSIZE´
tid --> impo_getThreadNum()-> id del hilo actual // MPI_getRank

#Pragma omp parallel 
    1 linea o {}
    crea tantos hilos como haya disponibles
#pragma omp section
    poco recomendado
EN AMBOS CASOS
    Barrera implícita al final, si no la quremos tenemos que poner: nowait
#Pragma omp for
    1 linea un bucle for
    for (....)-> lo va a transformar en un bucle basado en hilos
    la barrera esta implicita
#Pragma omp parallel for
    Se crea un for y todos ellos tienen que ser estar paralelizado
#Pragma omp master
    solo ejecuta hilo 0
#pragma omp single
    solo ejecuta el 1º que llegue
#pragma omp critical
    Sección critica
#pragma imp atomic
    1 linea, operación atómica
    Protege la memoria

#pragma omp parallel snered(x,y...), private (....)
    1 linea o {}
#pragma omp section
    Barrera implícita al final, si no la queremos: nowait

#pragma omp parallel firsiprivate(x) (comprobar no veo bien la pizarra :D)
x= omp_get_threadNum();

*/
int sumatorio (std :: vector<int> v){
    int suma =0;
    #pragma omp parallel for
    for(int i =0; i< v.size(); i++){
    #pragma omp critical
        suma += v[i];
    }
    return suma;

}
// 100%%% ENTRA EN EL EXAMEN --> PARALELIZA EL SIGUIENTE RESULTADO
    int sumatorio(const std::vector<int>& v) {
    int maxGlobal = v[0];

    #pragma omp parallel
    {
        int maxLocal = v[0];

        #pragma omp for
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > maxLocal)
                maxLocal = v[i];
        }

        #pragma omp critical
        {
            if (maxLocal > maxGlobal)
                maxGlobal = maxLocal;
        }
    }

    return maxGlobal;
}
