#include "ListaEnlazada.hpp"




tLista::tLista() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}

tLista::~tLista(){
    clear();
    delete head;
}

void tLista::clear() {
    tNodo* aux = head->sig;    // Recorrer la lista y liberar la memoria de cada nodo
    while (aux != NULL) {
        tNodo* temp = aux;
        aux = aux->sig;
        delete temp;
    }

    head->sig = NULL;// Reinicializar los punteros y variables de la lista
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

int tLista::append(tElemLista item){
    tail->sig= new tNodo;
    tNodo* aux = tail->sig;
    aux->info=item;
    tail=aux;
    tail->sig=NULL;
    listSize++;
    pos=listSize-1;
    return pos;
}

void tLista::moveToStart() { 
    curr = head; 
    pos = 0; 
}


void tLista::moveToEnd() { 
    curr = tail; 
    pos = listSize; 
}


void tLista::prev() {
    tNodo* temp;
    if (curr == head)   
        return;
    temp = head;
    while (temp->sig != curr) 
        temp = temp->sig;
    curr = temp;
    pos--;
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

int tLista::currPos(){
    return pos;
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

