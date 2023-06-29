#include "login.hpp"


/*****
* constructor del hashing cerrado
******
* Metodo que crea e inicia el hashing vacio
******
* Input:
*   void
******
* Returns:
*   void
*****/

login::login(){
    m = 32;
    HT = new ranura[m];
    registros = 0;
    for (int i = 0; i < m; i++){
        HT[i].name = VACIA;
    }
}

/*****
* login::~login
******
* Metodo destructor de la tabla de hashing
******
* Input:
*   void
******
* Returns:
*   void
*****/

login::~login(){
    delete[] HT;
}

/*****
* int login::h
******
* Metodo que hashea la llave 
******
* Input:
*   string k : clave a hashear
*   int M : tamanio tabla de hashing
******
* Returns:
*   int : posicion a utilizar en la tabla
*****/

int login::h(string k,int M){
    int sum = 0;
    int pow_3 = 1;
    for (unsigned int i = 0; i < k.size(); i++){
        sum = (((int)(k[i] * pow_3)) % M + sum + M) % M;
        pow_3 *= 3;
    }
    return sum % M;
}

/*****
* int p
******
* funcion que tiene el proposito de solucionar colisiones
******
* Input:
*   string k : llave a guardar en la tabla
*   int i : cantidad de colisiones
******
* Returns:
*   int : un entero para cambiar la posicion otorgada por el hashing
*****/

int p(string k, int i){
    return 5 * i * i + 17 * i + 47;
}

/*****
* void login::RevisarFactorDeCarga
******
* Metodo que revisa el factor de carga de la tabla de hashing y agranda la tabla si es necesario
******
* Input:
*   void
******
* Returns:
*   void
*****/

void login::RevisarFactorDeCarga(){
    float alfa=registros/(float)m;
    int pos,inicio;
    if (alfa>=0.7){
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

/*****
* bool login::crear_nuevo_usuario
******
* metodo que crea una nueva ranura en la tabla, si cumple con los requisitos
******
* Input:
*   string nombre : futuro name de la nueva ranura
*   string contrasenia : futura password
******
* Returns:
*   bool : retorna true si es ingresado correctamente y false si no
*****/

bool login::crear_nuevo_usuario(string nombre, string contrasenia){
    int inicio, i;
    int pos = h(nombre,m);
    inicio = pos;
    for (i = 1; HT[pos].name != VACIA && HT[pos].name != nombre; i++){
        pos = (inicio + p(nombre, i)) % m;
    }
    if (HT[pos].name == nombre){
        cout << "El usuario ya se encuentra registrado\n";
        return 0;
    }
    if (contrasenia.size() > 7){
        HT[pos].name = nombre;
        HT[pos].password = contrasenia;
        cout << "Usuario "<<nombre<<" registrado con exito  \n";
        registros++;
        RevisarFactorDeCarga();
        return 1;
    }
    cout << "La clave debe tener al menos 8 caracteres\n";
    return 0;
}

/*****
* bool login::cambiar_clave
******
* Metodo que cambia la password de una ranura si cumple con los requisitos
******
* Input:
*   string nombre : es la llave de la tabla de hashing a la cual se le cambiara la contrasenia
*   string nueva_contrasenia : password a cambiar
******
* Returns:
*   bool : retorna falso si no cumple con los requisitos y verdadero si se logra cambiar la password
*****/

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
        cout<<"Clave actualizada con exito\n";
        return 1;
    }
    cout << "La clave debe tener al menos 8 caracteres\n";
    return 0;
}

/*****
* bool login::iniciar_sesion
******
* busca si la ranura con el respectivo nombre existe o no
******
* Input:
*   string nombre : posible name de la ranura
*   string contrasenia : posible password de la ranura
******
* Returns:
*   bool : true si los requisitos se cumplen false si no
*****/

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
