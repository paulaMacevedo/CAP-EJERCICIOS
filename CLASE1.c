// EJERCIO 1
//srand(0);
//srand(time (NULL));
//rand() -> Entorno aleatorio dentro de -RAND_MAX a RAND_MAX
//studi_list <tipo> lista enlazada de elementos tipo
//studi vector <tipo> -> array de lista enlazada de elementos tipo
//aleatorio existe 1 y 10000: rand()%10000 +1;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ====== LISTAS ENLAZADAS ====== */

typedef struct nodo {
    int valor;
    struct nodo *sig;
} nodo;

int versionListas()
{
    srand(0);
    int nElem = 1000000;
    int nIter = 50;

    nodo *lista1 = (nodo*)malloc(sizeof(nodo));
    nodo *lista2 = (nodo*)malloc(sizeof(nodo));
    lista1->valor = rand();
    lista2->valor = rand();

    nodo *actual = lista1;
    for(int i = 1; i < nElem; i++)
    {
        nodo *nuevo = (nodo*)malloc(sizeof(nodo));
        nuevo->valor = rand();
        actual->sig = nuevo;
        actual = nuevo;
    }
    actual->sig = NULL;

    actual = lista2;
    for(int i = 1; i < nElem; i++)
    {
        nodo *nuevo = (nodo*)malloc(sizeof(nodo));
        nuevo->valor = rand();
        actual->sig = nuevo;
        actual = nuevo;
    }
    actual->sig = NULL;

    nodo *lista3;

    clock_t t1 = clock();
    for(int iter = 0; iter < nIter; iter++)
    {
        nodo *suma1 = lista1;
        nodo *suma2 = lista2;

        lista3 = (nodo*)malloc(sizeof(nodo));
        lista3->valor = suma1->valor + suma2->valor;
        nodo *suma3 = lista3;

        for(int i = 1; i < nElem; i++)
        {
            suma1 = suma1->sig;
            suma2 = suma2->sig;

            nodo *nuevo = (nodo*)malloc(sizeof(nodo));
            nuevo->valor = suma1->valor + suma2->valor;
            suma3->sig = nuevo;
            suma3 = nuevo;
        }
        suma3->sig = NULL;
    }
    clock_t t2 = clock();

    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total: %g\n", elapsed);
    printf("por elemento: %g\n", elapsed / nIter / nElem);

    return 0;
}

/* ====== ARRAYS ====== */

int versionArrays()
{
    srand(0);
    int nElem = 1000000;
    int nIter = 180;

    int *array1 = (int*)malloc(nElem * sizeof(int));
    int *array2 = (int*)malloc(nElem * sizeof(int));
    int *array3 = (int*)malloc(nElem * sizeof(int));

    for(int i = 0; i < nElem; i++)
    {
        array1[i] = rand();
        array2[i] = rand();
    }

    clock_t t1 = clock();
    for(int iter = 0; iter < nIter; iter++)
    {
        for(int i = nElem - 1; i >= 0; i--)
        {
            array3[i] = array1[i] + array2[i];
        }
    }
    clock_t t2 = clock();

    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total: %g\n", elapsed);
    printf("por elemento: %g\n", elapsed / nIter / nElem);

    return 0;
}

/* ====== SHORT CAST ====== */

void shortcast()
{
    srand(0);
    int nElem = 1000000;
    int nIter = 180;

    unsigned short *array1 = (unsigned short*)malloc(nElem * sizeof(unsigned short));
    unsigned short *array2 = (unsigned short*)malloc(nElem * sizeof(unsigned short));
    unsigned short *array3 = (unsigned short*)malloc(nElem * sizeof(unsigned short));

    for(int i = 0; i < nElem; i++)
    {
        array1[i] = rand() % 10000;
        array2[i] = rand() % 10000;
    }

    clock_t t1 = clock();
    for(int iter = 0; iter < nIter; iter++)
    {
        unsigned long *c_array1 = (unsigned long*)array1;
        unsigned long *c_array2 = (unsigned long*)array2;
        unsigned long *c_array3 = (unsigned long*)array3;

        for(int i = 0; i < nElem / 4; i++)
        {
            c_array3[i] = c_array1[i] + c_array2[i];
        }
    }
    clock_t t2 = clock();

    double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total: %g\n", elapsed);
    printf("por elemento: %g\n", elapsed / nIter / nElem);
}

/* ====== MAIN ====== */

int main()
{
    shortcast();
    return 0;
}
