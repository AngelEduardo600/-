#include <iostream>
using namespace std;

class Animal {
public:
    string nombre;
    int edad;
    string 
    
    
    Animal(string n, int e) : nombre(n), edad(e) {}

    void comer() {
        cout << nombre << " esta comiendo." << endl;
    }

    void dormir() {
        cout << nombre << " esta durmiendo." << endl;
    }

    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " anos" << endl;
    }
};

class Vertebrado : public Animal {
public:
    Vertebrado(string n, int e) : Animal(n, e) {}

    void tipoAnimal() {
        cout << nombre << " es un vertebrado." << endl;
    }
};

class Invertebrado : public Animal {
public:
    Invertebrado(string n, int e) : Animal(n, e) {}

    void tipoAnimal() {
        cout << nombre << " es un invertebrado." << endl;
    }
};

int main() {
    Vertebrado perro("Perro", 5);
    Invertebrado arana("Arana", 1);
    Vertebrado gato("Gato", 2);

    perro.mostrarInfo();
    perro.tipoAnimal();
    perro.comer();
    perro.dormir();

    cout << endl;

    arana.mostrarInfo();
    arana.tipoAnimal();
    arana.comer();
    arana.dormir();
    
    cout <<endl;
    
    gato.mostrarInfo();
    gato.tipoAnimal();
    gato.comer();
    gato.dormir();

    return 0;
}

