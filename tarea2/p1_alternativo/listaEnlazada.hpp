#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef char tElemLista;

struct tNodo{
    tElemLista info;
    tNodo* sig;
};



class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;//                                      apuntara siempre al nodo anterior del actual, para acceder al valor seria curr->sig->info
        unsigned int listSize;
        unsigned int pos; // posicion actual en la lista
    public:
        tLista();
        ~tLista();//                        elimina la lista por completo

        void clear();//                     borra todos los elementos de la lista, reinicializándola vacía

        int insert(tElemLista item);//      inserta un elemento en la posición actual de la lista

        //int append(tElemLista item);//      agrega un elemento al final de la lista

        tElemLista erase();//               borra el elemento actual y retorna su valor

        void moveToStart();//               mueve la posición actual al comienzo de la lista

        //void moveToEnd();//                 mueve la posición actual al final de la lista deja una posicion adelante del ultimo elemento

        void next();//                      mueve la posición actual al siguiente elemento de la lista, no produce cambios si está en la cola de la lista

        //void prev();//                      mueve la posición actual al elemento anterior de la lista, no produce cambios si está en la cabeza de la lista

        int length();//                     retorna el número de elementos en la lista

        //int currPos();//                    retorna la posición del elemento actual

        void moveToPos(unsigned int pos);//          mueve la posición actual a una especificada
        
        tElemLista getValue();//            obtiene el valor del elemento actual de la lista


        void change(tElemLista x);
};