# tareas_Inf134

tarea 1:
3.1)
    Una cierta empresa ha adquirido unos dispositivos con reconocimiento facial para la entrega de tickets
de alimentación en el casino. Un colaborador podrá acercarse a uno de estos dispositivos y obtener su ticket
si no ha superado su saldo diario por servicio. La obtención de un ticket se considerará como un “consumo”.
Cada colaborador podrá sacar un número de tickets limitado por su saldo en cada servicio del casino
(desayuno, almuerzo, once y cena). Dicho saldo puede variar para cada colaborador y servicio.
El dispositivo al captar un rostro, tratará de emparejarlo con un colaborador. En caso de reconocerlo,
entregará su RUT, en caso contrario, el string vacío. El RUT debe ser usado para la verificación del saldo y
registrar el consumo.

    3.1.1. Consideraciones

Considere las siguientes constantes que permiten identificar cada uno de los servicios de alimentación.

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

Considere el struct SaldoColaborador presentado a continuación que almacena para un colaborador
el saldo para cada uno de los servicios. Los valores de saldo en este struct no se actualizan, sino que solo se
consultan. El valor de cada saldo será mayor o igual a cero.

struct SaldoColaborador {
char rut [11];
int saldo_desayuno ;
int saldo_almuerzo ;
int saldo_once ;
int saldo_cena ;
}

El dispositivo registra los consumos de cada día en un archivo ASCII con un nombre arbitrario. En cada
línea del archivo se guardan, separados por espacios, el RUT y el servicio en que se realizó ese consumo. Para
cada servicio se guarda el nombre del servicio en mayúsculas. Notar que este archivo es creado al registrar
el primer consumo del día. A continuación se entrega un ejemplo de este archivo con cinco consumos:

13314801 -9 DESAYUNO
13314801 -9 ALMUERZO
03686224 -6 ONCE
78927357 -k CENA
03686224 -6 ONCE


Por otro lado, el dispositivo guarda la información de los saldos de cada colaborador en un archivo
binario llamado saldos.bin que primero guarda un entero n y luego n structs SaldoColaborador ordenados
lexicográficamente. En caso de que un colaborador no exista en este archivo se debe considerar como que
tiene saldo cero en todos los servicios.

    3.1.2. Requerimiento

Se debe implementar la función bool puedeConsumir(char* rut, int servicio, string consumos_dia
que retorna verdadero si es que el colaborador tiene saldo para recibir un ticket de alimentación y falso en
otro caso. Un colaborador no tendrá saldo si es que el número de tickets anteriores en el servicio es igual o
mayor a su saldo. En caso de tener saldo también debe registrar el consumo en el archivo de consumos del
día. Esta función recibe los siguientes parámetros:

rut: Un string con el RUT del colaborador en formato NNNNNNNN-D con cada N siendo un número del
0 al 9 y D un número del 0 al 9 o la letra k (e.g. 13314801-9, 03686224-6, 78927357-k).

servicio: un entero que identifica el servicio del consumo y que debe ser una de las constantes SERV_*
presentadas en la sección anterior.

consumos_dia: un string con el nombre de archivo que contiene los consumos del día.