#include "validaciones.h"

double convertirFahrenheit(double celsius);

int main() {
    try {
        double celsius = leerReal("Temperatura en grados Celsius: ", -1000, 100000);
        double fahrenheit = convertirFahrenheit(celsius);
        cout << fixed << setprecision(2);
        cout << celsius << " C equivalen a " << fahrenheit << " F" << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

double convertirFahrenheit(double celsius) {
    if (celsius < -273.15)
        throw domain_error("no existe temperatura menor al cero absoluto (-273.15 C)");
    return celsius * 9.0 / 5.0 + 32.0;
}
