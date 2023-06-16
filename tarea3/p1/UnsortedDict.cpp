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

void login::init() {
    for(int i = 0; i < m; i++) {
        HT[i].name = VACIA;
    }
}

login::login(){
    m=32;
    HT=new ranura[m];
    keys=new string[m];
    registros=0;
}



login::~login(){
    delete[]HT;
    delete[]keys;
}

int login::h(string k) {
    int sum = 0;
    int pow_3 = 1;
    for(int i = 0; i < k.size(); i++){
        sum = (((int) (k[i] * pow_3)) % m + sum + m) % m;
        pow_3 *= 3;
    }
    cout<<"m= "<<m<<", sum= "<<sum<<", hashing= "<<sum%m<<"\n";
    return sum%m;
}

int p(string k, int i) {
    return 5 * i * i + 17 * i + 47;
}

bool login::crear_nuevo_usuario(string nombre, string contrasenia){
    int inicio, i;
    int pos = h(nombre);
    inicio=pos;
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != nombre && i<=m; i++) {
        cout<<HT[pos].name<<"sexo\n";
        cout<<"estoy en el for por "<<i<<" vez\n";
        cout << nombre << " hizo colision\n";
        pos = (inicio + p(nombre, i)) % m;
    }
    if (HT[pos].name == nombre){
        cout<<"El usuario ya se encuentra registrado";
        return 0; 
    }
    if(contrasenia.size()>7){
        HT[pos].name = nombre;
        HT[pos].password = contrasenia;
        cout<<"Usuario registrado con exito";
        //ver el factor de carga alfa pag 51 ppt
        //revisarFactorDeCarga()
        return 1;
    }
    cout<<"La clave debe tener al menos 8 caracteres";
    return 0;
}

bool login::cambiar_clave(string nombre, string nueva_contrasenia){
    int inicio, i;
    int pos = inicio = h(nombre);
    return 1;
}


void login::eliminar() {
    for(int i = 0; i < m; i++) {
        if(HT[i].name != VACIA && HT[i].name != LIBERADA) {
            cout << "clave: " << HT[i].name << " " 
                 << "info: " << HT[i].password << "\n";
        }
    }
}






/*
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
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != usuario; i++)
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
*/