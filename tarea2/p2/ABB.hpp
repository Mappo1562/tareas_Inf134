#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
typedef int tipoElem;

//  se define tNodoArbolBin para ser utilizado en el ABB:

struct tNodoArbolBin{
    tipoElem info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

//  se define el arbol binario de busqueda:

class tabb{
    private:
        tNodoArbolBin* raiz;
        int nElems;
    
    public:
        tabb();
        //~tabb();

        void clear();//                 elimina todos los elementos de un ABB, dejándolo vacío

        void insert(tipoElem item);//   inserta un elemento “item” en el ABB

        //void remove(tipoElem item);//   elimina un elemento “item” de un ABB

        int find(tipoElem item);//      busca un “item” en un ABB, retorna 0 en caso de no encontrarlo

        int size();//                   cantidad de elementos en el árbol

        //void inOrden();//               recorrido in-orden de un ABB

        //void preOrden();//              recorrido pre-orden de un ABB

        //void postOrden();//             recorrido post-orden de un ABB


        int lower_bound(tipoElem x);//   busca el primer valor que sea menor o igual a x.
};