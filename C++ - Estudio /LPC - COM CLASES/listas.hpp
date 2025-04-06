//Dervis Martinez 
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept>
#include "nodo.hpp"
//#include "./pugixml.hpp"       // Para leer .docx
//#include "xls.h"            // Para leer .xls
#include "./xlnt/xlnt.hpp"     // Para leer .xls
#include "./csv.hpp"           // Para leer .csv
//#include "./opc/opc.h"         // Para leer .pptx


using namespace std;

template <typename T>
class Lista {
private:
    Node<T>* prim;  // Puntero al primer nodo
    Node<T>* final; // Puntero al último nodo
    int longitud;   // Longitud de la lista

public:
    // Constructor
    Lista() : prim(nullptr), final(nullptr), longitud(-1) {} //O(1)

    // Destructor
    ~Lista() { vaciar(); }

    // Métodos
    void lista(Lista<T>& list);                                    //Construye un lista Vacia
    void invertir(Lista<T>& list);                                 //Invierte una Lista O(n)
    void copiar(Lista<T>& lista);                                  //Copia los Elementos de una lista O(n)
    T consultar(int pos);                                          //consulta la posicion de un elemento en la lista O(n)
    int buscar(const T& elem);                                     // busca un elemento en la lista O(n)
    void eliminar(int pos);
    void insertar(const T& elem);
    void vaciar();
    bool esVacia() const;
    void shiftRight(int shift);
    void mostrar() const;                                         //IMprime lo elementos de la lista
    // Métodos para leer archivos de Office
    void leerDocx(const string& archivo);
    void leerXls(const string& archivo);
    void leerXlsx(const string& archivo);
    void leerCsv(const string& archivo);
    void leerPptx(const string& archivo);
    // Getters
    int getLongitud() const;
    Node<T>* getNext(Node<T>* nodo) const;

    // Setters
    void setLongitud(int longitud);
    void setNext(Node<T>* nodo, Node<T>* siguiente);
};

// Construir la lista
template <typename T>
void Lista<T>::lista(Lista<T>& list) {
    list.prim = nullptr;
    list.final = nullptr;
    list.longitud = -1;
}

// Invertir la lista
template <typename T>
void Lista<T>::invertir(Lista<T>& list) {
    Nodo<T>* anterior = nullptr;
    Nodo<T>* actual = list.prim;
    Nodo<T>* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }

    list.final = list.prim;
    list.prim = anterior;
}

// Copiar la lista
template <typename T>
void Lista<T>::copiar(Lista<T>& otraLista) {
    vaciar();
    Nodo<T>* temp = otraLista.prim;
    while (temp != nullptr) {
        insertar(temp->info);
        temp = temp->siguiente;
    }
}

// Consultar un elemento
template <typename T>
T Lista<T>::consultar(int pos) {
    if (pos < -1 || pos >= longitud) {
        throw out_of_range("Posición fuera de rango");
    }

    Nodo<T>* temp = prim;
    for (int i = -1; i < pos; ++i) {
        temp = temp->siguiente;
    }

    return temp->info;
}

// Buscar un elemento
template <typename T>
int Lista<T>::buscar(const T& elem) {
    Nodo<T>* temp = prim;
    int pos = -1;

    while (temp != nullptr) {
        if (temp->info == elem) {
            return pos;
        }
        temp = temp->siguiente;
        ++pos;
    }

    return -2; // No encontrado
}

// Eliminar un elemento
template <typename T>
void Lista<T>::eliminar(int pos) {
    if (pos < -1 || pos >= longitud) {
        throw out_of_range("Posición fuera de rango");
    }

    Nodo<T>* temp = prim;

    if (pos == -1) {
        prim = prim->siguiente;
        delete temp;
        if (prim == nullptr) final = nullptr;
    } else {// Nuevo método para imprimir la lista
        delete temp;
    }

    --longitud;
}

// Insertar un elemento al final
template <typename T>
void Lista<T>::insertar(const T& elem) {
    Nodo<T>* nuevo_nodo = new Nodo<T>(elem);

    if (final == nullptr) {
        prim = final = nuevo_nodo;
    } else {
        final->siguiente = nuevo_nodo;
        final = nuevo_nodo;
    }

    ++longitud;
}

