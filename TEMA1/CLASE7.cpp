// hacer la varianza en para un vector en paralelo
double varianza(std:: vector<double> datos){
    const int tam = datos.size();
    int media =0;
    #pragma omp parallel{ // PARARLEL LO QUE HACE ES CREAR HILOS
        double mediaLocal= 0;
    
        int tid = omp_getThreadNum();
        int nt = omp_getMaxNumTheads();
        for (int i =0; i<tam;i++){
            mediaLocal += datos[i];
        }
        #pragma omp critical
        media += mediaLocal;
        #pragma omp single // single es para que solo lo realice una operaicion
        media = media/tam

        double varLocal=0;
        for(int i=tid; i< tam; i+=nt){
            varLocal += (media -datos[i])*(media - datos[i]);
        }
        #pragma omp Critical
            var += varLocal;

    }
    return var;
}

/*
1. Variable local para todos los hilos
2. barrera
3. me he perdido?
*/

/*
VERSION CORREGIDA
#include <vector>
#include <omp.h>

double varianza(std::vector<double> datos) {

    int tam = datos.size();
    double suma = 0.0;

    // 1️⃣ Calcular la media
    #pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < tam; i++) {
        suma += datos[i];
    }

    double media = suma / tam;

    // 2️⃣ Calcular la varianza
    double var = 0.0;

    #pragma omp parallel for reduction(+:var)
    for (int i = 0; i < tam; i++) {
        var += (datos[i] - media) * (datos[i] - media);
    }

    return var / tam;  // varianza poblacional
}

*/

// PUNTO MEDIO CENTROIDE-> CAE EN EXAMEN
struct point3D{
    double coords[3];
};

point3D centroide (std:: vector<point3D> puntos){
    
    int tam = puntos.size();

    double sumaX = 0.0;
    double sumaY = 0.0;
    double sumaZ = 0.0;

    #pragma omp parallel for reduction(+:sumaX,sumaY,sumaZ)
    for(int i = 0; i < tam; i++){
        sumaX += puntos[i].coords[0];
        sumaY += puntos[i].coords[1];
        sumaZ += puntos[i].coords[2];
    }

    point3D resultado;

    resultado.coords[0] = sumaX / tam;
    resultado.coords[1] = sumaY / tam;
    resultado.coords[2] = sumaZ / tam;

    return resultado;
}