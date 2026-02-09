#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desarrollamos el constructor en c++, 
class nodo{
    public:
    int valor;
     nodo *Siguiente;
     nodo (int Nvalor){
        valor=Nvalor;
        Siguiente=NULL;
     }
};

// rellenar
int versionArray(){
  srand(0);
  int nElem=1000000;
  int nIter=180;

  // creamos los arrays (3 maneras distintas de declararlos podemos usar con el que estemos más cómodos)
  int *array1 = new int [nElem]; // reserva memoria para nElementos enteros
  int *array2 = (int*)malloc(nElem *sizeof(int));
  int *array3 = new int [nElem];

  // rellenamos los dos arrays con valores aleatorios
  for (int i =0; i<nElem;i++){
    array1[i]=rand();
    array2[i]=rand();
  }
  // ahora inicializamos el tiempo
  time_t t1 = clock();
for(int i = 0; i < nIter; i++){
    // vamos a realziar la suma de dos elementos
    for (int i =0; i<nElem; i++){
        array3[i]=array1[i]+array2[i];
    }
}
time_t t2 = clock();
double elapsed = (t2 - t1) / CLOCKS_PER_SEC;
printf("total: %g\n", elapsed);
	printf("por elemento: %g\n", elapsed/nIter/nElem);
	return 0;
}
int shortcats(){
    // esta función lo que va a hacer es en vez de sumar numeros de 1 en 1 va a ir sumandolos de 4 en 4
    srand(0);
    int nElemen =10000;
    int nIter =180;
    // vamosa a crear los distintos arrays de 16 bits que van a facilitar esta tarea
    // distintas formas de declararlo
    unsigned short *array1 = new unsigned short[nElemen];
    unsigned short *array2 = (unsigned short*)malloc(nElemen *sizeof(unsigned short));
    unsigned short *array3 = new unsigned short [nElemen];
    // los rellenamos de forma aletoria
    for (int i =0; i<nElemen; i++){
        array1[i]= rand()%1000;
        array2[i]= rand()%1000;
    }
    // como vamos a sumarlo ya, procedemos a inicializar el tiempo
    time_t t1 = clock();
    for (int i =0; i<nIter; i++){
        // creamos los arrays de lectura de 8 en 8
        unsigned long *c_array1 = (unsigned long *)array1;
        unsigned long *c_array2 = (unsigned long *)array2;
        // es un vector
        unsigned long *c_array3 = (unsigned long *)array3.data();
        // realizamos la suma
        for (int i =0;i<nElemen/4; i++){
            c_array3[i]= c_array1[i]+c_array2[i];
        }

    }
    time_t t2 = clock();
	double elapsed = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("total: %g\n", elapsed);
	printf("por elemento: %g\n", elapsed/nIter/nElem);

}
int main(){
    shortcats();
}