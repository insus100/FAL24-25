// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
    if (ini == fin) {
        return v[ini];
    }
    else if (v[ini + 1] == v[fin]) {
        return min(v[ini], v[fin]);
    }
    else {
        int m = (ini + fin) / 2;
        if (v[m] > v[ini] || v[m] < v[m + 1])
            return resolver(v, ini, m);
        else
            return resolver(v, m + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    int sol = resolver(v, 0, n - 1);
    // escribir sol
    cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}