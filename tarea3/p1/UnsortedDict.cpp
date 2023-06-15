#include "UnsortedDict.hpp"

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

login::login(){
    m=32;
    usuarios=new ranura[m];
    claves=new tipoClave[m];
    registros=0;
}

~login::login(){
    usuarios.delete[];
    claves.delete[];
    registros=0;
}