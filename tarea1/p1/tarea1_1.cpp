#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

int const R = 11;
int NUMERO_CONSUMOS_DIARIOS=6;


struct SaldoColaborador {
char rut [11];
int saldo_desayuno ;
int saldo_almuerzo ;
int saldo_once ;
int saldo_cena ;
};


struct consumos{
    char rut[R];
    string tipo;
};


int conseguir_saldo(char*rut,int servicio_numerico){//                            la idea es que retorne la cantidad de saldo que tiene para el servicio que quiere, si no es colaborador retorna 0
    int n,saldo=0;
    ifstream file;
    SaldoColaborador cliente;
    file.open("saldos.bin",ios::binary);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file.read((char*)&n, sizeof(int));
    cout<<"n = "<<n<<" \n";
    for(int i=0 ; i<n ; i++){
        file.read((char*)&cliente, sizeof(SaldoColaborador));
        if (!strcmp(cliente.rut,rut))
            if (0==servicio_numerico)
                saldo=cliente.saldo_desayuno;
            else if (1==servicio_numerico)
                saldo=cliente.saldo_almuerzo;
            else if (2==servicio_numerico)
                saldo=cliente.saldo_once;
            else if (3==servicio_numerico)
                saldo=cliente.saldo_cena;
    }
    file.close();
    return saldo;
}
                              


string identificar_servicio(int servicionumerico){//        entrega un string en mayusculas listo para ser comparado con el archivo txt
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
    return servicio;
}



int gastos(string servicio,string consumos_dia,char* rut,int saldo){//              calcula cuantos servicios del mismo tipo ha usado en el dia
    ifstream file;
    string tipo,run;
    int contador=0,flag;
    file.open(consumos_dia);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    for (int i=0;i<NUMERO_CONSUMOS_DIARIOS;i++){
        file >> run;
        file >>tipo;
        flag=1;
        for (int j=0;j<R;j++){
            if (rut[j]!=run[j])
                flag=0;
        }
        if (flag){
            if (tipo==servicio)
                contador++;
        }
    }
    file.close();
    return contador;
}



bool puedeConsumir(char* rut, int servicionumerico, string consumos_dia){
    int saldo;
    string servicio;

    saldo=conseguir_saldo(rut,servicionumerico);

    if (!saldo)//   retorna falso para todos los que no son colaboradores o a los que no tienen saldo
        return 0;


    servicio=identificar_servicio(servicionumerico);

    int n=gastos(servicio , consumos_dia , rut , saldo);

    cout<<"el cliente ha utilizado "<<n<<" "<<servicio<<"\n";




    return false;
}



int main(){
    char r[R]="33333333-3";
    puedeConsumir(r,1,"consumosdia.txt");
    return 0;
}





/*
http://jbgarcia.webs.uvigo.es/asignaturas/TO/cursilloCpp/14_archivos.html
*/