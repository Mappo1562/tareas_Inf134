#include <iostream>
#include <fstream>
using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

int const R = 10;

struct SaldoColaborador {
char rut [11];
int saldo_desayuno ;
int saldo_almuerzo ;
int saldo_once ;
int saldo_cena ;
};

/*
void print(char *rut){
    for (int i=0 ; i<R ; i++){
        cout<<rut[i];
    }
    cout<<"\n";
}
*/



bool puedeConsumir(char* rut, int servicio, string consumos_dia){

}




int main(){

    char rut[R],n;
    for (int i=0 ; i<R ; i++){
        cin>>n;
        rut[i]=n;
    }
    cout<<"\n";
    print(rut);
    return 0;
}



/*
43
56
*/