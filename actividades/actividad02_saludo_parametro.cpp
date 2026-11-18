#include "validaciones.h"

void saludo(int repeticiones);

int main() {
    try {
        int veces = leerEntero("Cantidad de veces a imprimir el saludo (1-100): ", 1, 100);
        saludo(veces);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void saludo(int repeticiones) {
    if (repeticiones <= 0)
        throw invalid_argument("las repeticiones deben ser positivas");
    for (int conteo = 1; conteo <= repeticiones; conteo++)
        cout << conteo << ". Bienvenidos a Funciones en LP1" << endl;
}
