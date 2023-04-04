#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int const R = 10;


/*
void open(){
    ofstream file;
    file.open("saldos.bin",ios::binary);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char *s="13314801-9 DESAYUNO";
    file.write(s,20*sizeof(char));
    file.close();
}
*/

void leer(){
    ifstream file;
    int n,b;
    char a[R];
    file.open("saldos.bin",ios::binary | ios::in);
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    file.read((char*)&n, sizeof(int));
    cout<<"n = "<<n<<" \n";

    for(int i=0;i<n;i++){
        file.read((char*)&a,R*sizeof(char));

        for (int j=0;j<R;j++){
            cout<<a[j];
        }
        
        file.read((char*)&b, sizeof(int));
        cout<<"\n";
    }
    file.close();
}



int main(){
    cout<<"todo funciona \n";
    //open();
    leer();
    return 0;
}