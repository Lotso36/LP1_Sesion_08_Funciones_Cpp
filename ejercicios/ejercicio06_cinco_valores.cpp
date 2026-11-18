#include "validaciones.h"

int maximo2(int a, int b);
int maximo5(int a, int b, int c, int d, int e);
long long producto5(int a, int b, int c, int d, int e);

int main() {
    try {
        int v1 = leerEntero("Valor 1 (-1000 a 1000): ", -1000, 1000);
        int v2 = leerEntero("Valor 2 (-1000 a 1000): ", -1000, 1000);
        int v3 = leerEntero("Valor 3 (-1000 a 1000): ", -1000, 1000);
        int v4 = leerEntero("Valor 4 (-1000 a 1000): ", -1000, 1000);
        int v5 = leerEntero("Valor 5 (-1000 a 1000): ", -1000, 1000);
        cout << "Valor maximo: " << maximo5(v1, v2, v3, v4, v5) << endl;
        cout << "Producto de los cinco valores: " << producto5(v1, v2, v3, v4, v5) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

int maximo2(int a, int b) { return (a > b) ? a : b; }

int maximo5(int a, int b, int c, int d, int e) {
    return maximo2(maximo2(maximo2(a, b), maximo2(c, d)), e);
}

long long producto5(int a, int b, int c, int d, int e) {
    return 1LL * a * b * c * d * e;  // |producto| <= 10^15
}
