/*asignacion dinamica
new :reserva el numero de bytes solicitado por la declaracion
delete : libera un bloque de bytes reservado con anterioridad

*/

#include <iostream>
#include <stdlib.h> //funciona new delete

using namespace std;

//prototype
void getNotes();
void viewNotes();

int numCalif ,*calif;

int main (){

    getNotes();
    viewNotes();

    delete[] calif; //liberando el espacio en bytes anteriormente 

    return 0;
};

void getNotes(){
    cout <<"Digite el Numero de Calificaciones:";
    cin >>numCalif;

    calif = new int[numCalif]; // crea el arreglo 

    for (int i = 0; i < numCalif; i++)                      // O(n)
    {
        cout<<"inserte una nota";
        cin>>calif[i];
    };
    
};

void viewNotes(){
    cout<<"\n\nMostrando Notas del Uusario :\n";            // 0(n)
    for (int i = 0; i < numCalif; i++)
    {
        cout<<calif[i]<<endl ;
    };
    
}