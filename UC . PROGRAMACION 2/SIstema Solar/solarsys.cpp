#include <iostream>
#include <string>
#include <vector>  // para guardar los planetas en un vector
#include <limits> // Necesario para numeric_limits

using namespace std;

class Planeta {
private:
    string planetName;
    float distance;
    float radio;
    int masa;

public:
    // Constructor (inicializa los atributos al crear el objeto)
    Planeta(string planetName, float distance, float radio, int masa);

    // Métodos
    void createPlanet() const;

    // Getters (const porque no modifican los atributos)
    string getName() const;
    float getDistance() const;
    float getRadio() const;
    int getMasa() const;

    // Setters (para modificar los atributos si es necesario)
    void setName(string planetName);
    void setDistance(float distance);
    void setRadio(float radio);
    void setMasa(int masa);

    //comparaciones
    float planetaMasGrande() const;
};

// Definiciones de las funciones miembro fuera de la clase Planeta
Planeta::Planeta(string planetName, float distance, float radio, int masa) :
    planetName(planetName), distance(distance), radio(radio), masa(masa) {}

void Planeta::createPlanet() const {
    cout << "Nombre: " << planetName << endl;
    cout << "Distancia: " << distance << endl;
    cout << "Radio: " << radio << endl;
    cout << "Masa: " << masa << endl;
}

string Planeta::getName() const { return planetName; }
float Planeta::getDistance() const { return distance; }
float Planeta::getRadio() const { return radio; }
int Planeta::getMasa() const { return masa; }

void Planeta::setName(string planetName) { this->planetName = planetName; }
void Planeta::setDistance(float distance) { this->distance = distance; }
void Planeta::setRadio(float radio) { this->radio = radio; }
void Planeta::setMasa(int masa) { this->masa = masa; }

float Planeta::planetaMasGrande() const {
    return radio; // Devuelve el radio del planeta actual
}

class SolarSystem {
private:
    vector<Planeta> planetas;

public:
    void addPlaneta(const Planeta& planeta);
    void mostrarPlanetas() const;
    Planeta* buscarPlanetaMasGrande() const;
};

void SolarSystem::addPlaneta(const Planeta& planeta) {
    planetas.push_back(planeta);
}

void SolarSystem::mostrarPlanetas() const {
    for (const auto& planeta : planetas) {
        planeta.createPlanet();
        cout << endl;
    }
}

Planeta* SolarSystem::buscarPlanetaMasGrande() const {
    if (planetas.empty()) {
        return nullptr; // No hay planetas en el sistema solar
    }

    Planeta* planetaMasGrande = nullptr;
    float radioMaximo = numeric_limits<float>::lowest(); // Inicializar con el valor más pequeño posible

    for (Planeta& planeta : planetas) { // Usar referencia para evitar copias innecesarias
        if (planeta.getRadio() > radioMaximo) {
            radioMaximo = planeta.getRadio();
            planetaMasGrande = &planeta; // Guardar la dirección del planeta
        }
    }

    return planetaMasGrande;
}

int main() {
    Planeta tierra("Tierra", 149.6, 6371, 5.97);
    Planeta marte("Marte", 227.9, 3389.5, 0.642);
    Planeta jupiter("Jupiter", 778.3, 69911, 1898); // Un planeta más grande

    SolarSystem sistemaSolar;

    sistemaSolar.addPlaneta(tierra);
    sistemaSolar.addPlaneta(marte);
    sistemaSolar.addPlaneta(jupiter);

    sistemaSolar.mostrarPlanetas();

    Planeta* planetaGrande = sistemaSolar.buscarPlanetaMasGrande();

    if (planetaGrande != nullptr) {
        cout << "\nEl planeta más grande es: " << planetaGrande->getName() << endl;
    } else {
        cout << "\nNo hay planetas en el sistema solar." << endl;
    }

    return 0;
}


