//correspondecia entre arrays y punteros

#include <iostream>
using namespace std ; 

//prototypes
int correspondecia(int array[]);

int main(){

    int num[] = {1,2,3,4,5};


    return 0 ;
}

int correspondecia(int num[]){
    //Variables Locales
    int *dir_num ;

    dir_num = num;
    for (int i = 0; i < 5; i++)
    {
        cout <<"Element in the Vector.["<<i<<"]:"<<*dir_num++<<endl;
    };
    return 0;
};

