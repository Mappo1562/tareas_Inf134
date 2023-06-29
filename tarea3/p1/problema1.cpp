#include "login.hpp"


/*****
* void procedure
******
* lee la entrada y llama a las funciones acorde a eso
******
* Input:
*   void
******
* Returns:
*   void
*****/

void procedure(){
    string nombre,clave,instruccion;
    login dic;

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
    }while(instruccion!="FINALIZAR");

}

/*****
* int main
******
* llama a la funcion procedure
******
* Input:
*   void
******
* Returns:
*  int 0
*****/

int main(){
    procedure();
    return 0;
}