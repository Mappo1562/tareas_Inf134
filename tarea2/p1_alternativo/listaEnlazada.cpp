#include "ListaEnlazada.hpp"


/*****
*   tLista::tLista()
******
*  este es el método constructor de una Lista Enlazada
******
* Input:
******
* Return:
*   Crea la Lista
*****/

tLista::tLista() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}

/*****
*   tLista::~tLista()
******
*  este es el método destructor de una Lista Enlazada
******
* Input: 
******
* Return:
*   Elimina la Lista 
*****/

tLista::~tLista(){
    clear();
    delete head;
}

/*****
*   void tLista::clear()
******
*  Esta es el método para reiniciar la Lista a vacía
******
* Input:
*   Lista
******
* Return:
*   Libera la memoria de la Lista 
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

/*****
*   int tLista::insert(tElemLista item)
******
*  Esta es el método para insertar un ítem
******
* Input:
*   Ítem
******
* Return:
*   Lista con el ítem insertado 
*****/

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

/*****
*   void tLista::moveToStart()
******
*  Este es el método para mover el puntero al comienzo 
******
* Input:
******
* Return:
*   mueve el puntero al comienzo
*****/

void tLista::moveToStart() { 
    curr = head; 
    pos = 0; 
}

/*****
*   void tLista::next()
******
*  Este es el método para mover el puntero al siguiente valor 
******
* Input:
******
* Return:
*   mueve el puntero al siguiente valor 
*****/

void tLista::next() { 
    if (curr != tail) { 
        curr = curr->sig; 
        pos++; 
    } 
}

/*****
*   void tLista::moveToPos(unsigned int posicion)
******
*  Este es el método para mover a una posición definida 
******
* Input:
*   unsigned int posicion: posición a la que se quiere mover
******
* Return:
*   mueve el curr a la posición definida y cambia pos
*****/

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

/*****
*   tElemLista tLista::getValue()
******
*  Este es el método para obtener la información de la posición actual
******
* Input:
******
* Return:
*   Información de la pocisión actual
*****/

tElemLista tLista::getValue(){
    return curr->sig->info;
}

/*****
*   int tLista::length()
******
*  Este es el método para obtener el tamaño de la Lista 
******
* Input:
******
* Return:
*   Tamaño de la Lista
*****/

int tLista::length(){
    return listSize;
}

/*****
*   tElemLista tLista::erase()
******
*  Este es el método para eliminar el valor en la posición actual
******
* Input:
******
* Return:
*   Lista sin el valor de la posición actual
*   tElemLista ret: el valor eliminado
*****/

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

/*****
*   void tLista::change(tElemLista x)
******
*  Este es el método para intercambiar la información actual por la información entregada
******
* Input:
*   tElemLista x: Información entregada para intercambiar 
******
* Return:
*   Lista resultante
*****/

void tLista::change(tElemLista x){
    curr->sig->info=x;
}

