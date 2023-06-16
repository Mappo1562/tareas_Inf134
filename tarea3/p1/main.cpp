#include "UnsortedDict.hpp"

//cd /mnt/d/user/admin/documents/github/tareas_inf134/tarea3/p1
//g++ UnsortedDict.cpp main.cpp -o out -Wall

int main(){
    int a;
    string nombre,clave;
    login dic;
    dic.init();


    do{
        cin>>a;
        if (a==1){
            cin>> nombre;
            cin>> clave;
            cout<<"lo agregare\n";
            dic.crear_nuevo_usuario(nombre,clave);
        }
        if (a==2){
            dic.eliminar();
        }
    }while (a!=0);

    return 0;
}