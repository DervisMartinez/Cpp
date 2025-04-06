//Sobre Carga de Operadores 
#include <iostream>
#include <stdlib.h>
using namespace std;

class fecha{
    //Atributos
    private :
        int day, month ,year ;
    //methods 
    public:
        fecha(int ,int ,int); //constructor
        fecha(long); // consturcto 2
        void mostrarFecha(); 


};

//constructor 1
fecha::fecha(int _day , int _month , int _year){
    year = _year ;
    month = _month ;
    day = _day;
};

//constructor 2
fecha::fecha(long fecha){
    year = int(fecha /1000); // extraer el year
    month = int(fecha-year*1000)/100 ; //extraer el mes
    day = int(fecha-year*1000-month*100); //extraer el dia 
};

void fecha::mostrarFecha(){

    cout <<'la fecha es :'<<day<<'/'<<month<<'/'<<year<<endl;
};

int main() {
    long numericDate;
    while (cin >> numericDate) { // Leer fechas en formato numérico largo (YYYYMMDD) desde la entrada
        fecha f(numericDate); // Crear objeto de fecha usando el segundo constructor
        f.mostrarFecha(); // Mostrar la fecha
    }
    system("pause");
    return 0;
}

