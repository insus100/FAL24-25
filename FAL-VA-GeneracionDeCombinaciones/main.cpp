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

void generarCombinaciones(vector<int> &sol, int N, int K) {
    int c = 1;
    if (K > 0) {
        c = sol[K - 1] + 1;
    }
    for (int i = c; i <= N; ++i) {
        sol[K] = i;
        if (K == sol.size() - 1) {
            for (int x : sol)
                cout << x << " ";
            cout << "\n";
        }
        else generarCombinaciones(sol, N, K + 1);
    }
}

// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int N, K;
    cin >> N >> K;

    if (!cin)
        return false;

    vector<int> sol(K);

    generarCombinaciones(sol, N, 0);

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