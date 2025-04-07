#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.hpp"

using namespace std;

template <typename T>
class Lista {
    //Atributtes
private:
    Node<T>* prim;    //Puntero al Primero de la Lista
    Node<T>* final;  // Puntero al Final de la lista
    int longitud;    // LOngitud de lista
    //Methods 
public:
    Lista() : prim(nullptr), final(nullptr), longitud(0) {}  //Constructor de la lista
    ~Lista() { vaciar(); }  //Destructor

    // Métodos básicos
    void construir(Lista<T>& list);
    void invertir(Lista<T>& list);
    void copiar(const Lista<T>& otraLista);
    T consultar(int pos);     //O(n)
    int buscar(const T& elem);
    void eliminar(int pos);                             //Elimina una Posicion de la LIsta 
    void insertar(const T& elem);
    void vaciar();                                      // Vacia una LIsta 
    bool esVacia() const;
    void shiftRight(int shift);
    void shiftLeft(int shift);
    void mostrar() const;
    void concatenar(Lista<T>& list);
    void ordenar(Lista<T>& list);
    void modificar(int pos, const T& nuevoValor);

//-----------------------------------------------------------------

    // Getters
    int getLongitud() const;
    Node<T>* getNext(Node<T>* nodo) const;
    Node<T>* getPrim() const;
    Node<T>* getFinal() const;

    // Setters
    void setLongitud(int longitud);
    void setNext(Node<T>* nodo, Node<T>* siguiente);
    void setPrim(Node<T>* nuevoPrim);
    void setFinal(Node<T>* nuevoFinal);
};

// Implementación

template <typename T>
void Lista<T>::construir(Lista<T>& list) {
    list.prim = nullptr;
    list.final = nullptr;
    list.longitud = 0;
}

template <typename T>
void Lista<T>::invertir(Lista<T>& list) {
    Node<T>* anterior = nullptr;
    Node<T>* actual = list.prim;
    Node<T>* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->getNext();
        actual->setNext(anterior);
        anterior = actual;
        actual = siguiente;
    }
    list.final = list.prim;
    list.prim = anterior;
}

template <typename T>
void Lista<T>::copiar(const Lista<T>& otraLista) {
    vaciar();
    Node<T>* temp = otraLista.prim;
    while (temp != nullptr) {
        insertar(temp->getValue());
        temp = temp->getNext();
    }
}

template <typename T>
T Lista<T>::consultar(int pos) {
    if (pos < 0 || pos >= longitud) {
        throw out_of_range("Posición fuera de rango");
    }
    Node<T>* temp = prim;
    for (int i = 0; i < pos; ++i) {
        temp = temp->getNext();
    }
    return temp->getValue();
}

template <typename T>
int Lista<T>::buscar(const T& elem) {
    Node<T>* temp = prim;
    int pos = 0;
    while (temp != nullptr) {
        if (temp->getValue() == elem) {
            return pos;
        }
        temp = temp->getNext();
        ++pos;
    }
    return -1;
}

template <typename T>
void Lista<T>::eliminar(int pos) {
    if (pos < 0 || pos >= longitud) {
        throw out_of_range("Posición fuera de rango");
    }
    Node<T>* temp = prim;
    if (pos == 0) {
        prim = prim->getNext();
        delete temp;
        if (prim == nullptr) {
            final = nullptr;
        }
    } else {
        Node<T>* anterior = nullptr;
        for (int i = 0; i < pos; ++i) {
            anterior = temp;
            temp = temp->getNext();
        }
        anterior->setNext(temp->getNext());
        if (temp->getNext() == nullptr) {
            final = anterior;
        }
        delete temp;
    }
    --longitud;
}

template <typename T>
void Lista<T>::insertar(const T& elem) {
    Node<T>* nuevo_nodo = new Node<T>(elem);
    if (final == nullptr) {
        prim = final = nuevo_nodo;
    } else {
        final->setNext(nuevo_nodo);
        final = nuevo_nodo;
    }
    ++longitud;
}

template <typename T>
void Lista<T>::vaciar() {
    while (prim != nullptr) {
        Node<T>* temp = prim;
        prim = prim->getNext();
        delete temp;
    }
    final = nullptr;
    longitud = 0;
}

template <typename T>
bool Lista<T>::esVacia() const {
    return prim == nullptr;
}

//mover a la Derecha 
template <typename T>
void Lista<T>::shiftRight(int shift) {
    if (longitud == 0 || shift % longitud == 0) return;
    shift = shift % longitud;
    int splitPoint = longitud - shift;
    Node<T>* current = prim;
    Node<T>* prev = nullptr;
    for (int i = 0; i < splitPoint; ++i) {
        prev = current;
        current = current->getNext();
    }
    final->setNext(prim);
    prim = current;
    prev->setNext(nullptr);
    final = prev;
}

//Mover a Izquierda
template <typename T>
void Lista<T>::shiftLeft(int shift) {
    if (longitud == 0 || shift % longitud == 0) return;

    shift = shift % longitud;
    Node<T>* current = prim;
    Node<T>* prev = nullptr;

    for (int i = 0; i < shift; ++i) {
        prev = current;
        current = current->getNext();
    }

    // Reorganizar enlaces
    final->setNext(prim);  // Conecta final con el principio
    prim = current;        // Nuevo comienzo
    prev->setNext(nullptr); // Rompe la lista
    final = prev;          // Nuevo final
}

template <typename T>
void Lista<T>::mostrar() const {
    Node<T>* temp = prim;
    while (temp != nullptr) {
        cout << temp->getValue() << " -> ";
        temp = temp->getNext();
    }
    cout << "nullptr" << endl;
}

template <typename T>
void Lista<T>::concatenar(Lista<T>& list) {
    Node<T>* temp = list.getPrim();
    while (temp != nullptr) {
        insertar(temp->getValue());
        temp = temp->getNext();
    }
}

template <typename T>
void Lista<T>::ordenar(Lista<T>& list) {
    if (list.esVacia() || list.getLongitud() == 1) return;

    bool huboIntercambio;
    do {
        huboIntercambio = false;
        Node<T>* actual = list.getPrim();
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

//Modificar
template <typename T>
void Lista<T>::modificar(int pos, const T& nuevoValor) {
    if (pos < 0 || pos >= longitud) {
        throw out_of_range("Posición fuera de rango");
    }
    Node<T>* temp = prim;
    for (int i = 0; i < pos; ++i) {
        temp = temp->getNext();
    }
    temp->setValue(nuevoValor);
}


// ---------------------------------Getters -------------------------------
template <typename T>
int Lista<T>::getLongitud() const {
    return longitud;
}

template <typename T>
Node<T>* Lista<T>::getNext(Node<T>* nodo) const {
    return nodo ? nodo->getNext() : nullptr;
}

template <typename T>
Node<T>* Lista<T>::getPrim() const {
    return prim;
}

template <typename T>
Node<T>* Lista<T>::getFinal() const {
    return final;
}

// Setters
template <typename T>
void Lista<T>::setLongitud(int longitud) {
    this->longitud = longitud;
}

template <typename T>
void Lista<T>::setNext(Node<T>* nodo, Node<T>* siguiente) {
    if (nodo) {
        nodo->setNext(siguiente);
    }
}

template <typename T>
void Lista<T>::setPrim(Node<T>* nuevoPrim) {
    prim = nuevoPrim;
}

template <typename T>
void Lista<T>::setFinal(Node<T>* nuevoFinal) {
    final = nuevoFinal;
}

#endif // LISTA_H

