#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <unordered_map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;
//funcion para reconocer si se repite algun numero de la funcion
bool se_repite(vector<int>& a,int b){
    //se devolvera al tiro que no esta repetido si el arreglo no tiene variables
    if(a.size()==0){
        return false;
    }
    //un for para recorrer cada elemento
    for(unsigned int i=0;i<a.size();i++){
        //se afirma que el arreglo tiene un numero igual al de b
        if(a[i]==b){
            return true;
        }    
    }
    //se retorna un falso al no haber un numero random
    return false;
}
//funcion para transcribir todo los datos de un arreglo a otro
void swapall(vector<int>& a,vector<int>& b){
    //se confirma si esta del mismo tamaño que la otra funcion primero
    if(a.size()>b.size()){
        //se le agregan elementos al arreglo con un push_back
        for(unsigned int i=0;i<a.size();i++){
            b.push_back(a[i]);
        }
    }else{
        //se le cambian los datos de los elementos
        for(unsigned int i=0;i<a.size();i++){
            b[i]=a[i];
        }
    }
    
}
//un cambio normal de dos for
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void SelectionSort(vector<int>& arr,int opcion) {
    int n = arr.size();
    for (int i = 0; i < n ; ++i) {
        for (int j = i; j < n ; ++j) {
            //hay que cambiar el mayor o menor para hacerlo acendente o descendente
            if (arr[j] < arr[i] && opcion==1) {
            // Intercambia los elementos si están en el orden incorrecto
                swap(arr[i],arr[j]);
            }
            if (arr[j] > arr[i] && opcion==2) {
            // Intercambia los elementos si están en el orden incorrecto
                swap(arr[i],arr[j]);
            }
        }
    }
}
void BubbleSort(vector<int>& arr,int opcion) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            //hay que cambiar el mayor o menor para hacerlo acendente o descendente
            if (arr[j] > arr[j + 1] && opcion==1) {
                // Intercambia los elementos si están en el orden incorrecto
                swap(arr[j],arr[j+1]);
            }
            if (arr[j] < arr[j + 1] && opcion==2) {
                // Intercambia los elementos si están en el orden incorrecto
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertionSort(vector<int>& arr,int opcion) {
    int size=arr.size();
    for (int i = 1; i < size; ++i) {
        int j = i;
        //hay que cambiar el mayor o menor para hacerlo acendente o descendente
        while (j > 0 && arr[j - 1] > arr[j] && opcion==1) {
            // Intercambia los elementos si están en el orden incorrecto
            swap(arr[j],arr[j-1]);
            j--;
        }
        while (j > 0 && arr[j - 1] < arr[j] && opcion==2) {
            // Intercambia los elementos si están en el orden incorrecto
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
void shellSort(vector<int>& arr,int opcion) {
    int n = arr.size();
    int gap = n / 2; // Empieza con la mitad del tamaño del vector como brecha inicial

    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            //se cambia el mayor o menor de la segunda condicion del while para hacerlo acendente o descendente
            while (j >= gap && arr[j - gap] > temp && opcion==1) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            while (j >= gap && arr[j - gap] < temp && opcion==2) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }

            arr[j] = temp;
        }

        gap = gap / 2; // Reducción de la brecha utilizando una secuencia de brechas adecuada
    }
}
vector<int> merge(vector<int>& left, vector<int>& right,int opcion) {
    vector<int> output;
    unsigned int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        //hay que cambiar el mayor o menor para hacerlo acendente o descendente
        //se empuja hacia un nuevo arreglo el valor mayor o menor tamaño dependiendo del usuario
        if(opcion==1){
           if (left[i] < right[j]) {
                output.push_back(left[i]);
                ++i;
            } else {
                output.push_back(right[j]);
                ++j;
            } 
        }else{
            if (left[i] > right[j]) {
                output.push_back(left[i]);
                ++i;
            } else {
                output.push_back(right[j]);
                ++j;
            } 
        }
        
    }

    while (i < left.size()) {
        output.push_back(left[i]);
        ++i;
    }

    while (j < right.size()) {
        output.push_back(right[j]);
        ++j;
    }

    return output;
}
vector<int> mergeSort(vector<int>& arr,int opcion) {
    int length = arr.size();

    if (length == 1) {
        return arr;
    }

    int mid = length / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left,opcion);
    right = mergeSort(right,opcion);
    //se junta todo
    return merge(left, right,opcion);
}
void quickSort(vector<int>& arr, int inicio, int fin, int opcion)
{
    stack<pair<int, int>> pila;
    pila.push(make_pair(inicio, fin));

    while (!pila.empty())
    {
        int inicioActual = pila.top().first;
        int finActual = pila.top().second;
        pila.pop();

        if (inicioActual >= finActual)
            continue;

        int pivote = arr[finActual];
        int i = inicioActual - 1;

        for (int j = inicioActual; j <= finActual - 1; ++j)
        {
            if (opcion==1)
            {
                if (arr[j] < pivote)
                {
                    ++i;
                    swap(arr[i], arr[j]);
                }
            }
            else
            {
                if (arr[j] > pivote)
                {
                    ++i;
                    swap(arr[i], arr[j]);
                }
            }
        }

        swap(arr[i + 1], arr[finActual]);
        int indicePivote = i + 1;

        pila.push(make_pair(inicioActual, indicePivote - 1));
        pila.push(make_pair(indicePivote + 1, finActual));
    }
}
void heapify(vector<int>& arr, int n, int i,int opcion) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest] && opcion==1) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest] && opcion==1) {
        largest = right;
    }
    if (left < n && arr[left] < arr[largest] && opcion==2) {
        largest = left;
    }
    if (right < n && arr[right] < arr[largest] && opcion==2) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest,opcion);
    }
}
void heapSort(vector<int>& arr,int opcion) {
    int n = arr.size();

    // Construir un heap máximo
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i,opcion);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0,opcion);
    }
}
//entrega los resultados con la estructura pedida
void resultados(unordered_map<string,std::chrono::duration<double>>arr,const string& nombre){
    cout<< "Carrera por el Tablero: "<<nombre<< endl;
    int id=1;
    string nombregana;
    //poner una variable mayor para determinar el menor
    std::chrono::duration<double> menor=std::chrono::seconds(120);
    for(const auto& pair:arr){
        string nombre_alg=pair.first;
        std::chrono::duration<double> value=pair.second;
        //se revisa si cada elemento del unorder_map tiene el menor tiempo
        if(menor>pair.second){
            menor=pair.second;
            nombregana=pair.first;
        }
        cout<<id<<") "<<nombre_alg<<", "<<value.count()<<endl;
        id++;
    }
    cout<<"El ganador es: "<<nombregana<<" con "<<menor.count()<<" segundos"<<endl;
}
int main(){

    vector<int> arrOrdenado1,arrDesordenado1,arrAleatorior1,arrAleatorionr1,prueba1;
    vector<int> arrOrdenado2,arrDesordenado2,arrAleatorior2,arrAleatorionr2,prueba2;
    vector<int> arrOrdenado3,arrDesordenado3,arrAleatorior3,arrAleatorionr3,prueba3;
    //arrAleatorior= se repiten los numeros, arrAleatorionr= no se repiten los numeros
    unordered_map<string,std::chrono::duration<double>> resultado;
    int i,opcion;
    //determinar el maximo entre 90000 y 100000
    int n=90000+1 + rand() % (10000);
    int random=1 + rand() % (n);
    
    //formato del docente para que el usuario diga si es acendente o descendente
    cout<< "Carrera de algoritmos"<< endl;
    cout<<"1) Acendente"<<endl;
    cout<<"2) Descendente"<<endl;
    cout<<"Opcion elegida: ";
    cin>> opcion;
    cout<<"parte 1"<<endl;
    for( i=0;i<n;i++){
        //determinar como es el ordenado y el inversamente ordenado
        if(opcion==1){
            arrOrdenado1.push_back(i);
            arrDesordenado1.push_back(n-i);
        }else{
            arrOrdenado1.push_back(n-i);
            arrDesordenado1.push_back(n);
        }
        arrAleatorior1.push_back(random);
        random=1 + rand() % (n+1000);    
    }
    int m=10000000;
    for(i=0;i<n;i++){
        do{
            //crear una gran cantidad de probabilidades para que salgan mas facil los random
            random= rand() % (m)+rand() % (m)+ rand() % (m) + rand() % (m)+ rand() % (m) + rand() % (m);
            //cout << arrAleatorionr1.size() <<endl;
        }while(se_repite(arrAleatorionr1,random));
        arrAleatorionr1.push_back(random);
    }
    //para ver el resultado de cada arreglo
    auto inicio=std::chrono::high_resolution_clock::now();
    auto fin=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion= fin-inicio;
    for(int w=1;w<=4;w++){
        for(int z=1;z<=7;z++){
            //se recargan las funciones hacia otro arreglo
            if(w==1){
                swapall(arrOrdenado1,prueba1);
                cout<< prueba1.size()<<endl;
            }
            if(w==2){
                swapall(arrDesordenado1,prueba1);
            }
            if(w==3){
                swapall(arrAleatorionr1,prueba1);
            }
            if(w==4){
                swapall(arrAleatorior1,prueba1);
            }
            switch (z)
            {
                
                case 1:
                    inicio=std::chrono::high_resolution_clock::now();
                    SelectionSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["SelectionSort"]=duracion;
                    break;
                case 2:
                    inicio=std::chrono::high_resolution_clock::now();
                    BubbleSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["BubbleSort"]=duracion;
                    break;
                case 3:
                    inicio=std::chrono::high_resolution_clock::now();
                    insertionSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["insertionSort"]=duracion;
                    break;
                case 4:
                    inicio=std::chrono::high_resolution_clock::now();
                    shellSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["shellSort"]=duracion;
                    break;
                case 5:
                    inicio=std::chrono::high_resolution_clock::now();
                    mergeSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["mergeSort"]=duracion;
                    break;
                case 6:
                    inicio=std::chrono::high_resolution_clock::now();
                    quickSort(prueba1,0,prueba1.size()-1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["quickSort"]=duracion;
                    break;
                case 7:
                    inicio=std::chrono::high_resolution_clock::now();
                    heapSort(prueba1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["heapSort"]=duracion;
                    break;
            }
        }
        //mostrar los resultados de cada carrera
        if(w==1){
            resultados(resultado,"Ordenado");
        }
        if(w==2){
            resultados(resultado,"Inversamente ordenado");
        }
        if(w==3){
            resultados(resultado,"Aleatorio");
        }
        if(w==4){
            resultados(resultado,"Aleatorio con duplicados");
        }
    }
    //desde aqui en adelante es lo mismo con variables cambiados
    cout<<"Parte 2"<<endl;
    //determinar el maximo entre 50000 y 70000
    n=50000+1 + rand() % (20000);
    for( i=0;i<n;i++){
        if(opcion==1){
            arrOrdenado2.push_back(i);
            arrDesordenado2.push_back(n-i);
        }else{
            arrOrdenado2.push_back(n-i);
            arrDesordenado2.push_back(n);
        }
        arrAleatorior2.push_back(random);
        random=1 + rand() % (n+1000);    
    }
    for(i=0;i<n;i++){
        do{
            random= rand() % (m)+rand() % (m)+ rand() % (m) + rand() % (m)+ rand() % (m);
            //cout << random <<endl;
        }while(se_repite(arrAleatorionr2,random));
        arrAleatorionr2.push_back(random);
    }
    for(int w=1;w<=4;w++){
        for(int z=1;z<=7;z++){
            if(w==1){
                swapall(arrOrdenado2,prueba2);
                cout<< prueba2.size()<<endl;
            }
            if(w==2){
                swapall(arrDesordenado2,prueba2);
            }
            if(w==3){
                swapall(arrAleatorionr2,prueba2);
            }
            if(w==4){
                swapall(arrAleatorior2,prueba2);
            }
            switch (z)
            {
                
                case 1:
                    inicio=std::chrono::high_resolution_clock::now();
                    SelectionSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["SelectionSort"]=duracion;
                    break;
                case 2:
                    inicio=std::chrono::high_resolution_clock::now();
                    BubbleSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["BubbleSort"]=duracion;
                    break;
                case 3:
                    inicio=std::chrono::high_resolution_clock::now();
                    insertionSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["insertionSort"]=duracion;
                    break;
                case 4:
                    inicio=std::chrono::high_resolution_clock::now();
                    shellSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["shellSort"]=duracion;
                    break;
                case 5:
                    inicio=std::chrono::high_resolution_clock::now();
                    mergeSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["mergeSort"]=duracion;
                    break;
                case 6:
                    inicio=std::chrono::high_resolution_clock::now();
                    quickSort(prueba2,0,prueba2.size()-1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["quickSort"]=duracion;
                    break;
                case 7:
                    inicio=std::chrono::high_resolution_clock::now();
                    heapSort(prueba2,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["heapSort"]=duracion;
                    break;
            }
        }
        if(w==1){
            resultados(resultado,"Ordenado");
        }
        if(w==2){
            resultados(resultado,"Inversamente ordenado");
        }
        if(w==3){
            resultados(resultado,"Aleatorio");
        }
        if(w==4){
            resultados(resultado,"Aleatorio con duplicados");
        }
    }
    cout<<"Parte 3"<<endl;
    //determinar el maximo entre 7500 y 15000
    n=7500+1 + rand() % (7500);
    for( i=0;i<n;i++){
        if(opcion==1){
            arrOrdenado3.push_back(i);
            arrDesordenado3.push_back(n-i);
        }else{
            arrOrdenado3.push_back(n-i);
            arrDesordenado3.push_back(n);
        }
        arrAleatorior3.push_back(random);
        random=1 + rand() % (n+1000);    
    }
     m=100000;
    for(i=0;i<n;i++){
        do{
            random= rand() % (m)+rand() % (m)+ rand() % (m) ;
        }while(se_repite(arrAleatorionr3,random));
        arrAleatorionr3.push_back(random);
    }
    for(int w=1;w<=4;w++){
        for(int z=1;z<=7;z++){
            if(w==1){
                swapall(arrOrdenado3,prueba3);
                cout<< prueba3.size()<<endl;
            }
            if(w==2){
                swapall(arrDesordenado3,prueba3);
            }
            if(w==3){
                swapall(arrAleatorionr3,prueba3);
            }
            if(w==4){
                swapall(arrAleatorior3,prueba3);
            }
            switch (z)
            {
                
                case 1:
                    inicio=std::chrono::high_resolution_clock::now();
                    SelectionSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["SelectionSort"]=duracion;
                    break;
                case 2:
                    inicio=std::chrono::high_resolution_clock::now();
                    BubbleSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["BubbleSort"]=duracion;
                    break;
                case 3:
                    inicio=std::chrono::high_resolution_clock::now();
                    insertionSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["insertionSort"]=duracion;
                    break;
                case 4:
                    inicio=std::chrono::high_resolution_clock::now();
                    shellSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["shellSort"]=duracion;
                    break;
                case 5:
                    inicio=std::chrono::high_resolution_clock::now();
                    mergeSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["mergeSort"]=duracion;
                    break;
                case 6:
                    inicio=std::chrono::high_resolution_clock::now();
                    quickSort(prueba3,0,prueba3.size()-1,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["quickSort"]=duracion;
                    break;
                case 7:
                    inicio=std::chrono::high_resolution_clock::now();
                    heapSort(prueba3,opcion);
                    fin=std::chrono::high_resolution_clock::now();
                    duracion= fin-inicio;
                    resultado["heapSort"]=duracion;
                    break;
            }
        }
        if(w==1){
            resultados(resultado,"Ordenado");
        }
        if(w==2){
            resultados(resultado,"Inversamente ordenado");
        }
        if(w==3){
            resultados(resultado,"Aleatorio");
        }
        if(w==4){
            resultados(resultado,"Aleatorio con duplicados");
        }
    }
    
    
    return 0;
}