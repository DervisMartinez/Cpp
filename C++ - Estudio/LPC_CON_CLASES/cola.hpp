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

    // Destructor
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
    void invertir();
    void concatenar(Cola<T>& otra);
    void modificar(int pos, const T& nuevoValor);   
    void ordenar();

    // ------ Geters -----------

    Node<T>* getFrente() const;
    Node<T>* getUltimo() const;
    int getLongitud() const;

    // Setters
    void setFrente(Node<T>* nuevoFrente);
    void setUltimo(Node<T>* nuevoUltimo);
    void setLongitud(int nuevaLongitud);

};

// Implementación del Destructor
template <typename T>
Cola<T>::~Cola() {
    destruir();
}

// Método para construir la cola (inicializarla vacía)
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
        final->setNext(nuevoNodo);  // Enlaza el último nodo con el nuevo
        final = nuevoNodo;          // Actualiza el puntero final
    }
    longitud++;
}

// Método para eliminar y devolver el primer elemento de la cola (Desencolar)
template <typename T>
T Cola<T>::desencolar() {
    if (esVacia()) {
        throw std::out_of_range("Error: La cola está vacía.");
    }
    Node<T>* temp = frente;
    T valor = temp->getValue();
    frente = frente->getNext();
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
    return frente->getValue();
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
    Node<T>* actual = frente;
    while (actual != nullptr) {
        std::cout << actual->getValue() << " -> ";
        actual = actual->getNext();
    }
    std::cout << "NULL" << std::endl;
};

template <typename T>
void Cola<T>::modificar(int pos, const T& nuevoValor) {
    if (pos < 0 || pos >= longitud) {
        throw std::out_of_range("Posición fuera de rango");
    }
    Node<T>* temp = frente;
    for (int i = 0; i < pos; ++i) {
        temp = temp->getNext();
    }
    temp->setValue(nuevoValor);
};

template <typename T>
void Cola<T>::ordenar() {
    if (longitud <= 1) return;

    bool huboIntercambio;
    do {
        huboIntercambio = false;
        Node<T>* actual = frente;
        Node<T>* siguiente = actual->getNext();
        while (siguiente != nullptr) {
            if (actual->getValue() > siguiente->getValue()) {
                T temp = actual->getValue();
                actual->setValue(siguiente->getValue());
                siguiente->setValue(temp);
                huboIntercambio = true;
            }
            actual = siguiente;
            siguiente = siguiente->getNext();
        }
    } while (huboIntercambio);
};


template <typename T>
void Cola<T>::concatenar(Cola<T>& otra) {
    Node<T>* temp = otra.frente;
    while (temp != nullptr) {
        encolar(temp->getValue());
        temp = temp->getNext();
    }
};

template <typename T>
void Cola<T>::invertir() {
    Node<T>* anterior = nullptr;
    Node<T>* actual = frente;
    Node<T>* siguiente = nullptr;
    final = frente;

    while (actual != nullptr) {
        siguiente = actual->getNext();
        actual->setNext(anterior);
        anterior = actual;
        actual = siguiente;
    }

    frente = anterior;
};

/// ---Getters ---
template <typename T>
Node<T>* Cola<T>::getFrente() const {
    return frente;
};

template <typename T>
Node<T>* Cola<T>::getUltimo() const {
    return final;
};

template <typename T>
int Cola<T>::getLongitud() const {
    return longitud;
};


// ---Seters ---
template <typename T>
void Cola<T>::setFrente(Node<T>* nuevoFrente) {
    frente = nuevoFrente;
};

template <typename T>
void Cola<T>::setUltimo(Node<T>* nuevoUltimo) {
    final = nuevoUltimo;
};

template <typename T>
void Cola<T>::setLongitud(int nuevaLongitud) {
    longitud = nuevaLongitud;
}


#endif // COLA_H
