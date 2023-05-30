#include "listaEnlazada.hpp"


fstream file;

/*****
*   void INSERTAR(int pos,char c, tLista &list)
******
*  esta es la función que inserta un nucleotido en la posición entregada
******
* Input:
******
*   int pos: Posición donde se insertará el nucleotido 
*   char c: Nucleotido a insertar 
*   tLista &list: Lista por referencia
* Return:
*   Lista resultante
*****/

void INSERTAR(int pos,char c, tLista &list){
    list.moveToPos(pos);
    list.insert(c);
    list.moveToStart();
    return;
}

/*****
*   void BORRAR(int pos, tLista &list)
******
*  esta es la función que borra un nucleotido en la posición entregada
******
* Input:
******
*   int pos: Posición donde se borrará el nucleotido 
*   tLista &list: Lista por referencia
* Return:
*   Lista resultante
*****/

void BORRAR(int pos, tLista &list){
    list.moveToPos(pos);
    list.erase();
    list.moveToStart();
    return;
}

/*****
*   void INTERCAMBIAR(int pos, char c, tLista &list)
******
*  esta es la función que intercambia un nucleotido en la posición entregada
******
* Input:
******
*   int pos: Posición donde se intercambiará el nucleotido 
*   char c: Nucleotido a intercambiar 
*   tLista &list: Lista por referencia
* Return:
*   Lista resultante
*****/

void INTERCAMBIAR(int pos, char c, tLista &list){
    list.moveToPos(pos);
    list.change(c);
    list.moveToStart();
    return;
}

/*****
*   void print(tLista &list, fstream &ret)
******
*  esta es la función que imprime la Lista de nucleotidos resultantes en el archivo
******
* Input:
******
*   tLista &list: Lista por referencia
*   fstream &ret: Archivo donde se imprimirá la Lista resultante 
* Return:
*   Imprime  en el archivo
*   Vacía la Lista
*****/

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

/*****
*   void procedureHelp(int m,tLista &list, fstream &ret)
******
*  esta es la función que tiene el propósito de leer las intrucciones
******
* Input:
******
*   int m: entero m que indica la cantidad de modificaciones
*   tLista &list: Lista por referencia
*   fstream &ret: Archivo donde se imprimirá la Lista resultante 
* Return:
*   Realiza la opción pedida
*****/

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

/*****
*   void copia(tLista &ret,string original)
******
*  esta es la función que a partir de un string lo copia a una Lista
******
* Input:
******
*   tLista &ret: Archivo donde se imprimirá la Lista resultante 
*   string original: La secuencia de nucleotidos
* Return:
*   tLista ret: Retorna la Lista 
*****/

void copia(tLista &ret,string original){
    for (unsigned int i=0;i<original.length();i++){
        ret.insert(original[i]);
        ret.next();
    }
}

/*****
*   void procedure()
******
*  esta es la función que define las variables y llama a la funcion procedureHelp()
******
* Input:
******
* Return:
*   Llama a la funcion procedureHelp()
*****/

void procedure(){
    fstream ret;
    file.open("secuencias-nucleotidos.txt", ios::in);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ret.open("secuencias-reconstruidas.txt", ios::out);
    if(!ret.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
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

/*****
*   int main()
******
*  esta es la función llama a la función procedure()
******
* Input:
******
* Return:
*   Llama a la funcion procedure()
*****/

int main(){
    procedure();
}
