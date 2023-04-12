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

int* comprarTarjeta(string nombre, int dia, int &m){
    int ret[m];
    for (int i=0 ; i<m ; i++){
        ret[i]=nombre[i]%dia;
    }
    return ret;
}

void intercambiarTarjeta(Persona* p1, Persona* p2){

}

int puntaje(Persona* p1){

}

Persona* unDia(Persona* personas, int dia){

}

void variosDias(Persona* personas, int cant_dias){

}

int main(){
    ifstream file;
    int n,tamanio;
    string nombre,fecha;
    bool cambia;
    file.open("ejemplos.txt");
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file>>n;
    for (int i=0;i<n;i++){
        file>>nombre;
        file>>fecha;
        file>>cambia;
        file>>tamanio;
        cout<<comprarTarjeta(nombre,dia,tamanio)
    }
    return 0;
}