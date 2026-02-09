#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdexcept>
#include <iostream>
// VERSION 1 DOS COPIAS
std:: vector<double> suma_copias(std:: vector<double> a, std:: vector<double>b){
    // va a devolver un vector con la suma
    for (int i =0; i<a.size();i++){
        a[i]+=b[i];
    }
    return a;
}´
// VERSION 2 USANDO R-VALUES(move) 
std:: vector<double> suma_move(std:: vector<double>&& a,const std:: vector<double> &b){
    // con && indicamos que es temporal y & que solo lee
    for (int i =0; i<a.size(); i++){
        a[i]+= b[i];
    }
    return std:: move(a); // devolver moviendo los datos no copiando
}

// VERSION 3 USANDO TEMPLATES
template <typename L, typename R>
struct VecSum {
    const L& l;
    const R& r;
// no guarda numeros si no referencias a las cosas l y r
    double operator[](size_t i) const {
        return l[i] + r[i];
    }
    // aquí va a la función operator+ que le va a pasar referencia de las listas que vamso a sumar

    size_t size() const {
        return l.size();
    }
};

VecSum<std::vector<double>, std::vector<double>> operator+(const std::vector<double>& a,const std::vector<double>& b) {
    return {a, b};
}
