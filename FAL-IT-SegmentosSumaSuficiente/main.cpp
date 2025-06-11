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

int contarSegmentosSuficientes(const vector<int>& v, int k, long long s, int n) {
    unsigned long long sum = 0;
    int segmentos = 0;
    for (int i = 0; i < k; i++) {
        sum += v[i];
    }
    if (sum >= s) segmentos++;

    for (int i = 1; i < n - k + 1; i++) {
        sum -= v[i - 1];
        sum += v[i + k - 1];

        if (sum >= s) segmentos++;
    }

    return segmentos;
}

bool resuelveCaso() {
    int n, k;
    // Usamos long long para manejar sumas grandes, ya que los elementos de v pueden ser hasta 10^9 
    // y el tamaño del vector puede llegar a 100,000, lo que podría causar desbordamiento en int.
    long long s;

    cin >> n;
    if (n == 0) return false;

    cin >> k >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << contarSegmentosSuficientes(v, k, s, n) << "\n";
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