#include "validaciones.h"

const double PI = 3.14159265358979323846;

double calculaPerimetro(double radio);
double calculaArea(double radio);

int main() {
    try {
        cout << "1. Ingresar radio\n2. Ingresar diametro" << endl;
        int opcion = leerEntero("Opcion: ", 1, 2);
        double medida = leerReal("Valor de la medida (0.01 - 100000): ", 0.01, 100000);
        double radio = (opcion == 1) ? medida : medida / 2;
        cout << fixed << setprecision(3);
        cout << "Radio     = " << radio << endl;
        cout << "Perimetro = " << calculaPerimetro(radio) << endl;
        cout << "Area      = " << calculaArea(radio) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double calculaPerimetro(double radio) {
    if (radio <= 0) throw invalid_argument("el radio debe ser positivo");
    return 2 * PI * radio;
}

double calculaArea(double radio) {
    if (radio <= 0) throw invalid_argument("el radio debe ser positivo");
    return PI * radio * radio;
}
