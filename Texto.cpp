//

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream archivo;
    archivo.open("Triangulo.cpp");

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << "Linea leida: " << linea << std::endl;
        }
    } else {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    archivo.close();
    return 0;
}
