#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int p;
int puntajemax;

struct Persona {
    string nombre ;
    char fecha [11];
    int tamanio_tarjeta ;
    int * tarjeta ;
    bool quiere_intercambiar ;
};

void print(Persona* personas){
    for (int i=0 ; i<p ; i++){
        cout<<personas[i].nombre<<" ";
        for (int j=0 ; j<personas[i].tamanio_tarjeta ; j++)
            cout<<personas[i].tarjeta[j];
        cout<<"\n";
    }
}



int* comprarTarjeta(string nombre, int dia, int &m){
    int* ret=new int[nombre.size()];
    for (unsigned int i=0 ; i<nombre.size() ; i++){
        ret[i] = nombre[i]%dia;
    }
    m=nombre.size();
    return ret;
}

void intercambiarTarjeta(Persona* p1, Persona* p2){//                   se necesita trabajar esta funcion ya que el dia 1 no da lo mismo del ejemplo
    int* copia = (*p1).tarjeta ;
    (*p1).tarjeta=(*p2).tarjeta;
    (*p2).tarjeta=copia;
    (*p1).quiere_intercambiar=0;
}

int puntaje(Persona* p1){
    int sum=0;
    for (int i=0; i<p1->tamanio_tarjeta ;i++)
        sum+= p1->tarjeta[i] * p1->fecha[i%10];
    return sum;
}

bool numero_comun(Persona a, Persona b, int tamanio){
    for(int i=0 ; i<tamanio ; i++)
        if(a.tarjeta[i]==b.tarjeta[i])
            return 1;
    return 0;  
}

Persona* unDia(Persona* personas, int dia){

    for(int i=0 ; i<p ; i++){//                                                 se compran las tarjetas para todas las personas del arr y se guarda su respectiva tarjeta y el tamaño de esta
        int m=(personas[i].nombre).size();
        personas[i].tarjeta=comprarTarjeta(personas[i].nombre, dia, m);
        personas[i].tamanio_tarjeta=m;
    }

    cout<<"dia = "<<dia<<"\n";
    print(personas);
    cout<<"\n";

    bool sigo=1;
    while(sigo){//                                                              ciclos para cambios de tarjetas
        sigo=0;
        for(int i=0 ; i<p ; i++){
            if (personas[i].quiere_intercambiar){
                for(int j=0 ; j<p ; j++){
                    if(personas[j].quiere_intercambiar && j!=i){
                        int tamanio;
                        if (personas[i].tamanio_tarjeta < personas[j].tamanio_tarjeta)
                            tamanio=personas[i].tamanio_tarjeta;
                        else
                            tamanio=personas[j].tamanio_tarjeta;
                        if(numero_comun(personas[i],personas[j],tamanio)){
                            intercambiarTarjeta(&personas[i],&personas[j]);
                            sigo=1;//                                           la flag seguira siendo 1 si por lo menos una persona cambio
                        }
                    }
                }
            }
        }
    }

    cout<<"despues del intercambio:\n";
    print(personas);
    cout<<"\n";

    Persona* ganador=&personas[0];
    puntajemax=puntaje(ganador);
    for(int i=0 ; i<p ; i++){
        int puntos=puntaje(&personas[i]);
        if (puntos>puntajemax){
            ganador=&personas[i];
            puntajemax=puntos;
        }
    }

    return ganador;
}

void variosDias(Persona* personas, int cant_dias){
    Persona* ganador;
    for(int i=1;i<=cant_dias;i++){
        ganador=unDia(personas,i);
        cout<<ganador->nombre<<"    "<<ganador->fecha<<"    "<<puntajemax<<"\n\n";
    }
}

int main(){
/*
    cin>>p;
    Persona personas[p];
    for(int i=0;i<p;i++){
        cin>>personas[i].nombre;
        cin>>personas[i].fecha;
        cin>>personas[i].quiere_intercambiar;
    }
*/
    ifstream file;
    file.open("arch.txt");
    file>>p;
    Persona personas[p];
    for(int i=0;i<p;i++){
        file>>personas[i].nombre;
        file>>personas[i].fecha;
        file>>personas[i].quiere_intercambiar;
    }
    variosDias(personas,2);
    return 0;
}