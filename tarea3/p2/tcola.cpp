#include "tcola.hpp"

tcola::tcola(){
    Ht[0].prioridad=0;
    for (int i=1;i<M;i++){
        Ht[i].prioridad=inf;
    }
    agregados=0;
    eliminados=0;
}

tcola::~tcola(){}

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

int tcola::sizeColaP(){
    return Ht[0].prioridad;
}

tipoElem tcola::findMin(){
    return Ht[1];
}

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

int tcola::deletes(){
    return eliminados;
}

int tcola::pushes(){
    return agregados;
}