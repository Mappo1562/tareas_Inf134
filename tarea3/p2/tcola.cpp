#include "tcola.hpp"

/*****
* tcola::tcola
******
* constructor tcola
******
* Input:
*   void
******
* Returns:
*   void
*****/


tcola::tcola(){
    Ht=new comando[M];
    Ht[0].prioridad=0;
    for (int i=1;i<M;i++){
        Ht[i].prioridad=inf;
    }
    agregados=0;
    eliminados=0;
}

/*****
* tcola::~tcola
******
* destructor tcola
******
* Input:
*   void
******
* Returns:
*   void
*****/

tcola::~tcola(){}

/*****
* void tcola::clear
******
* libera la memoria
******
* Input:
*   void
******
* Returns:
*   void
*****/

void tcola::clear(){
    delete[] Ht;
}

/*****
* void tcola::insertColaP
******
* Metodo que inserta un item en el heap
******
* Input:
*   comando item : item a ingresar
******
* Returns:
*   void
*****/


void tcola::insertColaP(comando item){
    Ht[0].prioridad++;
    agregados++;
    int pos=Ht[0].prioridad;
    Ht[pos]=item;
    bool flag=1;
    while (flag){
        if(Ht[pos/2].prioridad>item.prioridad){
            Ht[pos]=Ht[pos/2];
            Ht[pos/2]=item;
            pos=pos/2;
        }
        else 
            flag=false;
    }
}

/*****
* int tcola::sizeColaP
******
* Metodo que retorna la cantidad de valores en el heap
******
* Input:
*   void
******
* Returns:
*   Ht[0].prioridad : int que representa el total de valores en el heap
*****/


int tcola::sizeColaP(){
    return Ht[0].prioridad;
}

/*****
* tipoElem tcola::findMin
******
* Metodo que retorna el comando con numero de prioridad menor
******
* Input:
*   void
******
* Returns:
*   Ht[1] : comando con numero de prioridad menor
*****/


tipoElem tcola::findMin(){
    return Ht[1];
}

/*****
* void tcola::removeMin
******
* Metodo que elimina el min valor de prioridad y reacomoda el heap
******
* Input:
*   void
******
* Returns:
*   void
*****/


void tcola::removeMin(){
    if (Ht[0].prioridad<1)
        return;
    Ht[1]=Ht[Ht[0].prioridad];
    Ht[Ht[0].prioridad].prioridad=inf;
    Ht[0].prioridad--;
    bool flag=1;
    int pos=1;
    eliminados++;
    comando aux;
    while (flag){
        if (Ht[pos*2].prioridad<Ht[pos].prioridad||Ht[pos*2+1].prioridad<Ht[pos].prioridad){
            if (Ht[pos*2].prioridad<Ht[pos*2+1].prioridad){
                aux=Ht[pos*2];
                Ht[pos*2]=Ht[pos];
                Ht[pos]=aux;
                pos=pos*2;
            }
            else if (Ht[pos*2+1].prioridad<Ht[pos*2].prioridad){
                aux=Ht[pos*2+1];
                Ht[pos*2+1]=Ht[pos];
                Ht[pos]=aux;
                pos=pos*2+1;
            }
        }
        else
            flag=0;
    }
}

/*****
* int tcola::deletes
******
* Metodo que retorna la cantidad de valores eliminados (enviados)
******
* Input:
* void
******
* Returns:
*   eliminados : entero que representa la cantidad de los valores enviados (eliminados)
*****/


int tcola::deletes(){
    return eliminados;
}

/*****
* int tcola::pushes
******
* Metodo que retorna la cantidad de valores ingresados
******
* Input:
* void
******
* Returns:
*   agregados : entero que representa la cantidad de los valores agregados
*****/

int tcola::pushes(){
    return agregados;
}