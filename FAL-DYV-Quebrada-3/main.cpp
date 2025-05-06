// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Sol {
    int menor;
    int apariciones;
};

// función que resuelve el problema
Sol resolver(vector<int> const &v, int ini, int fin) {
    if (ini == fin) {
        return { v[ini], 1 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] < v[fin]) return { v[ini], 1 };
        else if (v[ini] > v[fin]) return { v[fin], 1 };
        else return { v[ini], 2 };
    }
    else {
        int m = (ini + fin) / 2;

        Sol izq = resolver(v, ini, m);
        Sol der = resolver(v, m + 1, fin);
        Sol res;
        if (izq.menor < der.menor) {
            res = izq;
        }
        else if (izq.menor > der.menor) {
            res = der;
        }
        else {
            res.menor = izq.menor;
            res.apariciones = izq.apariciones + der.apariciones;
        }
        return res;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    if (n == 0) {
        cout << "0\n";
        return true;
    }
    vector<int> v(n);
    for (int &c : v)
        cin >> c;

    Sol sol = resolver(v, 0, n - 1);

    // escribir sol
    cout << sol.apariciones << "\n";
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
