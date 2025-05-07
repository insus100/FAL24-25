// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Sol {
    bool caucasico;
    int pares;
};
// función que resuelve el problema
Sol resolver(vector<int> const &v, int ini, int fin) {
    if (ini == fin) {
        return { true, v[ini] % 2 == 0 ? 1 : 0 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] % 2 == 0 && v[fin] % 2 == 0) {
            return { true, 2 };
        }
        else if (v[ini] % 2 == 0 && v[fin] % 2 != 0 || v[ini] % 2 != 0 && v[fin] % 2 == 0) {
            return { true, 1 };
        }
        else {
            return { true, 0 };
        }
    }
    else {
        int m = (ini + fin) / 2;

        Sol izq = resolver(v, ini, m);
        Sol der = resolver(v, m + 1, fin);

        return { abs(izq.pares - der.pares) <= 2 && izq.caucasico && der.caucasico, izq.pares + der.pares };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> v(n);
    
    for (int& c : v)
        cin >> c;

    Sol sol = resolver(v, 0, n - 1);
    // escribir sol
    sol.caucasico ? cout << "SI\n" : cout << "NO\n";
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
