//min heap
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
#define M 9999
#define inf 2147483647

struct comando{
    string id;
    int prioridad;
    string instruccion;
};

typedef comando tipoElem;

class tcola{
    private:
        comando Ht[M];
        int agregados;
        int eliminados;
    public:    
        tcola();
        ~tcola();

        // encuentra el minimo elemento del conjunto
        tipoElem findMin();

        // cantidad de elementos en la cola prioridad
        int sizeColaP();

        // elimina el máximo elemento del conjunto
        void removeMin();

        // inserta un elemento “item” en la cola de prioridad
        void insertColaP(comando item);
    
        void print();

        int pushes();

        int deletes();
};