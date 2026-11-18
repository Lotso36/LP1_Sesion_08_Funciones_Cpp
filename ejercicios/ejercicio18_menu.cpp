#include "validaciones.h"

double areaTrianguloEquilatero(double lado);
double areaRombo(double diagonalMayor, double diagonalMenor);
double volumenCubo(double arista);

int main() {
    try {
        int opcion;
        cout << fixed << setprecision(3);
        do {
            cout << "\n1. Area del triangulo equilatero\n2. Area del rombo\n"
                 << "3. Volumen del cubo\n4. Finalizar" << endl;
            opcion = leerEntero("Seleccione una opcion: ", 1, 4);
            if (opcion == 1) {
                double l = leerReal("Lado: ", 0.01, 100000);
                cout << "Area = " << areaTrianguloEquilatero(l) << endl;
            } else if (opcion == 2) {
                double D = leerReal("Diagonal mayor: ", 0.01, 100000);
                double d = leerReal("Diagonal menor: ", 0.01, 100000);
                cout << "Area = " << areaRombo(D, d) << endl;
            } else if (opcion == 3) {
                double a = leerReal("Arista: ", 0.01, 10000);
                cout << "Volumen = " << volumenCubo(a) << endl;
            }
        } while (opcion != 4);
        cout << "Programa finalizado." << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double areaTrianguloEquilatero(double lado) {
    if (lado <= 0) throw invalid_argument("el lado debe ser positivo");
    return sqrt(3.0) / 4.0 * lado * lado;
}

double areaRombo(double diagonalMayor, double diagonalMenor) {
    if (diagonalMayor <= 0 || diagonalMenor <= 0)
        throw invalid_argument("las diagonales deben ser positivas");
    if (diagonalMenor > diagonalMayor)
        throw invalid_argument("la diagonal menor no puede superar a la mayor");
    return diagonalMayor * diagonalMenor / 2.0;
}

double volumenCubo(double arista) {
    if (arista <= 0) throw invalid_argument("la arista debe ser positiva");
    return arista * arista * arista;
}
