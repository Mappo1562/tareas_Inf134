#   Listas De La Suerte

para compilar el programa se utilizo    g++ tarea1_2.cpp -o out -Wall

el programa cuenta con las funciones pedidas y 1 extra creada para facilitar un poco las cosas, dejamos un archivo txt que utilizamos para probar el programa

1. int comprarTarjeta(string nombre, int dia, int &m)

> la funcion crea un array que es la tarjeta de la respectiva persona en base a su nombre y el dia (tiene el tamaño del nombre)

2. void intercambiarTarjeta(Persona* p1, Persona* p2)

> la funcion intercambia las tarjetas de p1 y de p2 y hace que p1 ya no quiera intercambiar

3. int puntaje(Persona* p1)

> calcula el puntaje de la persona p1

4. bool numero_comun(Persona a, Persona b, int tamanio)

> verifica si dos personas tienen por lo menos un numero en comun de su tarjeta

5. Persona* unDia(Persona* personas, int dia)

> hace que todas las personas compren su tarjeta diaria, luego hace que se intercambien cuando cumplan los requisitos, luego verifica a el ganador

6. void variosDias(Persona* personas, int cant_dias)

> hace que la funcion unDia se pueda ejecutar un numero determinado de veces y imprime por pantalla al ganador con su fecha de nacimiento y su puntaje