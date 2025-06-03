#include <iostream>
#include <limits>
#include <windows.h> // Para Sleep

using namespace std;

enum Estado {
    PAUSA,
    TIEMPO_CONFIG,
    FUERTE,
    MODERADA,
    LISTO_PARA_INICIAR,
    APAGADO,
    EN_CURSO
};

class Microondas {
private:
    Estado estadoActual;
    int potencia;
    int tiempo;
    bool puertaCerrada;

public:
    Microondas() {
        estadoActual = APAGADO;
        potencia = 0;
        tiempo = 0;
        puertaCerrada = false;
    }

    void mostrarEstado() {
        cout << "\nEstado actual: ";
        switch (estadoActual) {
            case FUERTE: cout << "FUERZA ALTA"; break;
            case MODERADA: cout << "FUERZA MODERADA"; break;
            case TIEMPO_CONFIG: cout << "TIEMPO CONFIGURADO"; break;
            case LISTO_PARA_INICIAR: cout << "LISTO PARA INICIAR"; break;
            case EN_CURSO: cout << "EN CURSO"; break;
            case PAUSA: cout << "PAUSA"; break;
            case APAGADO: cout << "APAGADO"; break;
        }
        cout << (puertaCerrada ? " | Puerta cerrada\n" : " | Puerta abierta\n");
    }

    int leerEntero(string mensaje) {
        int valor;
        while (true) {
            cout << mensaje;
            cin >> valor;
            if (cin.fail()) {
                cout << "Entrada invalida. Intente de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
        }
    }

    char leerChar(string mensaje, string opcionesValidas) {
        char c;
        while (true) {
            cout << mensaje;
            cin >> c;
            c = tolower(c);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (opcionesValidas.find(c) != string::npos) {
                return c;
            } else {
                cout << "Opcion invalida. Intente otra vez.\n";
            }
        }
    }

    void seleccionarPotencia() {
        int opcion = leerEntero("\nSeleccione el nivel de potencia:\n1. FUERTE (600W)\n2. MODERADA (300W)\nOpcion: ");
        if (opcion == 1) {
            potencia = 600;
            estadoActual = FUERTE;
            cout << "Potencia FUERTE seleccionada.\n";
        } else if (opcion == 2) {
            potencia = 300;
            estadoActual = MODERADA;
            cout << "Potencia MODERADA seleccionada.\n";
        } else {
            cout << "Opcion no valida. Reinciando...\n";
            reiniciar();
        }
    }

    void configurarTiempo() {
        tiempo = leerEntero("Ingrese el tiempo en segundos: ");
        if (tiempo <= 0) {
            cout << "Tiempo invalido. Reinciando...\n";
            reiniciar();
        } else {
            estadoActual = TIEMPO_CONFIG;
            cout << "Tiempo configurado: " << tiempo << " segundos.\n";
        }
    }

    bool comprobarPuerta() {
        char estado = leerChar("¿Está la puerta cerrada? (s = si / n = no): ", "sn");
        if (estado == 's') {
            puertaCerrada = true;
            estadoActual = LISTO_PARA_INICIAR;
            cout << "Puerta cerrada. Preparando el ciclo...\n";
            return true;
        } else {
            cout << "Puerta abierta. Reiniciando...\n";
            puertaCerrada = false;
            estadoActual = APAGADO;
            return false;
        }
    }

    void iniciarOperacion() {
        if (potencia > 0 && tiempo > 0 && puertaCerrada) {
            estadoActual = EN_CURSO;
            int tiempoRestante = tiempo;
            mostrarEstado();

            while (tiempoRestante > 0) {
                cout << "Funcionando... " << tiempoRestante << "s restantes\n";
                Sleep(1000);
                tiempoRestante--;

                char abrir = leerChar("¿Desea abrir la puerta? (s = si / n = no): ", "sn");
                if (abrir == 's') {
                    puertaCerrada = false;
                    cout << "Puerta abierta. Ciclo pausado.\n";

                    char cerrar = leerChar("Cerrar puerta para reiniciar desde el comienzo (s): ", "s");
                    if (cerrar == 's') {
                        puertaCerrada = true;
                        cout << "Puerta cerrada. Reiniciando ciclo...\n";
                        return;
                    }
                }
            }

            finalizar();
        } else {
            cout << "No se puede iniciar. Datos incompletos.\n";
        }
    }

    void finalizar() {
        cout << "\nCiclo terminado. ¡LISTO!\n";
        estadoActual = PAUSA;
        mostrarEstado();
    }

    void reiniciar() {
        potencia = 0;
        tiempo = 0;
        puertaCerrada = false;
        estadoActual = APAGADO;
        mostrarEstado();
    }

    void ejecutar() {
        while (true) {
            reiniciar();
            seleccionarPotencia();
            configurarTiempo();
            if (comprobarPuerta()) {
                iniciarOperacion();
            }
        }
    }
};

int main() {
    Microondas m;
    m.ejecutar();
    return 0;
}
