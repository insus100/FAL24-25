#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int secuencias(const vector<int> v, int u, int suma, int minimal) {
    int num_sec = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (suma + v[i] <= u && v[i] != minimal) {
            num_sec++;
            num_sec += secuencias(v, u, suma + v[i], min(minimal, v[i]));
        }
    }
    return num_sec;
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == -1) return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int u;

    cin >> u;

    cout << secuencias(v, u, 0, INT_MAX) << "\n";

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