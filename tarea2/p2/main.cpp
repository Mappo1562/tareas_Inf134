#include "ABB.hpp"


void ENCENDER(int i,tabb &arbol){
    if(!arbol.find(i))
        arbol.insert(i);
}


void CUANTOS_ENCENDER(int i,tabb &arbol){
    int poste;
    poste=arbol.lower_bound(i);
    cout<<i-poste<<"\n";
}


void PARAR_PROGRAMA(tabb &arbol){
    cout<<arbol.size()<<"\n";
    arbol.clear();
}



void R(tabb &arbol, string opcion){
    if(opcion=="ENCENDER"){
        int n;
        cin>>n;
        ENCENDER(n,arbol);
    }
    else if(opcion=="CUANTOS_ENCENDER"){
        int n;
        cin>>n;
        CUANTOS_ENCENDER(n,arbol);
    }
    else if (opcion=="PARAR_PROGRAMA"){
        PARAR_PROGRAMA(arbol);
        return;
    }
    else
        cout<<"esta opcion no existe por favor utiliza alguna de estas\nENCENDER\nCUANTOS_ENCENDER\nPARAR_PROGRAMA\n";
    cin>>opcion;
    R(arbol,opcion);
    return;
}

void procedure(){
    tabb arbol;
    string opcion;
    cin>>opcion;
    R(arbol,opcion);
}

int main (){
    procedure();
    return 0;
}