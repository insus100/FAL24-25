// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

struct Sol {
    bool disperso;
    int primer;
    int ultimo;
};
using namespace std;
// función que resuelve el problema

Sol resolver(vector<int> const& v, int ini, int fin, int const K) {
    if (ini == fin) {
        // Un único elemento siempre es suficientemente disperso
        return { true, v[ini], v[ini] };
    }

    int m = (ini + fin) / 2;

    Sol izq = resolver(v, ini, m, K);
    Sol der = resolver(v, m + 1, fin, K);

    bool actualDisperso = abs(v[ini] - v[fin]) >= K;
    bool esDisperso = actualDisperso && izq.disperso && der.disperso;

    return { esDisperso, v[ini], v[fin] };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, K;
    cin >> n >> K;
    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    Sol sol = resolver(v, 0, n - 1, K);
    // escribir sol
    sol.disperso ? cout << "SI\n" : cout << "NO\n";
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