#include <iostream>
#include <string>

using namespace std;

class activo {
    // atributos
    private:
    string name;
    float price;

    // metodos
    public:
    void construir() {}
    
    void construir(string name, float price); // Solo declaración
    
    // getters
    string getName() { return name; }
    float getPrice() { return price; }
    
    // setters
    void setName(string name) {
        this->name = name;
    }
    
    void setPrice(float price) {
        this->price = price;
    }
};

//  método construir
void activo::construir(string name, float price) {
    this->name = name ;
    this->price = price;
}

string activo::getName(){
    return name;
}

float activo ::getPrice(){
   return price ; 
}

