#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept>
#include "nodo.hpp"

template <typename T>
class Pila {
private:
    Node<T>* tope;  // Puntero al nodo en la cima de la pila
    int longitud;   // Cantidad de elementos en la pila

public:
    // Constructor
    Pila() : tope(nullptr), longitud(0) {}  // O(1)

    // Destructor
    ~Pila();

    // Métodos básicos de la pila
    void construir(Pila<T>& pila);   // Inicializa una pila vacía
    void apilar(const T& dato);      // Agrega un elemento a la cima de la pila (push)
    T desapilar();                   // Elimina y devuelve el elemento superior (pop)
    T obtenerTope() const;           // Devuelve el tope sin eliminarlo (peek)
    bool esVacia() const;            // Verifica si la pila está vacía
    int getLongitud() const;         // Retorna la longitud de la pila
    void destruir();                 // Vacía la pila
    void mostrar() const;            // Muestra los elementos de la pila
};

// Implementación del Destructor
template <typename T>
Pila<T>::~Pila() {
    destruir();
}

// Método para construir la pila (inicializarla vacía)
template <typename T>
void Pila<T>::construir(Pila<T>& pila) {
    pila.tope = nullptr;
    pila.longitud = 0;
}

// Método para agregar un elemento en la cima de la pila (push)
template <typename T>
void Pila<T>::apilar(const T& dato) {
    Node<T>* nuevoNodo = new Node<T>(dato);
    nuevoNodo->setNext(tope);
    tope = nuevoNodo;
    longitud++;  // Se incrementa la longitud correctamente
}

// Método para eliminar y devolver el elemento superior de la pila (pop)
template <typename T>
T Pila<T>::desapilar() {
    if (esVacia()) {
        throw std::out_of_range("Error: La pila está vacía.");
    }
    Node<T>* nodoAEliminar = tope;
    T valor = nodoAEliminar->getValue();
    tope = tope->getNext();
    delete nodoAEliminar;
    longitud--;
    return valor;
}

// Método para obtener el elemento en la cima sin eliminarlo (peek)
template <typename T>
T Pila<T>::obtenerTope() const {
    if (esVacia()) {
        throw std::out_of_range("Error: La pila está vacía.");
    }
    return tope->getValue();
}

// Método para verificar si la pila está vacía
template <typename T>
bool Pila<T>::esVacia() const {
    return tope == nullptr;
}

// Método para obtener la longitud de la pila
template <typename T>
int Pila<T>::getLongitud() const {
    return longitud;
}

// Método para destruir (vaciar) la pila
template <typename T>
void Pila<T>::destruir() {
    while (!esVacia()) {
        desapilar();
    }
}

// Método para mostrar los elementos de la pila
template <typename T>
void Pila<T>::mostrar() const {
    Node<T>* actual = tope;
    while (actual != nullptr) {
        std::cout << actual->getValue() << " -> ";
        actual = actual->getNext();
    }
    std::cout << "NULL" << std::endl;
}

#endif // PILA_H
