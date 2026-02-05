#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//EJERCICIO 3?

int main(){
    int nElem=100;
    int nIter=10;
    srand(0);
    // version puntero doble
    int ** matriz =(int **)malloc(nElem*sizeof(int*));
    for (int i =0; i<nElem;i++){
    matriz[i]=(int*)malloc(nElem*sizeof(int));
    for (int j =0; j<nElem; j++)
    {
        matriz[i][j]=rand()%100;
    }
}
    // versión puntero sencillo
    int *matriz2 = (int *)malloc(nElem*nElem*sizeof(int));
    int *matriz3= (int*)malloc(nElem*nElem*sizeof(int));
    for (int i =0;i<nElem*nElem;i++){
    matriz2[i]=rand()%100000;
}
    time_t t1 = clock();
    for (int iter =0; iter<nIter;iter++){ // ESTA FUNCION ES TIEMPO
        for (int i=0; i<nElem; i++){
            for (int j=0; j<nElem;j++){
                int temp = 0;
                for (int k =0; k<nElem;k++){
                    temp+= matriz[i][k]*matriz[k][j];
                }
                
            }
        }

}
    time_t t2= clock();
    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total: %g\n", elapsed);
    printf("por elemento: %g\n", elapsed / nIter / nElem);

}