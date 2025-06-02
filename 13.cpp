#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double depositoMensual = 1000.0;
    double tasaMensual = 0.03;
    int anios = 10;
    int meses = anios * 12;

    double montoTotal = 0.0;

    for (int i = 1; i <= meses; i++) {
        montoTotal += depositoMensual;
        montoTotal *= (1 + tasaMensual);
    }

    cout.precision(2);
    cout << fixed;
    cout << "Monto total ahorrado despues de " << anios << " anios: $" << montoTotal << endl;

    return 0;
}

