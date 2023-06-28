#include "tcola.hpp"



void PUSHCOMMAND(comando c, tcola &heap){
    heap.insertColaP(c);
    cout<<heap.sizeColaP()<<" PENDING\n";
}

void GET(tcola &heap, int n){
    if (heap.sizeColaP()<n){
        cout<<"0\n";
        return;
    }
    string ids[n], ins[n];
    comando c;
    cout<<n;
    for (int i=0;i<n;i++){
        c=heap.findMin();
        cout<<" "<<c.id;
        ins[i]=c.instruccion;
        heap.removeMin();
    }
    for(int i=0;i<n;i++)
        cout<<"\n"<<ins[i];
    cout<<"\n";
}

void PRINT(tcola heap){
    heap.print();
}

void TERMINATE(tcola heap){
    cout<<heap.deletes()<<" SENT "<<heap.pushes()<<" CREATED\n";
}

void procedure(){
    comando comando;
    string instruccion;
    tcola heap;
    int n;
    do{
        cin>>instruccion;
        if (instruccion=="PUSHCOMMAND"){
            cin>>comando.id;
            cin>>comando.prioridad;
            getline(cin,comando.instruccion);
            PUSHCOMMAND(comando,heap);
        }
        if (instruccion=="GET"){
            cin>>n;
            GET(heap,n);
        }
        if (instruccion=="PRINT"){
            PRINT(heap);
        }
        if (instruccion=="TERMINATE"){
            TERMINATE(heap);
        }
    }while(instruccion!="TERMINATE");
}

int main(){
    procedure();
    return 0;
}