#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

typedef int tipoClave; // tipo de clave de cada

typedef int tipoInfo; // tipo de valor de cada


class UnsortedDict{
    private:

    public:

    UnsortedDict();

    ~UnsortedDict();

    tipoInfo get(tipoClave k)//             Obtiene el valor i almacenado en el registro (k,i)

    void insert(tipoClave k, tipoInfo i)//  Almacena un un registro (k, i) en el diccionario

    tipoInfo remove(tipoClave k)//          Elimina el registro (k,i) almacenado en el diccionario

    void clear()//                          Reinicializa el diccionario a uno vacío

    int size()//                            Retorna el número de registros almacenados
};