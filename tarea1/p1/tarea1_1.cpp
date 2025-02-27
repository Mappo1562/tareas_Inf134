#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;


int const R = 11;


struct SaldoColaborador {
char rut [11];
int saldo_desayuno ;
int saldo_almuerzo ;
int saldo_once ;
int saldo_cena ;
};


/*****
*   int conseguir_saldo(char*rut,int servicio_numerico)
*****
*   hace que la funcion unDia se pueda ejecutar un numero determinado de veces y imprime por pantalla al ganador con su fecha de nacimiento y su puntaje
*****
*   input:
*   int servicio_numerico : un numero que representa el servicio que quiere la persona
*   char *rut : un arreglo con el rut del posible colaborador
*****
*   return:
*       int, retorna la cantidad de saldo que tiene para el servicio que quiere, si no es colaborador retorna 0
*****/

int conseguir_saldo(char*rut,int servicio_numerico){//                              retorna la cantidad de saldo que tiene para el servicio que quiere, si no es colaborador retorna 0
    int n,saldo=0;
    ifstream file;
    SaldoColaborador cliente;
    file.open("saldos.bin",ios::binary);

    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file.read((char*)&n, sizeof(int));

    for(int i=0 ; i<n ; i++){
        file.read((char*)&cliente, sizeof(SaldoColaborador));
        if (!strcmp(cliente.rut,rut)){

            if (0==servicio_numerico)
                saldo=cliente.saldo_desayuno;

            else if (1==servicio_numerico)
                saldo=cliente.saldo_almuerzo;

            else if (2==servicio_numerico)
                saldo=cliente.saldo_once;

            else if (3==servicio_numerico)
                saldo=cliente.saldo_cena;
        }
    }
    file.close();
    return saldo;
}
                              

/*****
*   string identificar_servicio(int servicionumerico)
*****
*   pasa el numero a un string escrito de la misma manera que estan escritos en el archivo txt
*****
*   input:
*   int servicio_numerico : un numero que representa el servicio que quiere la persona
*****
*   return:
*       string, entrega un string en mayusculas listo para ser comparado con el archivo txt
*****/


string identificar_servicio(int servicionumerico){//                                entrega un string en mayusculas listo para ser comparado con el archivo txt
    string servicio;
    if (servicionumerico==SERV_DESAYUNO){
        servicio="DESAYUNO";
    }
    else if (servicionumerico==SERV_ALMUERZO){
        servicio="ALMUERZO";
    }
    else if (servicionumerico==SERV_ONCE){
        servicio="ONCE";
    }
    else if (servicionumerico==SERV_CENA){
        servicio="CENA";
    }
    else servicio="NO EXISTE";
    return servicio;
}


/*****
*   int gastos(string servicio,string consumos_dia,char* rut)
*****
*   calcula cuantos servicios iguales ha tenido en el dia
*****
*   input:
*   string servicio : un string en matusculas con el servicio pedido por la persona
*   string consumos_dia : un string con el respectivo nombre del archivo txt
*   char rut : un arreglo con el rut de la persona
*****
*   return:
*       int, retorna cuantos servicios del mismo tipo ha usado en el dia
*****/


int gastos(string servicio,string consumos_dia,char* rut){//              calcula cuantos servicios del mismo tipo ha usado en el dia
    ifstream file;
    string tipo,run;
    int contador=0,flag;
    file.open(consumos_dia);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    while (file >> run){
        file >>tipo;
        flag=1;
        for (int j=0;j<R;j++){//                                                    comparamos el string run con el arreglo de caracteres rut
            if (rut[j]!=run[j]){
                flag=0;
                break;
            }
        }
        if (flag){
            if (tipo==servicio)
                contador++;
        }
    }
    file.close();
    return contador;
}


/*****
*   void actualizartxt(char* rut, string servicio, string consumos_dia)
*****
*   luego de hacer el pedido esta funcion actualiza el archivo txt con el nuevo consumo
*****
*   input:
*   char rut : un arreglo con el rut de la persona
*   string servicio : un string en matusculas con el servicio pedido por la persona
*   string consumos_dia : un string con el respectivo nombre del archivo txt
*****
*   return:
*       no retorna nada
*****/


void actualizartxt(char* rut, string servicio, string consumos_dia){//              como el nombre lo dice actualiza el archivo .txt con el nuevo consumo
    fstream file;
    file.open(consumos_dia, ios::app);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file<<rut<<" "<<servicio<<"\n";
    file.close();
}


/*****
*   void creartxt(string consumos_dia)
*****
*   revisa si el archivo txt con el nombre de consumos_dia existe, y si no lo crea
*****
*   input:
*   string consumos_dia : un string con el respectivo nombre del archivo txt
*****
*   return:
*       no retorna nada
*****/


void creartxt(string consumos_dia){
    fstream file;
    file.open(consumos_dia, ios::app);
    if(!file.is_open()){
        fstream crear;
        crear.open(consumos_dia, ios::out);
        crear.close();
        return;
    }
    file.close();
}


/*****
*   bool puedeConsumir(char* rut, int servicionumerico, string consumos_dia)
*****
*   revisa si el usuario puede consumir un respectivo servicio o no
*****
*   input:
*   char rut : un arreglo con el rut de la persona
*   int servicio_numerico : un numero que representa el servicio que quiere la persona
*   string consumos_dia : un string con el respectivo nombre del archivo txt
*****
*   return:
*       bool, retorna verdadero si puede consumir y falso si no
*****/


bool puedeConsumir(char* rut, int servicionumerico, string consumos_dia){
    int saldo,gasto;
    string servicio;
      
    saldo=conseguir_saldo(rut,servicionumerico);

    if (!saldo)//                                               retorna falso para todos los que no son colaboradores o a los que no tienen saldo
        return 0;

    servicio=identificar_servicio(servicionumerico);

    if (servicio=="NO EXISTE")//                                retorna falso si el servicio pedido no existe
        return 0;


    creartxt(consumos_dia);
    gasto=gastos(servicio , consumos_dia , rut );


    if (saldo-gasto<=0)//                                       retorna falso si ya utilizo todo su saldo
        return 0;
    
    actualizartxt(rut , servicio, consumos_dia);

    return 1;
}



int main(){
    char rut[R];
    int servicio;
    string nombre;
    cout<<"Zona de pruebas \n";
    cout<<"el nombre del archivo del dia usa formato x.txt donde x es un string random";
    do{
        cout<<"ingrese el nombre del archivo del dia:";cin>>nombre;
        cout<<"rut: ";cin>>rut;
        cout<<"numero servicio: ";cin>>servicio;
        if (puedeConsumir(rut,servicio,nombre))
            cout<<"puede consumir\n";
        else
            cout<<"no puede consumir\n";
    }while(servicio!=4);
    return 0;
}

