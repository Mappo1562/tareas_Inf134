#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

typedef int tipoClave; // tipo de clave de cada

typedef int tipoInfo; // tipo de valor de cada

#define VACIA -1
#define LIBERADA -2
#define R 2

struct ranura{
    tipoClave key;
    tipoInfo info;
};


class UnsortedDict{
    private:
        ranura HT[M];
    public:

    UnsortedDict();

    ~UnsortedDict();

    tipoInfo get(tipoClave k)//             Obtiene el valor i almacenado en el registro (k,i)

    void insert(tipoClave k, tipoInfo i)//  Almacena un un registro (k, i) en el diccionario

    tipoInfo remove(tipoClave k)//          Elimina el registro (k,i) almacenado en el diccionario

    void clear()//                          Reinicializa el diccionario a uno vacío

    int size()//                            Retorna el número de registros almacenados
};


class login(){
    private:
        int m;
        int registros;
        ranura usuarios[];
        tipoClave claves[];
    public:
        login();
        ~login();
        bool iniciar_sesion(string usuario, string clave);
        bool crear_nuevo_usuario(string usuario, string clave);
        bool cambiar_clave(string usuario, string nueva_clave);

}