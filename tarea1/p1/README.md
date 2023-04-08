#   Casino de alimentacion

para compilar el programa se utilizo    g++ tarea1_1.cpp -o out -Wall

el programa cuenta con una funcion principal y 5 subfunciones, donde cada una tiene un rol especifico:

# 1. bool puedeConsumir(char* rut, int servicionumerico, string consumos_dia)

esta funcion es la principal, recibe un arreglo de caracteres de tamaño R (variable global = 11), un servicio expresado en numero, y el nombre del archivo donde se guardaran los consumos diarios. Esta funcion retorna *true* si la persona puede consumir y *false* si no puede

# 2. int conseguir_saldo(char*rut,int servicio_numerico)

esta funcion recibe el arreglo del rut, y el servicio expresado en numeros, y retorna la cantidad de veces que el propietario del rut puede consumir ese tipo de servicio, si el propietario del rut no es colaborador retorna 0

# 3. string identificar_servicio(int servicionumerico)

esta funcion recibe el servicio de manera numerica y lo compara para guardar el nombre del servicio en una variable y retornarlo

# 4. int gastos(string servicio,string consumos_dia,char* rut)

esta funcion recibe el string del servicio, el nombre del archivo donde se guardan los consumos del dia, el arreglo del rut y el saldo, y retorna las cantidad de veces que la persona ha consumido ese tipo de servicio en el dia

# 5. void actualizartxt(char* rut, string servicio, string consumos_dia)

esta funcion recibe el arreglo del rut, el string del servicio y el nombre del archivo de los consumos del dia, no retorna nada pero agrega el nuevo consumo al documento de los consumos diarios

# 6. void creartxt(string consumos_dia)

esta funcion recibe el nombre del archivo de los consumos diarios y crea el archivo, solo es utilizada cuando no hay ningun consumo anterior