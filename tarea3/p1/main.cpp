#include "UnsortedDict.hpp"

//cd /mnt/d/user/admin/documents/github/tareas_inf134/tarea3/p1
//g++ UnsortedDict.cpp main.cpp -o out -Wall
// pepe y fasdfasf colisionan
int main(){
    string nombre,clave,instruccion;
    login dic;
    dic.init();

    int i=1;
    fstream file;
    file.open("ejemplo.txt",ios::in);
    do{
        cout<<i++<<"\n";
        file>>instruccion;
        if (instruccion=="REGISTRAR"){
            file>>nombre;
            file>>clave;
            dic.crear_nuevo_usuario(nombre,clave);
        }

        else if (instruccion=="INICIAR_SESION"){
            file>>nombre;
            file>>clave;
            dic.iniciar_sesion(nombre,clave);
        }
        else if (instruccion=="ACTUALIZAR"){
            file>>nombre;
            file>>clave;
            dic.cambiar_clave(nombre,clave);
        }
        else if (instruccion=="PRINT"){
            dic.eliminar();
        }
    }while(instruccion!="FINALIZAR");
    file.close();


    /*
    do{
        cin>>instruccion;
        if (instruccion=="REGISTRAR"){
            cin>>nombre;
            cin>>clave;
            dic.crear_nuevo_usuario(nombre,clave);
        }

        else if (instruccion=="INICIAR_SESION"){
            cin>>nombre;
            cin>>clave;
            dic.iniciar_sesion(nombre,clave);
        }
        else if (instruccion=="ACTUALIZAR"){
            cin>>nombre;
            cin>>clave;
            dic.cambiar_clave(nombre,clave);
        }
        else if (instruccion=="PRINT"){
            dic.eliminar();
        }
    }while(instruccion!="FINALIZAR");
    */

    return 0;
}