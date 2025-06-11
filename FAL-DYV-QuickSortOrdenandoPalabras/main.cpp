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
#include <string>

using namespace std;

// Función para intercambiar dos elementos
void swap(vector<string>& v, int i, int j) {
    string aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Función de partición para QuickSort
int partition(vector<string>& v, int c, int f) {
    // TODO: Implementar la función partition
    // Escoge un pivote y reorganiza el array de modo que los elementos
    // menores que el pivote queden a su izquierda y los mayores a su derecha.
    string pivote = v[f];
    int i = c, j = f - 1;

    while (i <= j) {

        if (v[i] <= pivote)
            ++i;
        else if (v[j] > pivote)
            --j;
        else {
            swap(v, i, j);
            ++i;
            --j;
        }
    }

    swap(v, i, f);
    return i;
}

// Función principal de QuickSort
void quickSort(vector<string>& v, int c, int f) {
    // TODO: Implementar la función quickSort
    // Utiliza partition para dividir el array y aplicar recursivamente
    // quickSort en los subarrays izquierdo y derecho.
    if (f - c <= 0)
        return;
    else {
        int p = partition(v, c, f);
        quickSort(v, c, p - 1);
        quickSort(v, p + 1, f);
    }
}

bool resuelveCaso() {
    int N;
    cin >> N;

    if (!cin)
        return false;

    vector<string> arr(N);
    cin.ignore(); // Consumir el salto de línea después de N

    // Leer las N palabras
    for (int i = 0; i < N; i++) {
        getline(cin, arr[i]);
    }

    // Aplicar QuickSort
    quickSort(arr, 0, N - 1);

    // Mostrar las palabras ordenadas
    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }

    cout << endl; // Separador entre casos

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
    for (int i = 0; i < numCasos && resuelveCaso(); i++);

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}