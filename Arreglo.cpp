//Realizar un codigo que capture numeros que los ordene en un arreglo y los despliegue en pantalla

#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    const int TAM = 10;
    int numeros[TAM];

    // Captura de 10 números
    cout << "Ingrese 10 numeros:\n";
    for (int i = 0; i < TAM; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Ordenamiento ascendente
    sort(numeros, numeros + TAM);

    // Mostrar arreglo ordenado
    cout << "\nNumeros ordenados en forma ascendente:\n";
    for (int i = 0; i < TAM; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}

