#include "ABB.hpp"

/*
 en este cpp no estan incluidas las todas funciones del arbol binario de busqueda, 
 solo estan presentes las utilizadas en la tarea, las pedidas literalmente estan 
 desde la linea 89
*/



/*****
*   tabb::tabb()
******
*   esta funcion tiene el proposito de crear un ABB
******
* Input:
******
* Returns:
*   un ABB vacio
*****/

tabb::tabb(){
    raiz = NULL;
    nElems = 0;
}



/*****
*   void clearHelp(tNodoArbolBin *nodo)
******
*   esta funcion tiene el proposito de ser recursiva para ayudara la funcion clear y lograr eliminar los datos en el ABB
******
* Input:
*   tNodoArbolBin *nodo  : la respectiva raiz de un sub arbol binario
******
* Returns:
*   libera la memoria del ABB
*****/

void clearHelp(tNodoArbolBin *nodo) {
    if (nodo == NULL) return; //    árbol vacío, se detiene
    clearHelp(nodo->izq); //        visita subárbol izquierdo recursivamente
    clearHelp(nodo->der); //        visita subárbol derecho recursivamente
    delete nodo; //                 después de borrar subárboles, se borra a sí mismo
}



/*****
*   void tabb::clear()
******
*   esta funcion tiene el proposito de eleiminar el arbol llamando a la funcion recursiva clearHelp
******
* Input:
******
* Returns:
*   cambia nElems a 0
*   deja la raiz apuntando a NULL
*****/

void tabb::clear() {
 clearHelp(raiz);
 raiz = NULL;
 nElems = 0;
}



/*****
*   int tabb::size()
******
*   esta funcion tiene el proposito de retornar cuantos valores tiene el arbol
******
* Input:
******
* Returns:
*   retorna cuantos elementos tiene el arbol
*****/

int tabb::size(){
    return nElems;
}





//// ***    funciones pedidas en la tarea    *** ////






                /////     insert:     /////


/*****
*   void insertHelp(tNodoArbolBin *&nodo, tipoElem item,bool &flag)
******
*   esta funcion tiene el proposito de ser recursiva para ayudara la funcion insert y lograr insertar un dato en el ABB
******
* Input:
*   tNodoArbolBin *&nodo : la respectiva raiz de un sub arbol binario
*   tipoElem item        : es el dato que se desea ingresar al ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
*   bool flag            : una flag que determina si el dato fue ingresado correctamente o no
******
* Returns:
*   retorna la flag por referencia
*   retorna el arbol por referencia con sus respectivos camios, si existieron
*****/

void insertHelp(tNodoArbolBin *&nodo, tipoElem item,bool &flag){
    if (nodo==NULL){//                                              si el nodo es null indica que ahi se ingresara el dato
        nodo=new tNodoArbolBin;
        nodo->info=item;
        nodo->izq=NULL;
        nodo->der=NULL;
        flag= 1;
    }
    else if (item<nodo->info)//                                     si el dato a ingresar es menor al valor del nodo se evaluara la funcion en su hijo izquierdo
        insertHelp(nodo->izq,item,flag);

    else if (item>nodo->info)//                                     si el dato a ingresar es mayor al valor del nodo se evaluara la funcion en su hijo derecho
        insertHelp(nodo->der,item,flag);

    else if (item==nodo->info){//                                   si el dato a ingresar es igual al valor del nodo no se insertara en el arbol y la flag sera false para no aumentar nElems
        cout<<"****    ERROR    ****\nel dato "<<nodo->info<<" ya fue ingresado\nerror en ABB.cpp linea 148 / 114\n";
        flag= 0;
    }
}



/*****
*   void tabb::insert(tipoElem item)
******
*   esta funcion tiene el proposito de insertar un dato al ABB, solo llama a la funcion insertHelp y verifica que la flag sea 1
******
* Input:
*   tipoElem item : el dato que se quiere ingresar al ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
******
* Returns:
*   si la insercion fue exitosa aumenta nElemes en 1
*****/

void tabb::insert(tipoElem item){
    bool flag;
    insertHelp(raiz,item,flag);
    if (flag)
        nElems++;
}



                /////     find:     /////


/*****
*   int findHelp(tNodoArbolBin *nodo, tipoElem item)
******
*   esta funcion tiene el proposito de ser recursiva para ayudara la funcion find y lograr encontrar un dato en el ABB
******
* Input:
*   tNodoArbolBin *&nodo : la respectiva raiz de un sub arbol binario
*   tipoElem item        : es el dato que se desea encontrar en el ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
******
* Returns:
*   retorna true si encuentra al valor y false si no lo encuentra
*****/

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



/*****
*   int tabb::find(tipoElem item)
******
*   esta funcion tiene el proposito de llamar a findHelp y lograr insertar un dato en el ABB
******
* Input:
*   tipoElem item        : es el dato que se desea ingresar al ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
******
* Returns:
*   retorna true si encuentra al valor y false si no lo encuentra
*****/

int tabb::find(tipoElem item) {
    return findHelp(raiz, item);
}



                /////     lower_bound:     /////


/*****
*   int lowerHelp(tNodoArbolBin* raiz,tipoElem x, int &opcion)
******
*   esta funcion tiene el proposito de ser recursiva para ayudara la funcion lower_bound y lograr encontrar el dato mas cercano menor o igual a x
******
* Input:
*   tNodoArbolBin *&nodo : la respectiva raiz de un sub arbol binario
*   tipoElem item        : es el dato del que se desea encontrar su menor o igual mas cercano en el ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
*   int &opcion          : variable que guarda una posible opcion hasta llegar a la opcion definitiva
******
* Returns:
*   retorna la opcion resultante por referencia
*****/

void lowerHelp(tNodoArbolBin* raiz,tipoElem x, int &opcion){
    if (raiz==NULL) 
        return;
    if (raiz->info==x){
        opcion=x;
        return;
    }
    if (x<raiz->info)
        return lowerHelp(raiz->izq,x,opcion);
    if (x>raiz->info){
        opcion=raiz->info;
        return lowerHelp(raiz->der,x,opcion);
    }
}



/*****
*   int tabb::lower_bound(tipoElem x)
******
*   esta funcion tiene el proposito de llamar a lowerHelp y lograr insertar un dato en el ABB
******
* Input:
*   tipoElem item        : es el dato del que se desea encontrar su menor o igual mas cercano en el ABB, resumido es un int ( linea 7 de ABB.hpp "typedef int tipoElem;")
******
* Returns:
*   retorna la opcion, si esta no se encuentra se retorna -1
*****/

int tabb::lower_bound(tipoElem x){
    int opcion=-1;
    lowerHelp(raiz,x,opcion);
/*
    if (opcion ==-1)
        cout<<"****    ERROR    ****\nel dato "<<x<<" no existe y no tiene predecesor\nerror en ABB.cpp linea 250\n";
*/
    return opcion;
}
