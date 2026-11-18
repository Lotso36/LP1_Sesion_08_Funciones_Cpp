#include "validaciones.h"

void dibujaTriangulo(int altura, char simbolo);

int main() {
    try {
        int altura = leerEntero("Altura del triangulo (1 - 60): ", 1, 60);
        char simbolo = leerCaracter("Caracter a utilizar: ");
        dibujaTriangulo(altura, simbolo);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void dibujaTriangulo(int altura, char simbolo) {
    if (altura < 1) throw invalid_argument("la altura debe ser positiva");
    for (int fila = 0; fila < altura; fila++)
        cout << string(fila, ' ') << string(altura - fila, simbolo) << endl;
}
