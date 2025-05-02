// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
vector<int> resolver(vector<int> const& v1, vector<int> const& v2) {
    vector<int> sol;
    int i = 0, j = 0;

    while (i < v1.size() || j < v2.size()) {
        if (i == v1.size()) {
            sol.push_back(v2[j]);
            j++;
        }
        else if (j == v2.size()) {
            sol.push_back(v1[i]);
            i++;
        }
        else if (v1[i] < v2[j]) {
            sol.push_back(v1[i]);
            i++;
        }
        else if (v2[j] < v1[i]) {
            sol.push_back(v2[j]);
            j++;
        }
        else if (v1[i] == v2[j]) {
            sol.push_back(v1[i]);
            i++;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int& c : v1)
        cin >> c;
    for (int& c : v2)
        cin >> c;
    vector<int> sol = resolver(v1, v2);
    // escribir sol
    for (int c : sol)
        cout << c << " ";
    cout << "\n";
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