// IMAGEN de S1 S2 S3 S4
 #include <iostream>
using namespace std;

int main() {
    string cadena;
    int estado = 1; // Estado S1

    cout << "Ingresa una cadena: ";
    cin >> cadena;

    for (int i = 0; i < cadena.length(); i++) {
        char simbolo = cadena[i];

        // Transiciones
        if (estado == 1) {
            if (simbolo == 'a') estado = 2;
        
        }
        else if (estado == 2) {
            if (simbolo == 'a') estado = 2;
            else if (simbolo == 'b') estado = 1;
            else if (simbolo == 'c') estado = 4;
        }
        else if (estado == 4) {
            if (simbolo == 'd') estado = 3;
            else if (simbolo == 'b') estado = 4;
        }
        else if (estado == 3) {
            if (simbolo == 'a') estado = 1;
            else if (simbolo == 'b') estado = 4;
        }
    }

    cout << "Estado final: S" << estado << endl;

    return 0;
}


