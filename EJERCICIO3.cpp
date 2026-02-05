#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int V1(){
    srand(0);
    int nElemen=1000;
    int nIter=10000;

    //ahora procedemos a realizar la declaración de las distintas matrices
    /// COMENZAMOS CON LA VERSION 1 DE INT ** -> CON ESTA VAMOS A PODER ACCEDER A LA MATRIZ DE FORMA INDEPENDIENTE[][]
    int **A = (int **)malloc(nElemen *sizeof(int *));
    // cada puntero va a apuntar a un array de NENTEROs
    for (int i =0; i<nElemen;i++){
        // hemos generado las filas y con esto generamos las columnas
        A[i]= (int *)malloc(nElemen *sizeof (int));
    }
    // rellenar con numeros aleatorios
    for (int i =0; i< nElemen;i++ ){
        for (int j=0; j<nElemen;j++){
            A[i][j]= rand() %100;
        }
    }

    // ahora vamos a tener que generar la matriz qie va a guardar el resultado
    int **R1 = (int **)malloc(nElemen *sizeof(int*));
    // generamos las columnas
    for (int i =0; i<nElemen; i++){
        R1[i]= (int *)malloc(nElemen *sizeof (int));
    }

    clock_t t1 = clock();
    // ahora realizamos la multiplicación de las dos matrices
    for (int i =0; i<nElemen; i++){
        for (int j =0; j<nElemen; j++){
            int suma=0;
            for (int k =0; k<nElemen;k++){
                suma += (int) A[i][k] * A [k][j];
            }
            R1[i][j]= (int)suma;
        }
    }
    clock_t t2 = clock();
    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Tiempo int**: %f s\n", elapsed);

    // LIBERAMOS MEMORIA
    for (int i = 0; i < nElemen; i++) free(A[i]);
    free(A);

    for (int i = 0; i < nElemen; i++) free(R1[i]);
    free(R1);

}
int v2(){
       srand(0);
    int nElemen=1000;
    int nIter=10000;
    // VERSION INT *

    // comenzamos reservando memoria para la matriz principal
    // con el nElement *nElement declaramos las filas y las columnas
    int *A = (int *)malloc(nElemen *nElemen *sizeof(int));
    // rellenamos la matriz de forma aleatoria
    for (int i =0; i<nElemen;i++){
        for (int j=0; j<nElemen; j++){
            A[i*nElemen +j]= rand()%100;
            // i* nElemento saltas al comienzo de la fila i y con j te deplazadas hasta la columna deseada
        }
    }
    // generamos la matriz donde vamos a guardar el resultado
    int *R = (int *)malloc(nElemen *nElemen * sizeof(int));

    // procedemos a multiplicar
    clock_t t1 = clock();
    // ahora realizamos la multiplicación de las dos matrices
    for (int i =0; i<nElemen; i++){
        for (int j =0; j<nElemen; j++){
            int suma=0;
            for (int k =0; k<nElemen;k++){
                suma += (int) A[i*nElemen +k] * A [k *nElemen + j];
            }
            R[i*nElemen + j]= (int)suma;
        }
    }
    clock_t t2 = clock();
    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Tiempo int**: %f s\n", elapsed);
}

int v3(){
    // version int * y gurando copia traspuestan antes de multiplicar
         srand(0);
    int nElemen=1000;
    int nIter=10000;
    // VERSION INT * con copia

    // comenzamos reservando memoria para la matriz principal
    // con el nElement *nElement declaramos las filas y las columnas
    int *A = (int *)malloc(nElemen *nElemen *sizeof(int));
    // rellenamos la matriz de forma aleatoria
    int *C = (int *) malloc(nElemen *nElemen *sizeof(int));

    for (int i =0; i<nElemen;i++){
        for (int j=0; j<nElemen; j++){
            A[i*nElemen +j]= rand()%100;
            // i* nElemento saltas al comienzo de la fila i y con j te deplazadas hasta la columna deseada
        }
    }
    // ahora vamos a guardar la copia traspuesta
    for (int i =0; i<nElemen; i++){
        for (int j =0; j<nElemen; j++){
            C[j*nElemen +i]= A[i*nElemen +j];
        }
    }
    // generamos la matriz donde vamos a guardar el resultado
    int *R = (int *)malloc(nElemen *nElemen * sizeof(int));

    // procedemos a multiplicar
    clock_t t1 = clock();
    // ahora realizamos la multiplicación de las dos matrices
    for (int i =0; i<nElemen; i++){
        for (int j =0; j<nElemen; j++){
            int suma=0;
    
            for (int k =0; k<nElemen;k++){
                suma += (int) A[i*nElemen +k] * C [j *nElemen + k];
            }
            R[i*nElemen + j]= (int)suma;
        }
    }
    clock_t t2 = clock();
    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Tiempo int**: %f s\n", elapsed);
}