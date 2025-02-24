#include <iostream>
using namespace std ; 

int verificarSiEsPar(int n);

int main(){
    //varible globales
    int num;

    cout << "add the new number: ";  // recibo un numero por el usuario 
    cin >>num ; 
    verificarSiEsPar(num); // llamada de la funcion de verificacion del numero par por valor

    return 0 ; // finaliza el programa 
}

int verificarSiEsPar(int num){
    //variables locales
    int *dir_num ; // puntero para guardar num

    dir_num = &num; // puntero :dir_num guarda la posicion de memoria de num 

    if (*dir_num % 2 == 0 )  // si lo que hay dentro de la direccion de memoria de dir_num en igual al resto 0 es par
    {
        cout << "the numnber is even" << endl; 
        cout <<"Posicion:"<<dir_num<< endl;
    }else
    {
        cout<< "the number :"<<*dir_num <<" is odd "<< endl; // el numero es impar y muestor el numero que me dio por consola
        cout <<"Posicion:"<<dir_num << endl;

    };

    return num;
};




