#include <iostream>
#include <string>

#define N 1000

using namespace std;

class portafolio {
    // atributo
    private:
    int arrayOfActive[N];
    int arrayOfCant[N];
    float arrayOfPeso[N];
    float capital;

    // metodos
    public:
    void construir() {}

    void construir(int active[], int cant[], float peso[], float cap) {
        for (int i = 0; i < N; ++i) {
            arrayOfActive[i] = active[i];
            arrayOfCant[i] = cant[i];
            arrayOfPeso[i] = peso[i];
        }
        capital = cap;
    }

};

