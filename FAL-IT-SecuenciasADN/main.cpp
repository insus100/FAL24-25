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
#include <vector>
#include <fstream>
using namespace std;

// Función que realiza la mezcla de dos vectores ordenados
void mezcla(vector<char>& sec1, vector<char>& sec2, vector<char>& resultado) {
    // Implementa aquí la función de mezcla
    int n = sec1.size();
    int m = sec2.size();
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (sec1[i] < sec2[j]) {
            resultado[k] = sec1[i];
            ++i;
        }
        else {
            resultado[k] = sec2[j];
            ++j;
        }
        ++k;
    }

    while (i < n) {
        resultado[k] = sec1[i];
        ++i;
        ++k;
    }
    while (j < m) {
        resultado[k] = sec2[j];
        ++j;
        ++k;
    }
}

bool resuelveCaso() {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) return false;

    vector<char> sec1(n);
    vector<char> sec2(m);
    vector<char> resultado(n + m);

    // Lectura de la primera secuencia
    for (int i = 0; i < n; i++) {
        cin >> sec1[i];
    }
    // Lectura de la segunda secuencia
    for (int i = 0; i < m; i++) {
        cin >> sec2[i];
    }

    // Llamada a la función de mezcla
    mezcla(sec1, sec2, resultado);

    // Escritura de resultados
    for (int i = 0; i < n + m; i++) {
        cout << resultado[i];
        if (i < n + m - 1) cout << " ";
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
    for (int i = 0; i < numCasos && resuelveCaso(); ++i);

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}