#include "tcola.hpp"

/*****
* void PUSHCOMMAND
******
* inserta un elemento en la tcola y imprime la cantidad de elementos actuales en esta misma
******
* Input:
*   comando c   : elemento a insertar
*   tcola &heap : tcola con todos los elementos
******
* Returns:
*   void, solo imprime
*****/


void PUSHCOMMAND(comando c, tcola &heap){
    heap.insertColaP(c);
    cout<<heap.sizeColaP()<<" PENDING\n";
}

/*****
* void GET
******
* elimina de la tcola a todos los n elementos menores
******
* Input:
* tcola &heap : tcola con todos los elementos
* int n       : numero entero que determina la cantidad de acciones a realizar
******
* Returns:
* TipoRetorno, Descripción retorno
*****/

void GET(tcola &heap, int n){
    if (heap.sizeColaP()==0){
        cout<<"0\n";
        return;
    }
    string ids[n], ins[n];
    comando c;
    cout<<n;
    for (int i=0;i<n;i++){
        if (heap.sizeColaP()==0){
            ins[i]=" ";
        }
        else{
            c=heap.findMin();
            cout<<" "<<c.id;
            ins[i]=c.instruccion;
            heap.removeMin();
        }
    }
    for(int i=0;i<n;i++)
        cout<<"\n"<<ins[i];
    cout<<"\n";
}

/*****
* void TERMINATE
******
* imprime los enviados y los creados
******
* Input:
*   tcola heap : tcola con todos los elementos
******
* Returns:
*   solo imprime los enviados y los creados
*****/

void TERMINATE(tcola heap){
    cout<<heap.deletes()<<" SENT "<<heap.pushes()<<" CREATED\n";
}

/*****
* procedure()
******
* llama a las funciones dependiendo de la entrada
******
* Input:
*   void
******
* Returns:
*   void, solo llama a las variables
*****/

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
        if (instruccion=="TERMINATE"){
            TERMINATE(heap);
        }
    }while(instruccion!="TERMINATE");
}

/*****
* int main()
******
* se encarga de llamar a procedure
******
* Input:
*   void
******
* Returns:
*   void
*****/

int main(){
    procedure();
    return 0;
}