#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definición de la estructura de un nodo de la lista enlazada

struct Nodo {
    char nucleotido;
    Nodo* siguiente;
};

/*****
*   void insertarNodo(Nodo*& cabeza, char nucleotido)
******
*   Función para insertar un nodo al final de la lista enlazada
******
* Input:
*   secuencia y nucleotido
******
* Returns:
*   inserta nodo dentro de la secuencia 
*****/

void insertarNodo(Nodo*& cabeza, char nucleotido) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->nucleotido = nucleotido;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

/*****
*   void imprimirLista(Nodo* cabeza, ofstream& archivoSalida)
******
*   Función para imprimir la lista enlazada
******
* Input:
*   secuencia
******
* Returns:
*   imprime la lista de secuencia en el archivo de salida ("secuencias-reconstruidas.txt")
*****/

void imprimirLista(Nodo* cabeza, ofstream& archivoSalida) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        archivoSalida << temp->nucleotido;
        temp = temp->siguiente;
    }
    archivoSalida << endl;
}

/*****
*   void insertar(Nodo*& cabeza, int posicion, char nucleotido)
******
*   Función para realizar la operación de inserción en la lista enlazada
******
* Input:
*   secuencia y operacion de INSERTAR acompañado de la posición y el nucleotido respectivo
******
* Returns:
*   modifica la secuencia agregando la nueva inserción
*****/

void insertar(Nodo*& cabeza, int posicion, char nucleotido) {
    if (posicion == 0) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->nucleotido = nucleotido;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        for (int i = 0; i < posicion - 1 && temp != nullptr; i++) {
            temp = temp->siguiente;
        }
        if (temp != nullptr) {
            Nodo* nuevoNodo = new Nodo;
            nuevoNodo->nucleotido = nucleotido;
            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        }
    }
}


/*****
*   void borrar(Nodo*& cabeza, int posicion)
******
*   Función para realizar la operación de borrado en la lista enlazada
******
* Input:
*   secuencia y operacion de BORRAR acompañado de la posición i
******
* Returns:
*   modifica la secuencia borrando el nucleotido de la posición i respectiva
*****/

void borrar(Nodo*& cabeza, int posicion) {
    if (posicion == 0) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    else {
        Nodo* temp = cabeza;
        for (int i = 0; i < posicion - 1 && temp != nullptr; i++) {
            temp = temp->siguiente;
        }
        if (temp != nullptr && temp->siguiente != nullptr) {
            Nodo* nodoBorrar = temp->siguiente;
            temp->siguiente = nodoBorrar->siguiente;
            delete nodoBorrar;
        }
    }
}

/*****
*   void intercambiar(Nodo* cabeza, int posicion, char nucleotido)
******
*   Función para realizar la operación de intercambio en la lista enlazada
******
* Input:
*   secuencia y operacion de INTERCAMBIAR acompañado de la posición i y un nucleotido por la base n
******
* Returns:
*   modifica la secuencia intercambiando el nucleotido por el otro
*****/

void intercambiar(Nodo* cabeza, int posicion, char nucleotido) {
    Nodo* temp = cabeza;
    for (int i = 0; i < posicion && temp != nullptr; i++) {
        temp = temp->siguiente;
    }
    if (temp != nullptr) {
        temp->nucleotido = nucleotido;
    }
}

int main() {
    int l, k;
    string secuenciaBase;
    ifstream archivoEntrada("secuencias-nucleotidos.txt");
    ofstream archivoSalida("secuencias-reconstruidas.txt");

    if (archivoEntrada.is_open()) {
        archivoEntrada >> l;
        archivoEntrada >> secuenciaBase;
        archivoEntrada >> k;

        /***** Construir la secuencia base *****/
        Nodo* cabeza = nullptr;
        for (char nucleotido : secuenciaBase) {
            insertarNodo(cabeza, nucleotido);
        }

        /***** Realizar las modificaciones *****/
        for (int i = 0; i < k; i++) {
            int m;
            archivoEntrada >> m;
            archivoEntrada.ignore();  /***** Ignorar el salto de línea *****/

            for (int j = 0; j < m; j++) {
                string tipoOperacion;
                int posicion;
                char nucleotido;

                archivoEntrada >> tipoOperacion >> posicion;

                if (tipoOperacion == "INSERTAR") {
                    archivoEntrada >> nucleotido;
                    insertar(cabeza, posicion, nucleotido);
                }
                if (tipoOperacion == "BORRAR") {
                    borrar(cabeza, posicion);
                }
                if (tipoOperacion == "INTERCAMBIAR") {
                    archivoEntrada >> nucleotido;
                    intercambiar(cabeza, posicion, nucleotido);
                }

                archivoEntrada.ignore(); /***** Ignorar el salto de línea *****/
            }

            /***** Imprimir la secuencia reconstruida en el archivo de salida *****/
            imprimirLista(cabeza, archivoSalida);

            /***** Restaurar la secuencia base para la siguiente reconstrucción *****/
            Nodo* temp = nullptr;
            while (cabeza != nullptr) {
                temp = cabeza;
                cabeza = cabeza->siguiente;
                delete temp;
            }

            /***** Reconstruir la secuencia base *****/
            for (char nucleotido : secuenciaBase) {
                insertarNodo(cabeza, nucleotido);
            }
        }

        archivoEntrada.close();
        archivoSalida.close();
    }
    else {
        cout << "No se pudo abrir el archivo de entrada." << endl;
    }

    return 0;
}