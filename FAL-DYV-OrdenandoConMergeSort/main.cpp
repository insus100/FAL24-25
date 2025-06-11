/***********************************************************************
 * Prepara el resto de tus asignaturas y aprueba todos los exámenes
 * finales con PROXUS!
 *
 * Todos los SPEEDRUNS disponibles:
 * https://www.proxusacademy.com
 *
 * Creado por PROXUS Academy
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función que combina dos subarrays ordenados
void merge(vector<int>& v1, vector<int> &v2, vector<int> &res) {

    int i = 0, j = 0, k = 0;
    
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            res[k] = v1[i];
            ++i;
        }
        else {
            res[k] = v2[j];
            ++j;
        }
        ++k;
    }

    while (i < v1.size()) {
        res[k] = v1[i];
        ++i;
        ++k;
    }
    while (j < v2.size()) {
        res[k] = v2[j];
        ++j;
        ++k;
    }
}

// Función principal de MergeSort
void mergeSort(vector<int>& v) {

    if (v.size() == 1)
        return;

    int m = v.size() / 2;

    vector<int> v1(m);
    vector<int> v2(v.size() - m);

    for (int i = 0; i < m; ++i)
        v1[i] = v[i];
    for (int i = 0; i < (v.size() - m); ++i)
        v2[i] = v[m + i];

    mergeSort(v1);
    mergeSort(v2);

    merge(v1, v2, v);
}

// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int N;
    cin >> N;

    if (!cin)
        return false;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(arr);

    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << "\n";

    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++)
        resuelveCaso();

    // Restablecimiento de la entrada/salida
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}