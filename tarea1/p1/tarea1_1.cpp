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



bool es_colaborador(char*rut){
    int n;
    bool flag=0;
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
            flag=1;
    }
    file.close();
    if (flag)
    return true;
    return false;
}



bool puedeConsumir(char* rut, int servicio, string consumos_dia){
    if (es_colaborador(rut))
        cout<<"es colaborador\n";
    else 
        cout<<"no es colaborador\n";
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