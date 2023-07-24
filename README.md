# Proyecto_U3
el objetivo de este proyecto es el desarrollo de un programa en C + + que permita realizar una comparación
de distintos algoritmos, en base a distintas entradas de datos, con el propósito de determinar qué algoritmo
puede ser incluido dentro del juego.
Los algoritmos que veremos son de funciones de ordenamiento cuadraticas y logaritmicas, tales como: selection sort,
bubble sort, insertion sort, shell sort, merge sort, quick sort y heap sort, estas fueron modificadas para que se pueda 
ordenar segun la opcion del usuario, de mayor a menor o de menor a mayor.
para solucionar esta duda de que algoritmo es mas eficiente se decidio utilizar la librerias <unorder_map> y <chrono> para medir el tiempo con 
std::chrono::high_resolution_clock::now(), ademas de crear otras funciones (aparte de las mencionadas) como: "se_repite" que 
determinaba si el arreglo ya tenia el numero (es escencial para crear el arreglo random sin repeticiones), "swapall" que entregaba 
todos los elementos del arreglo a otro, y "resultados" que imprimia los tiempos de cada funcion cuadratica que estaban almacernadas
en un unorder_map, ademas de determinaba el menor tiempo.
En el main se creo los cuatro tipos de arreglos que se pedia (ordenado, inversamente ordenado, aleatorio y aleatorio sin repeticiones), en el caso
de los aleatorios se utilizo la libreria <cstdlib>, para determinar guardar el tiempo de cada uno se creo el unordermap de esta manera 
unordered_map<string,std::chrono::duration<double>> para poner el nombre y su tiempo. 
