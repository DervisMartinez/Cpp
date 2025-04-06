#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <stdexcept>
#include "nodo.hpp"

template <typename T>
class Cola {
private:
    Node<T>* frente;  // Puntero al primer elemento de la cola
    Node<T>* final;   // Puntero al último elemento de la cola
    int longitud;     // Cantidad de elementos en la cola

public:
    // Constructor
    Cola() : frente(nullptr), final(nullptr), longitud(0) {}  // O(1)

    // Destructor (~ indica un destructor dentro de la clase )
    ~Cola();

    // Métodos básicos de la cola
    void construir(Cola<T>& cola);    // Construye una cola vacía
    void encolar(const T& dato);      // Inserta un elemento al final de la cola
    T desencolar();                   // Elimina y devuelve el primer elemento de la cola
    T obtenerFrente() const;          // Devuelve el primer elemento sin eliminarlo
    bool esVacia() const;             // Verifica si la cola está vacía
    int getLongitud() const;          // Retorna la longitud de la cola
    void destruir();                  // Vacía la cola
    void mostrar() const;             // Imprime los elementos de la cola

    //getters 
    int getLongitud() const;          // Obtiene la LOngitud de la Cola 
    //setters
};

// Implementación del Destructor
template <typename T>
Cola<T>::~Cola() {
    destruir();
}

// Método para construir la cola
template <typename T>
void Cola<T>::construir(Cola<T>& cola) {
    cola.frente = nullptr;
    cola.final = nullptr;
    cola.longitud = 0;
}

// Método para insertar un elemento al final de la cola (Encolar)
template <typename T>
void Cola<T>::encolar(const T& dato) {
    Node<T>* nuevoNodo = new Node<T>(dato);
    if (esVacia()) {
        frente = final = nuevoNodo;  // Si está vacía, frente y final apuntan al nuevo nodo
    } else {
        final->siguiente = nuevoNodo;  // Enlaza el último nodo con el nuevo
        final = nuevoNodo;             // Actualiza el puntero final
    }
    longitud++;
}

// Método para eliminar y devolver el primer elemento de la cola (Desencolar)
template <typename T>
T Cola<T>::desencolar() {
    if (esVacia()) {
        throw std::out_of_range("Error: La cola está vacía.");
    }

    Nodo<T>* temp = frente;
    T valor = temp->info;
    frente = frente->siguiente;
    delete temp;

    if (frente == nullptr) {
        final = nullptr;  // Si la cola queda vacía, también actualiza el puntero final
    }

    longitud--;
    return valor;
}

// Método para obtener el primer elemento de la cola sin eliminarlo
template <typename T>
T Cola<T>::obtenerFrente() const {
    if (esVacia()) {
        throw std::out_of_range("Error: La cola está vacía.");
    }
    return frente->info;
}

// Método para verificar si la cola está vacía
template <typename T>
bool Cola<T>::esVacia() const {
    return frente == nullptr;
}

// Método para obtener la longitud de la cola
template <typename T>
int Cola<T>::getLongitud() const {
    return longitud;
}

// Método para destruir (vaciar) la cola
template <typename T>
void Cola<T>::destruir() {
    while (!esVacia()) {
        desencolar();
    }
}

// Método para mostrar los elementos de la cola
template <typename T>
void Cola<T>::mostrar() const {
    Nodo<T>* actual = frente;
    while (actual != nullptr) {
        std::cout << actual->info << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "NULL" << std::endl;
}
// getters
template <typename  T>
int Cola<T> :: getLongitud() const {
    return longitud ;
};

#endif // COLA_H

