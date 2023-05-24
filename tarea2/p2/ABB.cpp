#include "ABB.hpp"

/*
 en este cpp estan incluidas las funciones del arbol binario de busqueda, 
 las funciones pedidas en la tarea estan a partir de la linea 146 del codigo
*/

void procesar(tipoElem info){
    cout<<info<<"\n";
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
    preOrdenHelp (nodo->izq); //     visita hijo izquierdo en pre-orden
    preOrdenHelp (nodo->der); //     visita hijo derecho en pre-orden
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
    postOrdenHelp (nodo->izq); //     visita hijo izquierdo en post-orden
    postOrdenHelp (nodo->der); //     visita hijo derecho en post-orden
    procesar(nodo->info); //        procesa nodo actual (se hace lo que necesite)
}

void tabb::postOrden(){
    postOrdenHelp(raiz);
}



//          ojo



tabb::~tabb(){
    clear();
}



tNodoArbolBin* find_padre(tNodoArbolBin *raiz,tipoElem x){
    if (raiz->info==x){
        cout<<"****    ERROR    ****\nel dato "<<x<<" es la raiz del arbol, no tiene padre\nerror en ABB.cpp linea 88\n";
    }
    if (x<raiz->info){
        if(raiz->izq->info==x)
            return raiz;
        
        else
            return find_padre(raiz->izq,x);
        
    }
    if (x>raiz->info){
        if(raiz->der->info==x)
            return raiz;
        
        else
            return find_padre(raiz->der,x);
    }
    return 0;
    
}

tNodoArbolBin* find_predecesor(tNodoArbolBin *raiz){
    if (raiz->der==NULL)
        return raiz;
    return find_predecesor(raiz->der);
}

void removeHelp(tNodoArbolBin *&nodo, tipoElem item){
    if (nodo->info==item){
        if (nodo->izq==NULL && nodo->der==NULL){
            delete[] nodo;
            nodo=NULL;
            return;
        }
        else if (nodo->izq!=NULL && nodo->der==NULL){
            tNodoArbolBin *aux=nodo->izq;
            delete[] nodo;
            nodo=aux;
            return;
        }
        else if (nodo->der!=NULL && nodo->izq==NULL){
            tNodoArbolBin *aux=nodo->der;
            delete[] nodo;
            nodo=aux;
            return;
        }

        else{
            tNodoArbolBin* aux=find_predecesor(nodo->izq);
            nodo->info=aux->info;
            removeHelp(nodo->izq,nodo->info);
            return;
/*
            if (aux->izq==NULL){
                delete[] aux;
                aux=NULL;
                return;
            }
            else{
                tNodoArbolBin* auxx=aux->izq;
                tNodoArbolBin* padre=find_padre(aux,aux->info);
                delete[] aux;
                return;
            }
*/
        }

    }
    if (nodo == NULL) 
        return;
    else if (item < nodo->info)
        removeHelp(nodo->izq, item);
    else if (item>nodo->info)
        removeHelp(nodo->der, item);
}

void tabb::remove(tipoElem item){
    if (find(item)){
        removeHelp(raiz,item);
        nElems--;
    }
    else{
        cout<<"****    ERROR    ****\nel dato "<<item<<" no existe, por lo tanto no se puede eliminar\nerror en ABB.cpp linea 163\n";
    }
}



int tabb::size(){
    return nElems;
}


//// ***    funciones pedidas en la tarea    *** ////


//      insert:
void insertHelp(tNodoArbolBin *&nodo, tipoElem item,bool &flag){
    if (nodo==NULL){
        nodo=new tNodoArbolBin;
        nodo->info=item;
        nodo->izq=NULL;
        nodo->der=NULL;
        flag= 1;
    }
    else if (item<nodo->info)
        insertHelp(nodo->izq,item,flag);

    else if (item>nodo->info)
        insertHelp(nodo->der,item,flag);

    else if (item==nodo->info){
        cout<<"****    ERROR    ****\nel dato "<<nodo->info<<" ya fue ingresado\nerror en ABB.cpp linea 167\n";
        flag= 0;
    }
}

void tabb::insert(tipoElem item){
    bool flag;
    insertHelp(raiz,item,flag);
    if (flag)
        nElems++;
}



//find:
int findHelp(tNodoArbolBin *nodo, tipoElem item) {
    if (nodo == NULL) 
        return 0; // item no está en el ABB
    if (nodo->info == item) 
        return 1; // item encontrado
    if (item < nodo->info)
        return findHelp(nodo->izq, item);
    else
        return findHelp(nodo->der, item);
}

int tabb::find(tipoElem item) {
 return findHelp(raiz, item);
}



//lower_bound:
void lowerHelp(tNodoArbolBin* raiz,tipoElem x, int &opcion){
    if (raiz==NULL) 
        return;
    if (raiz->info==x){
        opcion=x;
        return;
    }
    if (x<raiz->info)
        lowerHelp(raiz->izq,x,opcion);
    if (x>raiz->info){
        opcion=raiz->info;
        lowerHelp(raiz->der,x,opcion);
    }
}

int tabb::lower_bound(tipoElem x){
    int opcion=-1;
    lowerHelp(raiz,x,opcion);
    if (opcion ==-1)
        cout<<"****    ERROR    ****\nel dato "<<x<<" no existe y no tiene predecesor\nerror en ABB.cpp linea 210\n";
    return opcion;
}
