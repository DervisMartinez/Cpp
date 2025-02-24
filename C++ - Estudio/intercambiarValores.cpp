#include <iostream>
#include <stdlib.h>

using namespace std ;

void intercambio(float *,float *);//prototype

int mai(){
    float num1,num2;

    cout << "first num:"<<num1<<endl;
    cout << "second num :"<<num2<<endl;
    
    intercambio(&num1,&num2); 

    cout <<"despues del intercambio:\n\n"<<endl;
    cout <<"El nuevo valor de num1: "<<num1;
    cout <<"El nuevo valor de num2: "<<num2;


    return 0 ;
};

void intercambio(float *dirNm1,float *dirNm2){
    //var
    float aux;
    //intercambio
    aux = *dirNm1;
    *dirNm1 = *dirNm2;
    *dirNm2 = aux;
 }