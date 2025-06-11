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

//Función recursiva a implementar
int contarSecuenciaMaxima(const vector<int>& v, int K, int indice_inicial) {
    if (indice_inicial == (v.size() - 1) || abs(v[indice_inicial + 1] - v[indice_inicial]) > K) return 1;
    else {
        return 1 + contarSecuenciaMaxima(v, K, indice_inicial + 1);
    }
}

// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int N, K;
    cin >> N >> K;

    if (N == 0) return false;  // Condición de parada

    vector<int> pesos(N);
    for (int i = 0; i < N; ++i) {
        cin >> pesos[i];
    }

    // Llamada a la función recursiva
    int resultado = contarSecuenciaMaxima(pesos, K, 0);
    cout << resultado << "\n";

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