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

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void SelectionSort(vector<int>& arr) {
    int n = arr.size();
        for (int i = 0; i < n ; ++i) {
            for (int j = i; j < n ; ++j) {
                //hay que cambiar el mayor o menor para hacerlo acendente o descendente
                if (arr[j] > arr[i]) {
                // Intercambia los elementos si están en el orden incorrecto
                swap(arr[i],arr[j]);
            }
        }
    }
}
void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            //hay que cambiar el mayor o menor para hacerlo acendente o descendente
            if (arr[j] < arr[j + 1]) {
                // Intercambia los elementos si están en el orden incorrecto
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertionSort(vector<int>& arr) {
    int size=arr.size();
    for (int i = 1; i < size; ++i) {
        int j = i;
        //hay que cambiar el mayor o menor para hacerlo acendente o descendente
        while (j > 0 && arr[j - 1] < arr[j]) {
            // Intercambia los elementos si están en el orden incorrecto
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
void shellSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2; // Empieza con la mitad del tamaño del vector como brecha inicial

    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            //se cambia el mayor o menor de la segunda condicion del while para hacerlo acendente o descendente
            while (j >= gap && arr[j - gap] < temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }

            arr[j] = temp;
        }

        gap = gap / 2; // Reducción de la brecha utilizando una secuencia de brechas adecuada
    }
}
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> output;
    unsigned int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        //hay que cambiar el mayor o menor para hacerlo acendente o descendente
        //se empuja hacia un nuevo arreglo el valor mayor o menor tamaño dependiendo del usuario
        if (left[i] < right[j]) {
            output.push_back(left[i]);
            ++i;
        } else {
            output.push_back(right[j]);
            ++j;
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
vector<int> mergeSort(vector<int>& arr) {
    int length = arr.size();

    if (length == 1) {
        return arr;
    }

    int mid = length / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        //hay que cambiar el mayor o menor para hacerlo acendente o descendente
        if (arr[j] <= pivot) {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //hay que cambiar el mayor o menor para hacerlo acendente o descendente
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    //hay que cambiar el mayor o menor para hacerlo acendente o descendente
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Construir un heap máximo
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void resultados(unordered_map<string,double>arr,const string& nombre){
    cout<< "Carrera por el Tablero: "<<nombre<< endl;
    int id=1;
    for(const auto& pair:arr){
        string nombre_alg=pair.first;
        double value=pair.second;
        cout<<id<<") "<<nombre_alg<<value<<endl;
    }
}

int main(){

    vector<int> arrOrdenado,arrDesordenado,arrAleatoriod;
    unordered_map<string,double> resultados;
    int i,n=1000,opcion;
    int random=1 + rand() % (n);
    for( i=0;i<n;i++){
        arrOrdenado.push_back(i);
        arrDesordenado.push_back(n-i);
        arrAleatoriod.push_back(random);
        random=1 + rand() % (n);
    }
    //formato del docente para que el usuario diga si es acendente o descendente
    cout<< "Carrera de algoritmos"<< endl;
    cout<<"1) Acendente"<<endl;
    cout<<"2) Descendente"<<endl;
    cout<<"Opcion elegida: ";
    cin>> opcion;
    //para ver el resultado de cada arreglo
    auto inicio=std::chrono::high_resolution_clock::now();
    auto fin=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion= fin-inicio;
    /*
    for(int z=0;z<4;z++){
        
        switch (z)
        {
            case 1:
                
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
           
        }
        
    }
     */ 
    
    inicio=std::chrono::high_resolution_clock::now();
    //SelectionSort(arrAleatoriod);
    //BubbleSort(arrAleatoriod);
    //insertionSort(arrAleatoriod);
    //shellSort(arrAleatoriod);
    //vector<int>prueba= mergeSort(arrAleatoriod);
    //quickSort(arrAleatoriod,0,1000);
    heapSort(arrAleatoriod);
    fin=std::chrono::high_resolution_clock::now();
    duracion= fin-inicio;
    
    for( i=0;i<n;i++){
        //cout << prueba[i] <<endl;
        cout << arrAleatoriod[i] <<endl;
    }
    //cout << arrAleatoriod.size() <<endl;
    cout<< "Carrera por el Tablero: "<< endl;
    cout <<duracion.count()<<endl;
    return 0;
}