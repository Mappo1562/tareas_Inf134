#include "login.hpp"

//cd /mnt/d/user/admin/documents/github/tareas_inf134/tarea3/p1
//g++ UnsortedDict.cpp main.cpp -o out -Wall


void procedure(){
    string nombre,clave,instruccion;
    login dic;
    dic.init();

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

}

int main(){
    procedure();
    return 0;
}