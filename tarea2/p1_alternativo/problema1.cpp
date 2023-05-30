#include "listaEnlazada.hpp"


fstream file;


void INSERTAR(int pos,char c, tLista &list){
    list.moveToPos(pos);
    list.insert(c);
    list.moveToStart();
    return;
}

void BORRAR(int pos, tLista &list){
    list.moveToPos(pos);
    list.erase();
    list.moveToStart();
    return;
}

void INTERCAMBIAR(int pos, char c, tLista &list){
    list.moveToPos(pos);
    list.change(c);
    list.moveToStart();
    return;
}


void print(tLista &list, fstream &ret){
    list.moveToStart();
    for (int i=0;i<list.length();i++){
        ret<<list.getValue();
        list.next();
    }
    ret<<"\n";
    list.clear();
    return;
}

void printf(tLista &list){
    list.moveToStart();
    for (int i=0;i<list.length();i++){
        cout<<list.getValue();
        list.next();
    }
    list.moveToStart();
    cout<<"\n";
    return;
}

void procedureHelp(int m,tLista &list, fstream &ret){
    int pos;
    char c;
    string opcion;
    for (int j=0;j<m;j++){
        file>>opcion;
        if (opcion=="INSERTAR"){
            file>>pos;
            file>>c;
            INSERTAR(pos,c,list);
        }
        if (opcion=="BORRAR"){
            file>>pos;
            BORRAR(pos,list);
        }
        if (opcion=="INTERCAMBIAR"){
            file>>pos;
            file>>c;
            INTERCAMBIAR(pos,c,list);
        }
    }
    print(list,ret);
    return;
}

void copia(tLista &ret,string original){
    for (unsigned int i=0;i<original.length();i++){
        ret.insert(original[i]);
        ret.next();
    }
}

void procedure(){
    fstream ret;
    file.open("secuencias-nucleotidos.txt", ios::in);
    ret.open("secuencias-reconstruidas.txt", ios::out);
    int l,k,m;
    tLista list;
    string x;
    file>>l;

    file>>x;

    file>>k;
    for (int i=0;i<k;i++){
        copia(list,x);
        file>>m;
        procedureHelp(m,list,ret);
    }
    file.close();
    ret.close();
}


int main(){
    procedure();
}
