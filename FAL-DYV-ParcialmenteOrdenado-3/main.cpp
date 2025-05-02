// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Sol {
    int max;
    int min;
    bool ordenado;
};
using namespace std;
// función que resuelve el problema
Sol resolver(vector<int> const &v, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] <= v[fin]) return { v[fin], v[ini], true };
        else return { v[fin], v[ini], false };
    }
    else {
        int m = (ini + fin) / 2;

        Sol izq = resolver(v, ini, m);
        if (!izq.ordenado) return { 0, 0, false };
        Sol der = resolver(v, m + 1, fin);
        if (!der.ordenado) return { 0,0, false };

        bool ord = der.max >= izq.min && izq.min <= der.min;

        bool cumple = ord && der.ordenado && izq.ordenado;

        return { max(izq.max, der.max), min(izq.min, der.min), cumple };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int c;
    cin >> c;
    if (c == 0) return false;
    while (c != 0) {
        v.push_back(c);
        cin >> c;
    }

    Sol sol = resolver(v, 0, v.size() - 1);
    // escribir sol
    sol.ordenado ? cout << "SI\n" : cout << "NO\n";
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