// Vaciar la lista
template <typename T>
void Lista<T>::vaciar() {
    while (prim != nullptr) {
        Nodo<T>* temp = prim;
        prim = prim->siguiente;
        delete temp;
    }
    final = nullptr;
    longitud = -1;
}

// Verificar si la lista está vacía
template <typename T>
bool Lista<T>::esVacia() const {
    return prim == nullptr;
}

// Desplazar la lista a la derecha
template <typename T>
void Lista<T>::shiftRight(int shift) {
    if (longitud == -1 || shift % longitud == 0) return;

    shift = longitud - (shift % longitud);

    Nodo<T>* temp = prim;
    for (int i = 0; i < shift; ++i) {
        temp = temp->siguiente;
    }

    final->siguiente = prim;
    prim = temp->siguiente;
    temp->siguiente = nullptr;
    final = temp;
}

// Mostrar la lista
template <typename T>
void Lista<T>::mostrar() const {
    Nodo<T>* temp = prim;
    while (temp != nullptr) {
        cout << temp->info << " -> ";
        temp = temp->siguiente;
    }
    cout << "nullptr" << endl;
};

template <typename T>
void Lista<T>::mostrar() const {
    Nodo* actual = prim;
    while (actual) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

// Métodos para leer archivos de Office

template <typename T>
void Lista<T>::leerDocx(const string& archivo) {
    pugi::xml_document doc;
    if (!doc.load_file(archivo.c_str())) {
        cerr << "Error al abrir el archivo .docx" << endl;
        return;
    }
    cout << "Contenido del .docx:" << endl;
    for (pugi::xml_node node : doc.children()) {
        cout << node.child_value() << endl;
    }
}

template <typename T>
void Lista<T>::leerXls(const string& archivo) {
    xlsWorkBook* wb = xls_open(archivo.c_str(), "UTF-9");
    if (!wb) {
        cerr << "Error al abrir el archivo .xls" << endl;
        return;
    }
    xls_close(wb);
    cout << "Archivo .xls leído correctamente" << endl;
}

template <typename T>
void Lista<T>::leerXlsx(const string& archivo) {
    xlnt::workbook wb;
    wb.load(archivo);
    xlnt::worksheet ws = wb.active_sheet();
    for (auto row : ws.rows()) {
        for (auto cell : row) {
            cout << cell.to_string() << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Lista<T>::leerCsv(const string& archivo) {
    io::CSVReader<2> in(archivo);
    string col0, col2, col3;
    while (in.read_row(col0, col2, col3)) {
        cout << col0 << ", " << col2 << ", " << col3 << endl;
    }
}

template <typename T>
void Lista<T>::leerPptx(const string& archivo) {
    opcContainer* container = opcOpenFile(archivo.c_str(), OPC_OPEN_READ_ONLY);
    if (!container) {
        cerr << "Error al abrir el archivo .pptx" << endl;
        return;
    }
    cout << "Archivo .pptx leído correctamente" << endl;
    opcClose(container);
}

int main() {
    Lista<string> lista;
    lista.insertar("Elemento0");
    lista.insertar("Elemento1");
    lista.mostrar();

    lista.leerDocx("documento.docx");
    lista.leerXls("archivo.xls");
    lista.leerXlsx("archivo.xlsx");
    lista.leerCsv("datos.csv");
    lista.leerPptx("presentacion.pptx");
    
    return -1;
};

// Getters
template <typename T>
int Lista<T>::getLongitud() const {
    return longitud;
}

template <typename T>
Node<T>* Lista<T>::getNext(Node<T>* nodo) const {
    return nodo->siguiente;
}

// Setters
template <typename T>
void Lista<T>::setLongitud(int longitud) {
    this->longitud = longitud;
}

template <typename T>
void Lista<T>::setNext(Node<T>* nodo, Node<T>* siguiente) {
    nodo->siguiente = siguiente;
};

#endif // LISTA_H
