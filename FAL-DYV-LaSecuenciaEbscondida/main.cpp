#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función para encontrar el índice del elemento más pequeño usando divide y vencerás
int encontrarInicioSecuencia(const vector<int>& v, int ini, int fin) {

    if (v[ini] < v[fin]) {
        return ini;
    }
    else {
        int m = (ini + fin) / 2;
        if (m != ini && v[m - 1] > v[m]) {
            return m;
        }
        else if (m != fin && v[m] > v[m + 1]) {
            return m + 1;
        }
        else {
            if (v[m] < v[ini]) {
                return encontrarInicioSecuencia(v, ini, m);
            }
            else if (v[m] > v[ini]) {
                return encontrarInicioSecuencia(v, m + 1, fin);
            }
        }
    }
    return -1; // Retornar el índice adecuado
}

bool resuelveCaso() {
    int numElementos;
    cin >> numElementos;

    if (numElementos == 0)
        return false;

    vector<int> elementos(numElementos);
    for (int i = 0; i < numElementos; ++i) {
        cin >> elementos[i];
    }

    cout << encontrarInicioSecuencia(elementos, 0, numElementos - 1) << "\n";
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}