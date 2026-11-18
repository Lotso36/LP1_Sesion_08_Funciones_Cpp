#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <sstream>
#include <iomanip>
using namespace std;

// Da formato fijo (2 decimales) a un real para los mensajes
inline string formato(double valor) {
    ostringstream salida;
    salida << fixed << setprecision(2) << valor;
    return salida.str();
}

// Lee una linea completa; lanza excepcion si se cierra la entrada
inline string leerLinea(const string& mensaje) {
    cout << mensaje;
    string linea;
    if (!getline(cin, linea))
        throw runtime_error("Se cerro la entrada de datos.");
    return linea;
}

// Lee un entero en [minimo, maximo]; repite hasta que sea valido
inline long long leerEntero(const string& mensaje, long long minimo, long long maximo) {
    while (true) {
        string texto = leerLinea(mensaje);
        try {
            size_t usados = 0;
            long long valor = stoll(texto, &usados);
            if (texto.find_first_not_of(" \t", usados) != string::npos)
                throw invalid_argument("sobran caracteres");
            if (valor < minimo || valor > maximo)
                throw out_of_range("fuera de rango");
            return valor;
        } catch (const out_of_range&) {
            cout << "  Error: ingrese un entero entre " << minimo
                 << " y " << maximo << "." << endl;
        } catch (const invalid_argument&) {
            cout << "  Error: el dato no es un numero entero valido." << endl;
        }
    }
}

// Lee un real finito en [minimo, maximo]; acepta coma o punto decimal
inline double leerReal(const string& mensaje, double minimo, double maximo) {
    while (true) {
        string texto = leerLinea(mensaje);
        for (size_t i = 0; i < texto.size(); i++)
            if (texto[i] == ',') texto[i] = '.';
        try {
            size_t usados = 0;
            double valor = stod(texto, &usados);
            if (texto.find_first_not_of(" \t", usados) != string::npos || !isfinite(valor))
                throw invalid_argument("dato no valido");
            if (valor < minimo || valor > maximo)
                throw out_of_range("fuera de rango");
            return valor;
        } catch (const out_of_range&) {
            cout << "  Error: ingrese un numero entre " << formato(minimo)
                 << " y " << formato(maximo) << "." << endl;
        } catch (const invalid_argument&) {
            cout << "  Error: el dato no es un numero valido." << endl;
        }
    }
}

// Lee exactamente un caracter visible (sin espacios)
inline char leerCaracter(const string& mensaje) {
    while (true) {
        string texto = leerLinea(mensaje);
        if (texto.size() == 1 && isgraph(static_cast<unsigned char>(texto[0])))
            return texto[0];
        cout << "  Error: escriba un unico caracter visible (ASCII)." << endl;
    }
}

#endif
