#include <iostream>

using namespace std;

int main() {
    double base, altura, area;

    
    cout << "Ingrese la base del triangulo: ";
    cin >> base;
    cout << "Ingrese la altura del triangulo: ";
    cin >> altura;

    // Calcular el área
    area = (base * altura) / 2;


    cout << "El area del triangulo es: " << area << endl;

    return 0;
}

