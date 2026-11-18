#include "validaciones.h"

void clasificarCaracter(char c);

int main() {
    try {
        char c = leerCaracter("Ingrese un caracter: ");
        clasificarCaracter(c);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

void clasificarCaracter(char c) {
    char minuscula = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    if (!isalpha(static_cast<unsigned char>(c)))
        cout << "'" << c << "' es otro tipo de caracter (no es una letra)." << endl;
    else if (minuscula == 'a' || minuscula == 'e' || minuscula == 'i' ||
             minuscula == 'o' || minuscula == 'u')
        cout << "'" << c << "' es una vocal." << endl;
    else
        cout << "'" << c << "' es una consonante." << endl;
}
