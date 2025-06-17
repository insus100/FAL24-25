#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool esMinimalista(const vector<int>& v, int n) {
    int i = 0, minimo = INT_MAX;
    bool minimalista = true;
    while (i < n && minimalista) {
        if (v[i] < minimo) {
            minimo = v[i];
        }
        else if (v[i] == minimo) {
            minimalista = false;
        }
        ++i;
    }

    return minimalista;
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == -1) return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (esMinimalista(v, n)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}