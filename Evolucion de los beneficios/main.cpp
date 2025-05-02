// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const &v, int anoIni) {
    vector<int> sol;
    int ultimo = v[0], anio = anoIni;
    for (int const& a : v) {
        if (a > ultimo) {
            ultimo = a;
            sol.push_back(anio);
        }
        anio++;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int anoIni, anoFin;
    cin >> anoIni >> anoFin;
    int anios = anoFin - anoIni + 1;
    vector<int> v(anios);
    for (int& a : v)
        cin >> a;
    vector<int> sol = resolver(v, anoIni);
    // escribir sol
    for (int const& a : sol)
        cout << a << " ";

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