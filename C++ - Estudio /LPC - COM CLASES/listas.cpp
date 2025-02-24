#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "./nodo.h"  
using namespace std;

class Lista {
    // Atributos
private:
    Nodo* prim;  // Puntero al primer nodo
    Nodo* final; // Puntero al último nodo
    int longitud; // Longitud de la lista

public:
    // Constructor ; inicializa la lista vacia y longitud cero 
    Lista() : prim(nullptr), final(nullptr), longitud(0) {}

    // Métodos
    template<typename T> void lista(Lista *list); // Método para construir la lista
    template <typename> void invertir(Lista* list); // Método para invertir la lista
    void copiar(Lista& Lista); // Método para copiar una lista
    int consultar(int pos); // Método para consultar el elemento en la posición 'pos'
    int buscar(int elem); // Método para buscar un elemento en la lista
    int eliminar(int pos); // Método para eliminar un nodo en la posición 'pos'
    void insertar(Nodo*&list , int elem); // Método para insertar un elemento en una posición
    void vaciar(); // Método para vaciar la lista
    bool esVacia(); // Método para verificar si la lista está vacía

    // Getters
    int getLongitud() const; // Método para obtener la longitud de la lista
    template<typename> void getNext();
    // Setters
    void setLongitud(int longitud); // Método para establecer la longitud de la lista
    template<typename> void setNext();

};

// Creacion de las Funciones y Procesos de la lista

//Constructor Lista
template <typename T> 
void Lista::lista(Lista *list) {
    // Declaración de variables
    Nodo* head = nullptr;  // creamos un puntero a Nodo que apunta a nullptr inicialmente

  List-> prim = head; 
  List->longitud = 0;  // La longitud de la lista es 0 al principio
  List-> final = nullptr;
}; 

//invertir la lista
template <typename> 
void Lista :: invertir(Lista* list){
    //Variables
    Nodo* anterior; // Aqui guardamos el Nodo Anterior
    Nodo* actual ;
    Nodo* siguiente ;

    anterior = nullptr ;
    actual = this->prim;

    while (actual != NULL)
    {
        siguiente = actual*.getNext(list);
        anterior = settemplate<typename> void setNext();Next(anterior);
        anterior = actual;
        actual = siguiente; 
    };
    
    this->prim = anterior ;

};

//insertar en la lista
void Lista::insertar(Nodo*& list, int elem) {
    Nodo* nuevo_nodo;
    Nodo* aux1;
    Nodo* aux2;

    nuevo_nodo = new Nodo(elem);
    nuevo_nodo->info = elem;
    aux1 = list;

    // Caso especial: insertar al principio de la lista o en una lista vacía
    if (aux1 == NULL || aux1->info >= elem) {
        nuevo_nodo->siguiente = aux1;
        list = nuevo_nodo;
    } else {
        // Encuentra la posición de inserción correcta
        while (aux1 != NULL && aux1->info < elem) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        // Inserta el nuevo nodo en la posición encontrada
        aux2->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = aux1;
    }
}

#endif // LISTA.H