/***********************************************************************
 * Prepara el resto de tus asignaturas y aprueba todos los exбmenes
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

// Búsqueda binaria a implementar
bool busquedaBinaria(const vector<int>& v, int X, int iz, int der) {
    if (iz == der) return v[iz] == X;
    else if (iz + 1 == der) return v[iz] == X || v[der] == X;
    else {
        int m = (iz + der) / 2;

        if (X == v[m]) return true;
        else if (X < v[m]) return busquedaBinaria(v, X, iz, m);
        else if (X > v[m]) return busquedaBinaria(v, X, m + 1, der);
    }
}

// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int X;
    cin >> X;

    // Llamada a la función de búsqueda binaria y salida del resultado
    bool encontrado = busquedaBinaria(arr, X, 0, N - 1);
    if (encontrado) {
        cout << "ENCONTRADO" << endl;
    }
    else {
        cout << "NO ENCONTRADO" << endl;
    }

    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}