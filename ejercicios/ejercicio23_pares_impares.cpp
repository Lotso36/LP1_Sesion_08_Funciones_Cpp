#include "validaciones.h"

long long sumaPares(int inicio, int fin);
long long sumaImpares(int inicio, int fin);

int main() {
    try {
        int inicio = leerEntero("Inicio del rango: ", -100000, 100000);
        int fin = leerEntero("Fin del rango (>= inicio): ", inicio, 100000);
        cout << "Rango [" << inicio << ", " << fin << "]" << endl;
        cout << "Suma de pares   = " << sumaPares(inicio, fin) << endl;
        cout << "Suma de impares = " << sumaImpares(inicio, fin) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long sumaPares(int inicio, int fin) {
    if (inicio > fin) throw invalid_argument("el rango es invalido (inicio > fin)");
    long long suma = 0;
    for (int i = inicio; i <= fin; i++)
        if (i % 2 == 0) suma += i;
    return suma;
}

long long sumaImpares(int inicio, int fin) {
    if (inicio > fin) throw invalid_argument("el rango es invalido (inicio > fin)");
    long long suma = 0;
    for (int i = inicio; i <= fin; i++)
        if (i % 2 != 0) suma += i;        // != 0 tambien cubre impares negativos
    return suma;
}
