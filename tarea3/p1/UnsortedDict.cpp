#include "UnsortedDict.hpp"
/*
UnsortedDict::UnsortedDict(){

}

UnsortedDict::~UnsortedDict(){

}

tipoInfo UnsortedDict::get(tipoClave k){

}

void UnsortedDict::insert(tipoClave k, tipoInfo i){

}

tipoInfo remove(tipoClave k){

}

void UnsortedDict::remove(tipoClave k){

}

void UnsortedDict::clear(){

}

int UnsortedDict::size(){
    
}
*/

int login::h(tipoClave k){
    int sum=0;
    for(int i=0;i=0<k.length();i++)
        sum+=(int)k[i]*3;
    return sum%m;
}

login::login(){
    m=32;
    usuarios=new ranura[m];
    keys=new tipoClave[m];
    registros=0;
}

login::~login(){
    delete[]usuarios;
    delete[]keys;
    registros=0;
}

bool login::iniciar_sesion(string usuario, string clave){

}

bool login::crear_nuevo_usuario(string usuario, string clave){
    int inicio, i;
    int pos = inicio = h(clave);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
    if (HT[pos].clave == k)
        return 0; // inserción no exitosa: clave repetida
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1; // inserción exitosa
    }

}

bool login::cambiar_clave(string usuario, string nueva_clave){

}