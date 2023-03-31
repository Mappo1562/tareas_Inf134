#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void open(){
    ofstream file;
    file.open("data.dat",ios::binary);
    char *s="13314801-9 DESAYUNO";
    file.write(s,20*sizeof(char));
    file.close();
}

void leer(){
    ifstream file;
    int i;
    file.open("data.dat",ios::binary);
    file.read((char*)&i, 20*sizeof(char));
    cout<<i;
    file.close();
}

int main(){
    cout<<"todo funciona \n";
    //open();
    //leer();
    return 0;
}