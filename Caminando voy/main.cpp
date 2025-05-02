// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const&v, int D) {
    int cotaMin = v[0], cotaMax = INT_MIN, i = 1;
    bool apta = true;
    while (i < v.size() && apta) {
        if (v[i] > cotaMin && v[i] > cotaMax) cotaMax = v[i];
        else {
            cotaMin = v[i];
            cotaMax = INT_MIN;
        }
        if (cotaMax != INT_MIN && cotaMax - cotaMin > D) apta = false;
        i++;
    }

    return apta;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int D, N;
    cin >> D >> N;
    if (!std::cin)
        return false;
    vector<int> v(N);
    for (int& a : v)
        cin >> a;

    bool sol = resolver(v, D);
    // escribir sol
    sol ? cout << "APTA\n" : cout << "NO APTA\n";
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