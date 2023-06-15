#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

typedef string tipoClave; // tipo de clave de cada

typedef string tipoInfo; // tipo de valor de cada

int M=5;
#define VACIA -1
#define LIBERADA -2
#define R 2

struct ranura{
    tipoClave key;
    tipoInfo info;
};

/*
class UnsortedDict{
    private:
        ranura HT;
    public:

    UnsortedDict();

    ~UnsortedDict();

    tipoInfo get(tipoClave k);//             Obtiene el valor i almacenado en el registro (k,i)

    void insert(tipoClave k, tipoInfo i);//  Almacena un un registro (k, i) en el diccionario

    tipoInfo remove(tipoClave k);//          Elimina el registro (k,i) almacenado en el diccionario

    void clear();//                          Reinicializa el diccionario a uno vacío

    int size();//                            Retorna el número de registros almacenados
};
*/

class login{
    private:
        int m;
        int registros;
        ranura *usuarios;
        tipoClave *keys;
    public:
        login();
        ~login();
        bool iniciar_sesion(string usuario, string clave);
        bool crear_nuevo_usuario(string usuario, string clave);
        bool cambiar_clave(string usuario, string nueva_clave);
        int h(tipoClave k);
};