#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class BigSquaredMatrix {

private:
    std::vector<int> datos; // matriz almacenada como vector 1D
    int ancho;              // número de filas = columnas

public:

    /* ================= CONSTRUCTORES ================= */

    // Constructor básico: reserva memoria
    BigSquaredMatrix(int ancho) : ancho(ancho), datos(ancho * ancho) {}

    // Constructor que rellena con valores aleatorios [0, max]
    BigSquaredMatrix(int ancho, int max) : ancho(ancho), datos(ancho * ancho) {
        for (int i = 0; i < ancho * ancho; i++) {
            datos[i] = rand() % (max + 1);
        }
    }

    // Constructor copia (deep copy)
    BigSquaredMatrix(const BigSquaredMatrix& m)
        : ancho(m.ancho), datos(m.datos) {}

    // Constructor move (se roba la memoria)
    BigSquaredMatrix(BigSquaredMatrix&& m) noexcept
        : ancho(m.ancho), datos(std::move(m.datos)) {}

    /* ================= ASIGNACIONES ================= */

    // Copy assignment
    BigSquaredMatrix& operator=(const BigSquaredMatrix& m) {
        if (this != &m) {
            ancho = m.ancho;
            datos = m.datos;
        }
        return *this;
    }

    // Move assignment
    BigSquaredMatrix& operator=(BigSquaredMatrix&& m) noexcept {
        if (this != &m) {
            ancho = m.ancho;
            datos = std::move(m.datos);
        }
        return *this;
    }

    /* ================= ACCESO A DATOS ================= */

    // Modificar un elemento (fila, columna)
    void modificar(int fila, int col, int valor) {
        datos[fila * ancho + col] = valor;
    }

    // Acceso a una fila (NO const)
    int* operator[](int fila) {
#ifdef DEBUG
        if (fila >= ancho) {
            throw std::out_of_range("Fila fuera de rango");
        }
#endif
        return datos.data() + fila * ancho;
    }

    // Acceso a una fila (const)
    const int* operator[](int fila) const {
#ifdef DEBUG
        if (fila >= ancho) {
            throw std::out_of_range("Fila fuera de rango");
        }
#endif
        return datos.data() + fila * ancho;
    }

    /* ================= OPERADORES ================= */

    // Suma y asignación
    BigSquaredMatrix& operator+=(const BigSquaredMatrix& m) {
        for (int i = 0; i < ancho * ancho; i++) {
            datos[i] += m.datos[i];
        }
        return *this;
    }

    // Suma normal (lvalue)
    BigSquaredMatrix operator+(const BigSquaredMatrix& m) const {
        BigSquaredMatrix resultado(*this);
        resultado += m;
        return resultado;
    }

    // Suma optimizada para rvalues
    BigSquaredMatrix operator+(const BigSquaredMatrix& m) && {
        *this += m;
        return std::move(*this);
    }
};
int main() {
    srand(time(NULL));

    BigSquaredMatrix m(1000, 1000);
    BigSquaredMatrix m2 = m + m;      // usa copy
    BigSquaredMatrix m3(m);           // constructor copia
    BigSquaredMatrix m4(m + m);       // constructor move

    m[3][7] = 14;
    int x = m[3][7];

    return 0;
}