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


int busca_izq(vector<int> const& v, int ini, int fin) {

    if (ini == fin) {
        return ini;
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m] > v[m + 1])
            return busca_izq(v, m + 1, fin);
        else
            return busca_izq(v, ini, m);
    }
}

int busca_dcha(vector<int> const& v, int ini, int fin) {
    if (ini == fin) {
        return ini;
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m] >= v[m + 1])
            return busca_dcha(v, m + 1, fin);
        else
            return busca_dcha(v, ini, m);
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

    int longitudTramo;
    if (n == 0)
        longitudTramo = 0;
    else {
        int i = busca_izq(v, 0, n - 1);
        int j = busca_dcha(v, 0, n - 1);
        longitudTramo = j - i + 1;
    }
    cout << longitudTramo << "\n";

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