#include "validaciones.h"

void mostrarFibonacci(int n);

int main() {
    try {
        int n = leerEntero("Cantidad de terminos n (1 - 90): ", 1, 90);
        mostrarFibonacci(n);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void mostrarFibonacci(int n) {
    if (n < 1 || n > 90) throw out_of_range("n debe estar entre 1 y 90");
    unsigned long long anterior = 0, actual = 1;
    cout << "Serie de Fibonacci con " << n << " terminos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << anterior << (i < n - 1 ? ", " : "\n");
        unsigned long long siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }
}
