//Definir la clase deporte con tres atributos que se jugan con balon y
// definir las clases derivadas dependiendo con que parte del cuerpo se puede tocar el balon 

#include <iostream>
#include <string>
using namespace std;

// Clase base
class Deporte {
public:
    string nombre;
    int jugadores;
    string cancha;       
    

    // Constructor
    Deporte(string n, int j, string c) : nombre(n), jugadores(j), cancha(c) {}

    // Método para mostrar información general
    virtual void mostrarInfo() {
        cout << "Nombre del deporte: " << nombre << endl;
        cout << "Cantidad de jugadores: " << jugadores << endl;
        cout << "Tipo de cancha: " << cancha << endl;
    }

    // Método virtual para saber con qué parte del cuerpo se juega
    virtual void parteDelCuerpo() = 0;  // Método abstracto
};

// Clase derivada para deportes que se juegan con los pies
class DeporteConPies : public Deporte {
public:
    DeporteConPies(string n, int j, string c) : Deporte(n, j, c) {}

    void parteDelCuerpo() override {
        cout << "Este deporte se juega principalmente con los pies." << endl;
    }
};

// Clase derivada para deportes que se juegan con las manos
class DeporteConManos : public Deporte {
public:
    DeporteConManos(string n, int j, string c) : Deporte(n, j, c) {}

    void parteDelCuerpo() override {
        cout << "Este deporte se juega principalmente con las manos." << endl;
    }
};

// Clase derivada para deportes que se juegan con todo el cuerpo
class DeporteConTodoElCuerpo : public Deporte {
public:
    DeporteConTodoElCuerpo(string n, int j, string c) : Deporte(n, j, c) {}

    void parteDelCuerpo() override {
        cout << "Este deporte se juega con todo el cuerpo." << endl;
    }
};

// Ejemplo de uso
int main() {
    DeporteConPies futbol("Futbol", 11, "Cancha de cesped");
    DeporteConManos Tenis("Tenis", 2, "Cancha cubierta");
    DeporteConTodoElCuerpo rugby("Rugby", 15, "Campo de pasto");

    futbol.mostrarInfo();
    futbol.parteDelCuerpo();

    cout << endl;

    Tenis.mostrarInfo();
    Tenis.parteDelCuerpo();

    cout << endl;

    rugby.mostrarInfo();
    rugby.parteDelCuerpo();

    return 0;
}

	
	
	
	
	
	








