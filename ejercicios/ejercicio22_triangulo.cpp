#include "validaciones.h"

double mayorLado(double a, double b, double c);
string clasificarTriangulo(double a, double b, double c);

int main() {
    try {
        double a = leerReal("Lado a: ", 0.01, 100000);
        double b = leerReal("Lado b: ", 0.01, 100000);
        double c = leerReal("Lado c: ", 0.01, 100000);
        cout << clasificarTriangulo(a, b, c) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double mayorLado(double a, double b, double c) {
    double m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

string clasificarTriangulo(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) throw invalid_argument("los lados deben ser positivos");
    double mayor = mayorLado(a, b, c);
    if ((a + b + c) - mayor <= mayor)
        return "No es un triangulo: no cumple la desigualdad triangular.";
    double cuadMayor = mayor * mayor;
    double cuadOtros = a * a + b * b + c * c - cuadMayor;
    if (fabs(cuadMayor - cuadOtros) <= 1e-9 * cuadMayor) return "Es un triangulo rectangulo.";
    if (cuadMayor < cuadOtros) return "Es un triangulo acutangulo.";
    return "Es un triangulo obtusangulo.";
}
