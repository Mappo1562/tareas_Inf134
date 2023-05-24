#include "ABB.hpp"

/*****
*   void ENCENDER(int i,tabb &arbol)
******
*   esta funcion tiene el proposito de agregar un nuevo nodo al ABB
******
* Input:
*   int i       : entero a ingresar en el arbol
*   tabb &Arbol : ABB
******
* Returns:
*   solo agrega al arbol el nuevo nodo
*****/

void ENCENDER(int i,tabb &arbol){
    if(!arbol.find(i))
        arbol.insert(i);
}



/*****
*   void ENCENDER(int i,tabb &arbol)
******
*   esta funcion tiene el proposito de presentar en pantalla
*   cuantos numeros no estan en el arbol, segun la tarea,
*   entrega cuantos postes esten apagados entre i y el mas 
*   cercano menor a i encendido, si no hay ningun encendido 
*   entre 0 e i.
*   en esta funcion me aproveche de que mi funcion lower_bound()
*   retorna -1 en el caso de no encontrar ningun encendido
******
* Input:
*   int i       : entero al cual se buscaran los postes no encendidos menor que el pero mayores que un poste encendido
*   tabb &Arbol : ABB
******
* Returns:
*   solo imprime la cantidad de postes
*****/

void CUANTOS_ENCENDER(int i,tabb &arbol){
    int poste;
    poste=arbol.lower_bound(i);
    cout<<i-poste<<"\n";
}



/*****
*   void PARAR_PROGRAMA(tabb &arbol)
******
*   esta funcion tiene el proposito de imprimir por pantalla el tamaño del arbol y liberar su memoria
******
* Input:
*   tabb &Arbol : ABB
******
* Returns:
*   solo imprime el tamaño y elimina el arbol
*****/

void PARAR_PROGRAMA(tabb &arbol){
    cout<<arbol.size()<<"\n";
    arbol.clear();
}



/*****
*   void R(tabb &arbol, string opcion)
******
*   esta funcion tiene el proposito de ser recursiva para que el usuario pueda ingresar las opciones
*   que desee y asi actuar dependiendo de la opcion escogida
******
* Input:
*   string opcion : opcion escogida por el usuario
*   tabb &Arbol   : ABB
******
* Returns:
*   no retorna nada solo llama a otras funciones
*****/

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



/*****
*   void procedure()
******
*   esta funcion tiene el proposito de llamar a la funcion recursiva R()
******
* Input:
******
* Returns:
*   no retorna nada solo llama a R
*****/

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