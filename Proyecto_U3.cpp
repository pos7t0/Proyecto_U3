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

void SelectionSort(vector<int>& arr) {
    int n = arr.size();
        for (int i = 0; i < n ; ++i) {
            for (int j = i; j < n ; ++j) {
                if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Intercambia los elementos si están en el orden incorrecto
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    for(int z=0;z<4;z++){
        switch (z)
        {
            case 1:
                
                break;
            
            default:
                break;
        }
    }
    
    
    auto inicio=std::chrono::high_resolution_clock::now();
    SelectionSort(arrAleatoriod);
    auto fin=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion= fin-inicio;
    cout <<duracion.count()<<endl;
    for( i=0;i<n;i++){
        cout << arrAleatoriod[i] <<endl;
    }
    cout << arrAleatoriod.size() <<endl;
    cout<< "Carrera por el Tablero: "<< endl;

    return 0;
}