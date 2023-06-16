#include "UnsortedDict.hpp"


void login::init(){
    for (int i = 0; i < m; i++){
        HT[i].name = VACIA;
    }
}

login::login(){
    m = 32;
    HT = new ranura[m];
    registros = 0;
}

login::~login()
{
    delete[] HT;
}

int login::h(string k,int M)
{
    int sum = 0;
    int pow_3 = 1;
    for (int i = 0; i < k.size(); i++)
    {
        sum = (((int)(k[i] * pow_3)) % M + sum + M) % M;
        pow_3 *= 3;
    }
    return sum % M;
}

int p(string k, int i)
{
    return 5 * i * i + 17 * i + 47;
}


void login::RevisarFactorDeCarga(){
    float alfa=registros/(float)m;
    int pos,inicio;
    if (alfa>=0.7){
        cout<<"vamo a crecer carajooooooooooooooooooo\n";
        ranura aux[m*2];
        for (int i = 0; i < m*2; i++){
            aux[i].name = VACIA;
        }
        int nuevoTamanio = m * 2;
        for (int i=0;i<m;i++){
            if (HT[i].name!=VACIA){
                inicio=pos=h(HT[i].name,nuevoTamanio)%nuevoTamanio;
                for (int j=1; HT[i].name!=aux[pos].name && aux[pos].name!=VACIA; j++){
                    pos = (inicio + p(HT[i].name, j)) % nuevoTamanio;
                }
                aux[pos].name=HT[i].name;
                aux[pos].password=HT[i].password;
            }
        }
        m=nuevoTamanio;
        delete [] HT;
        HT= new ranura[nuevoTamanio];
        for(int i=0;i<m;i++){
            if(aux[i].name!=VACIA){
                HT[i].name=aux[i].name;
                HT[i].password=aux[i].password;
            }
            else
                HT[i].name=VACIA;
        }
        return;
    }
}




bool login::crear_nuevo_usuario(string nombre, string contrasenia){
    int inicio, i;
    int pos = h(nombre,m);
    inicio = pos;
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != nombre; i++){
        cout << nombre << " hizo colision\n";
        pos = (inicio + p(nombre, i)) % m;
    }
    if (HT[pos].name == nombre){
        cout << "El usuario ya se encuentra registrado\n";
        return 0;
    }
    if (contrasenia.size() > 7){
        HT[pos].name = nombre;
        HT[pos].password = contrasenia;
        cout << "Usuario "<<nombre<<" registrado con exito, registros= "<<registros<<"  \n";
        registros++;
        RevisarFactorDeCarga();
        return 1;
    }
    cout << "La clave debe tener al menos 8 caracteres\n";
    return 0;
}

bool login::cambiar_clave(string nombre, string nueva_contrasenia)
{
    int inicio, i;
    int pos = inicio = h(nombre,m);
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != nombre; i++){
        pos = (inicio + p(nombre, i)) % m;
    }
    if (HT[pos].name == VACIA){
        cout << "El usuario no se encuentra registrado\n";
        return 0;
    }
    else if (nueva_contrasenia.size() > 7){
        HT[pos].password = nueva_contrasenia;
        return 1;
    }
    cout << "La clave debe tener al menos 8 caracteres\n";
    return 0;
}

void login::eliminar(){
    for (int i = 0; i < m; i++){
        if (HT[i].name != VACIA){
            cout << "clave: " << HT[i].name << " "<< "info: " << HT[i].password << "\n";
        }
    }
    cout << "total de registros= " << registros << "\n";
}

bool login::iniciar_sesion(string nombre, string contrasenia){
    int inicio, i;
    int pos = inicio = h(nombre,m);
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != nombre; i++){
        pos = (inicio + p(nombre, i)) % m;
    }
    if (HT[pos].name == VACIA){
        cout << "El usuario no se encuentra registrado\n";
        return 0;
    }
    else if (contrasenia == HT[pos].password)
    {
        cout << "Sesion iniciada con exito\n";
        return 1;
    }
    cout << "La clave ingresada no coincide\n";
    return 0;
}
