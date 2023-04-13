#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Persona {
    string nombre ;
    char fecha [11];
    int tamanio_tarjeta ;
    int * tarjeta ;
    bool quiere_intercambiar ;
};

int* comprarTarjeta(string nombre, int dia, int &m){        //  creo que esta mal
    int* tarjeta=new int[nombre.size()];
    for (unsigned int i=0 ; i<nombre.size() ; i++){
        tarjeta[i] = nombre[i]%dia;
    }
    m=nombre.size();
    return tarjeta;
}

void intercambiarTarjeta(Persona* p1, Persona* p2){         // tambien creo q esta mal
    int* copia = (*p1).tarjeta ;
    (*p1).tarjeta=(*p2).tarjeta;
    (*p2).tarjeta=copia;
    (*p1).quiere_intercambiar=0;
}

int puntaje(Persona* p1){

}

Persona* unDia(Persona* personas, int dia){

}

void variosDias(Persona* personas, int cant_dias){

}

int main(){
    int dia,m,*var;
    string nombre;
    cin>>nombre;
    cin>>dia;
    m=nombre.length();
    var=comprarTarjeta(nombre,dia,m);
    for(int i=0;i<m;i++){
        cout<<var[i];
    }
    cout<<"\n";
    return 0;
}