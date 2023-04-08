#   Casino de alimentacion

para compilar el programa se utilizo    g++ tarea1_1.cpp -o out -Wall

el programa cuenta con una funcion principal y 5 subfunciones, donde cada una tiene un rol especifico:

1.  bool puedeConsumir(char* rut, int servicionumerico, string consumos_dia)

esta funcion es la principal, recibe un arreglo de caracteres de tamaño R (variable global = 11), un servicio expresado en numero, y el nombre del archivo donde se guardaran los consumos diarios. Esta funcion retorna *true* si la persona puede consumir y *false* si no puede