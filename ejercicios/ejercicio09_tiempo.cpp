#include "validaciones.h"

long long obtenerHoras(long long total);
int obtenerMinutos(long long total);
int obtenerSegundos(long long total);

int main() {
    try {
        long long total = leerEntero("Cantidad total de segundos: ", 0, 2000000000LL);
        cout << total << " s equivalen a " << obtenerHoras(total) << " h "
             << obtenerMinutos(total) << " min " << obtenerSegundos(total) << " s" << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

long long obtenerHoras(long long total) {
    if (total < 0) throw invalid_argument("los segundos no pueden ser negativos");
    return total / 3600;
}

int obtenerMinutos(long long total) { return static_cast<int>((total % 3600) / 60); }

int obtenerSegundos(long long total) { return static_cast<int>(total % 60); }
