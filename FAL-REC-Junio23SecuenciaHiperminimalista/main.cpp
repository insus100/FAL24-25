#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int min(int j, int i) {

    if (j == i) return -1;

    if (j < i) return j;

    return i;
}

int esHiperminimalista(const vector<int> v, int ini, int fin) {
    if (ini == fin) {
        return v[ini];
    }
    else if (ini + 1 == fin) {
        return min(v[ini], v[fin]);
    }
    else {
        int m = (ini + fin) / 2;
        int menorIzq = esHiperminimalista(v, ini, m);
        int menorDer = esHiperminimalista(v, m + 1, fin);

        return min(menorIzq, menorDer);
    }
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == -1) return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (esHiperminimalista(v, 0, v.size() - 1) == -1) {
        cout << "NO\n";
    }
    else {
        cout << "SI\n";
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