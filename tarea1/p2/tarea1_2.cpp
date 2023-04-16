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



/*
void print(Persona* personas){
    for (int i=0 ; i<p ; i++){
        cout<<personas[i].nombre<<" ";//                                esta funcion fue creada con el fin de ver que las pruebas funcionen bien
        for (int j=0 ; j<personas[i].tamanio_tarjeta ; j++)
            cout<<personas[i].tarjeta[j];
        cout<<"\n";
    }
}
*/



/*****
*   *int comprarTarjeta(string nombre, int dia, int &m)
*****
*   la funcion crea un array que es la tarjeta de la respectiva persona en base a su nombre y el dia (tiene el tamaño del nombre)
*****
*   input:
*   string nombre : un string con el nombre de la persona que comprara tarjeta
*   int dia : el numero de dia
*   int &m : es el largo del nombre, se pasa por referencia para que en la misma variable despues guardar el tamaño de la tarjeta
*****
*   return:
*       int*, retorna un puntero que apunta al primer valor de la tarjeta
*       por referencia, entrega el tamanio de la tarjeta
*****/

int* comprarTarjeta(string nombre, int dia, int &m){
    int* ret=new int[nombre.size()];
    for (unsigned int i=0 ; i<nombre.size() ; i++){
        ret[i] = nombre[i]%dia;
    }
    m=nombre.size();
    return ret;
}

/*****
*   void intercambiarTarjeta(Persona* p1, Persona* p2)
*****
*   la funcion intercambia las tarjetas de p1 y de p2 y hace que p1 ya no quiera intercambiar
*****
*   input:
*   Persona* p1 : un puntero a una persona que quiere cambiar
*   Persona* p2 : un puntero a una persona que quiere cambiar, esta despues de p1 y tiene por lo menos un numero en comun con p1
*****
*   return:
*       la funcion no retorna nada, solo cambia los valores de los punteros
*****/

void intercambiarTarjeta(Persona* p1, Persona* p2){
    int* copia = (*p1).tarjeta ,copiat = (*p1).tamanio_tarjeta;
    (*p1).tarjeta=(*p2).tarjeta;
    (*p1).tamanio_tarjeta=(*p2).tamanio_tarjeta;
    (*p2).tarjeta=copia;
    (*p2).tamanio_tarjeta=copiat;
    (*p1).quiere_intercambiar=0;
}

/*****
*   int puntaje(Persona* p1)
*****
*   calcula el puntaje de la persona p1
*****
*   input:
*   Persona* p1 : un puntero a una persona para calcular su puntaje en base a su fecha de nacimiento y a su tarjeta
*****
*   return:
*       int, retorna el puntaje que obtuvo
*****/

int puntaje(Persona* p1){
    int sum=0;
    for (int i=0; i<p1->tamanio_tarjeta ;i++)
        sum+= p1->tarjeta[i] * p1->fecha[i%10];
    return sum;
}

/*****
*   bool numero_comun(Persona a, Persona b, int tamanio)
*****
*   verifica si dos personas tienen por lo menos un numero en comun de su tarjeta
*****
*   input:
*   Persona a : una persona de la cual compararemos su tarjeta
*   persona b : la otra persona llamada a comparar tarjeta
*   int tamanio : el menor tamanio entre las dos tarjetas
*****
*   return:
*       bool, retorna verdadero si tienen un numero en comun y en el caso contrario retorna falso
*****/

bool numero_comun(Persona a, Persona b, int tamanio){//                         variable creada para ver si tienen por lo menos 1 numero en comun
    for(int i=0 ; i<tamanio ; i++)
        if(a.tarjeta[i]==b.tarjeta[i])
            return 1;
    return 0;  
}

/*****
*   Persona* unDia(Persona* personas, int dia)
*****
*   hace que todas las personas compren su tarjeta diaria, luego hace que se intercambien cuando cumplan los requisitos, luego verifica a el ganador
*****
*   input:
*   Persona* personas : un arreglo de p personas
*   int dia : el numero de dia
*****
*   return:
*       Persona*, retorna un puntero a la persona ganadora del dia
*****/

Persona* unDia(Persona* personas, int dia){

    for(int i=0 ; i<p ; i++){//                                                 se compran las tarjetas para todas las personas del arr y se guarda su respectiva tarjeta y el tamaño de esta
        int m=(personas[i].nombre).size();
        personas[i].tarjeta=comprarTarjeta(personas[i].nombre, dia, m);
        personas[i].tamanio_tarjeta=m;
    }
/*
    cout<<"dia = "<<dia<<"\n";
    print(personas);
    cout<<"\n";
*/
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
                        if(numero_comun(personas[i],personas[j],tamanio)){//    variable creada para ver si tienen por lo menos 1 numero en comun
                            intercambiarTarjeta(&personas[i],&personas[j]);
                            sigo=1;//                                           la flag seguira siendo 1 si por lo menos una persona cambio
                        }
                    }
                }
            }
        }
    }
/*
    cout<<"despues del intercambio:\n";
    print(personas);
    cout<<"\n";
*/
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

/*****
*   void variosDias(Persona* personas, int cant_dias)
*****
*   hace que la funcion unDia se pueda ejecutar un numero determinado de veces y imprime por pantalla al ganador con su fecha de nacimiento y su puntaje
*****
*   input:
*   Persona* personas : un arreglo de p personas
*   int cant_dia : el numero de dias totales
*****
*   return:
*       no retorna nada
*****/

void variosDias(Persona* personas, int cant_dias){
    Persona* ganador;
    for(int i=1;i<=cant_dias;i++){
        ganador=unDia(personas,i);
        cout<<ganador->nombre<<"    "<<ganador->fecha<<"    "<<puntajemax<<"\n\n";
    }
}

int main(){

    cin>>p;
    Persona personas[p];
    for(int i=0;i<p;i++){
        cin>>personas[i].nombre;
        cin>>personas[i].fecha;
        cin>>personas[i].quiere_intercambiar;
    }
/*                                                  main utilizado para las pruebas con el archivo "arch.txt"
    ifstream file;
    file.open("arch.txt");
    file>>p;
    Persona personas[p];
    for(int i=0;i<p;i++){
        file>>personas[i].nombre;
        file>>personas[i].fecha;
        file>>personas[i].quiere_intercambiar;
    }
*/
    variosDias(personas,p);
    return 0;
}