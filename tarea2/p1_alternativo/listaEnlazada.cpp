#include "ListaEnlazada.hpp"


/*****
*   tLista::tLista()
******
*  este es el constructor de una Lista Enlazada
******
* Input:
******
* Returns:
*   Lista 
*****/

tLista::tLista() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}

/*****
*   tLista::~tLista()
******
*  este es el destructor de una Lista Enlazada
******
* Input: Es la Lista
******
* Returns:
*   Elimina la Lista 
*****/

tLista::~tLista(){
    clear();
    delete head;
}

/*****
*   void tLista::clear()
******
*  Esta es la función para reiniciar la Lista Vacia 
******
* Input: Es la Lista
******
* Returns:
*   Elimina la Lista 
*****/

void tLista::clear() {
    tNodo* aux = head->sig;    
    while (aux != NULL) {
        tNodo* temp = aux;
        aux = aux->sig;
        delete temp;
    }
    head->sig = NULL;
    tail = curr = head;
    listSize = 0;
    pos = 0;

}


int tLista::insert(tElemLista item) {
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if (curr == tail)   
        tail = curr->sig;
    listSize++;
    return pos;
}


void tLista::moveToStart() { 
    curr = head; 
    pos = 0; 
}


void tLista::next() { 
    if (curr != tail) { 
        curr = curr->sig; 
        pos++; 
    } 
}


void tLista::moveToPos(unsigned int posicion) {
    if (posicion < 0 || posicion > listSize) 
        return;
    curr = head;
    pos = 0;
    for (unsigned int i = 0; i < posicion; i++) {
        curr = curr->sig;
        pos++;
    }
}

tElemLista tLista::getValue(){
    return curr->sig->info;
}

int tLista::length(){
    return listSize;
}


tElemLista tLista::erase() {
    tNodo* eliminar = curr->sig;
    tElemLista ret = eliminar->info;
    curr->sig = eliminar->sig;
    if (eliminar == tail)
        tail = curr;
    delete eliminar;
    listSize--;
    return ret;
}

void tLista::change(tElemLista x){
    curr->sig->info=x;
}

