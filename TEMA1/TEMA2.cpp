#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

std:: vector <int> suma (const std:: vector<int>& a, std:: vector<int> b){
    const int tam = a.size();
    int nt;
    # pragma omp parallel for
    {
        int x =7; // la X va a ser vista por todos los hijos y todas las variables
        int tid = omp.getThreadNum(); // hace falta todas las copas 
         nt = omp.getNumThreads();// tan solo hace falta una copia, todos escriben lo mismo
        for (int i =tid; i<tam; i+= nt){
        b[i]= a[i] + b[i];
    }
    }
    
    return b;
}
int max (const std:: vector<int>& a, std:: vector<int> b){
    int res = 0;
    
    for (int i =0; i<tam; i++){
       res += a[i];
    }
    return res;
}
// hay que conseguir que res la vean todos los hilos

/* un hilo por cada elemento 
 dividir el sector en bloques
     - Hilo 0: lee el elemento 0
     - Hilo 1: lee el elemento 1000?
     - Hilo 2: lee el elemento 2000?


// Dividir elemento a lemento
    - Hilo 0: elem 0
    - Hilo 1: elem 1
    - Hilo 2: elem 2
    - Hilo 3: elem 3
    - Hilo 0: elem 4
    REPARTO MUS
    
    */ 