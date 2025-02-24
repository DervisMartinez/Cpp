#include <iostream>
#include <stdlib.h>

using namespace std;
//prototypes
void getData();
void orderArray(int * ,int);
void viewArray(int * , int);

//global variables
int nElement , *element;

int main(){

    getData();
    orderArray(element,nElement);
    viewArray(element,nElement);

    delete[] element; //liberar memoria utilizada

    return 0 ;
}

void getData(){
    cout<<"Digite un numero de elementos del arreglo :\n";
    cin>>nElement;

    element = new int[nElement];

    for (int i = 0; i < nElement; i++)
    {
        cout<<"Digite un Numero :["<< i <<"] ";
        cin >> *(element + i);
    };
};

void orderArray(int *element, int nElement){
    int aux;

    for (int i = 0; i < nElement; i++){
        for (int j = 0; j < nElement - 1 ; j++){
            if(*(element+j) > *(element+j+1)){
                *(element+j) = *(element+j+1);
                *(element+j+1) = aux;
            };
        };
        
    };
};

void viewArray(int *element , int nElement){
cout <<"\n\nMostrando arreglo ordenado"<<endl;
for (int i = 0; i < nElement; i++)
{
    cout<<*(element+i);
};


};




