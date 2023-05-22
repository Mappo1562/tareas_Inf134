#include "ABB.hpp"

/*
 en este cpp estan incluidas las funciones del arbol binario de busqueda, 
 las funciones pedidas en la tarea estan a partir de la linea x del codigo
*/

void procesar(tipoElem nodo){
    return;
}



tabb::tabb(){
    raiz = NULL;
    nElems = 0;
}



void clearHelp(tNodoArbolBin *nodo) {
    if (nodo == NULL) return; //    árbol vacío, se detiene
    clearHelp(nodo->izq); //        visita subárbol izquierdo recursivamente
    clearHelp(nodo->der); //        visita subárbol derecho recursivamente
    delete nodo; //                 después de borrar subárboles, se borra a sí mismo
}



void tabb::clear() {
 clearHelp(raiz); // función auxiliar para eliminar los nodos
 raiz = NULL;
 nElems = 0;
}



void preOrdenHelp(tNodoArbolBin *nodo){
    if (nodo == NULL) return;
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en pre-orden
    inOrdenHelp (nodo->der); //     visita hijo derecho en pre-orden
}

void tabb::preOrden(){
    preOrdenHelp(raiz);
}



void inOrdenHelp (tNodoArbolBin *nodo) {
    if (nodo == NULL) return;
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en in-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
    inOrdenHelp (nodo->der); //     visita hijo derecho en in-orden
}

void tabb::inOrden () {
    inOrdenHelp (raiz);
}



void postOrdenHelp(tNodoArbolBin *nodo){
    if (nodo == NULL) return;
    inOrdenHelp (nodo->izq); //     visita hijo izquierdo en post-orden
    inOrdenHelp (nodo->der); //     visita hijo derecho en post-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
}

void tabb::postOrden(){
    postOrdenHelp(raiz);
}



tabb::~tabb(){

}



void tabb::remove(tipoElem item){

}



int tabb::size(){

}


//// ***    funciones pedidas en la tarea    *** ////


//insert:
void tabb::insert(tipoElem x){

}

//find:
int findHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == NULL) return 0; // item no está en el ABB
    if (nodo->info == item) return 1; // item encontrado
    if (item < nodo->info)
        return findHelp(nodo->izq, item);
    else
        return findHelp(nodo->der, item);
}

int tabb::find(tipoElem item) {
 return findHelp(raiz, item);
}

//lower_bound:
int tabb::lower_bound(tipoElem x){

}
