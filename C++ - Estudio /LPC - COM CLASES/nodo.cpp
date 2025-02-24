#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};



#endif // NODO_H
