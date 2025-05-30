// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct sol {
    int ini, fin;
};
// función que resuelve el problema
sol resolver(vector<int> const &v, int t) {
    int ini = -1, fin = -1;
    sol Sol{ 0, -1 };
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > t) {
            if (ini == -1) {
                ini = i;
                fin = i;
            }
            else fin = i;

            if (fin - ini > Sol.fin - Sol.ini) {
                Sol.ini = ini;
                Sol.fin = fin;
            }
        }
        else {
            ini = -1;
        }
    }
    return Sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t;
    cin >> n >> t;
    vector<int> v(n);

    for (int& a : v)
        cin >> a;

    sol sol = resolver(v, t);
    // escribir sol
    cout << sol.ini << " " << sol.fin << "\n";
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