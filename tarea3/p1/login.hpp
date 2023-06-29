#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define VACIA "_"

struct ranura{
    string name;
    string password;
};


class login{
    private:
        int m;
        int registros;
        ranura *HT;
    public:
        login();
        ~login();
        bool iniciar_sesion(string usuario, string clave);      //revisa si existe el usuario en el diccionario
        bool crear_nuevo_usuario(string usuario, string clave); //agrega un usuario a el diccionario
        bool cambiar_clave(string usuario, string nueva_clave); //cambia la informacion del diccionario
        int h(string k, int M);    //  funcion de hashing
        void RevisarFactorDeCarga();
};

