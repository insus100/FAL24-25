// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
struct edificio {
    string id;
    int altura;
    int altura_piso;
};
// función que resuelve el problema
vector<string> resolver(vector<edificio> const &v) {
    vector<string> sol;
    int maxEdif = INT_MIN, maxPiso = INT_MIN;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i].altura_piso != -1) {
            if (v[i].altura_piso > maxEdif) {
                sol.push_back(v[i].id);
            }
            if (v[i].altura > maxEdif) maxEdif = v[i].altura;
        }
        else {
            if (v[i].altura > maxEdif) maxEdif = v[i].altura;
        }
    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<edificio> v(n);
    for (edificio &e : v) {
        cin >> e.id >> e.altura >> e.altura_piso;
    }
    vector<string> sol = resolver(v);

    // escribir sol
    if (sol.empty()) {
        cout << "Ninguno\n";
    }
    else {
        cout << sol.size() << "\n";
        for (string const& e : sol)
            cout << e << " ";

        cout << "\n";
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
