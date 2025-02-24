#include <iostream>
#include <stdlib.h>


using namespace std ;

struct Nodo{
    int info ;
    Nodo* sig;
};
//prototypes
void agregarPila( Nodo *& , int);
void sacarPila(Nodo *& , int &);

int main(){
    Nodo *pila = NULL;
    int dato;

    cout << "ingrese un numero :\n";
    cin >>dato;
    agregarPila(pila,dato);

    cout << "ingrese otro numero :\n";
    cin >>dato;

    agregarPila(pila,dato);

    cout <<"\nsacando elementos de la pila";
    while (pila != NULL)//mientras no sea el final de la pila 
    {
        sacarPila(pila,dato)/* code */;
        if (pila != NULL)
        {
            cout<<dato <<" , ";
        }else{
            cout<<dato<<".";
        };
        
    };
    
    return 0 ; 

};

void agregarPila( Nodo *&pila , int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo ->info = n ;
    nuevo_nodo ->sig = pila ;
    pila = nuevo_nodo;

    cout<<"\nElemento "<<n<<" agregado correctamente a la pila\n"<<endl;

};

void sacarPila(Nodo *&pila , int &n){
    Nodo *aux= pila; //Creamos un nodo auxiliar que obtenga el valor de pila
    n = aux ->info ;
    pila = aux -> sig ; // pila apunta al siguiente despues de la auxiliar
    delete aux;
};
