#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int info;
    Nodo* prim;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo* actual ;

    //methods
    //cons
    Nodo(int valor) {
        info = valor;
        siguiente = nullptr; // Inicializamos Siguiente como un puntero nulo
    }

};

#endif // NODO_H
