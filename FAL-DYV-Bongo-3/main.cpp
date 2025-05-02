// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> &v, int ini, int fin, int b) {
    if (ini == fin) {
        if (v[ini] - ini == b) return v[ini];
        else return -1;
    }
    else if (ini + 1 == fin) {
        if (v[ini] - ini == b) return v[ini];
        else if (v[fin] - fin == b) return v[fin];
        return -1;
    }
    else {
        int m = (ini + fin) / 2;

        if (v[m] - m == b) return v[m];
        if (v[m] - m < b) {
            return resolver(v, m, fin, b);
        }
        else {
            return resolver(v, ini, m, b);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, b;
    cin >> n >> b;

    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    int sol = resolver(v, 0, n - 1, b);
    // escribir sol
    sol == -1 ? cout << "NO\n" : cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}