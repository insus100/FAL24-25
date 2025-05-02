// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const& v, int n, int d, int max) {
    vector<int> contadores(max + 1, 0);
    bool creciente = true, divertido = true;
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - 1) {
            if (v[i + 1] < v[i] || abs(v[i + 1] - v[i]) > 1) creciente = false;
        }
        contadores[v[i]]++;
        if (contadores[v[i]] > d) divertido = false;
    }

    return creciente && divertido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int d, n;
    cin >> d >> n;
    vector<int> v(n);
    int max = INT_MIN;
    for (int& c : v) {
        cin >> c;
        if (c > max) max = c;
    }
        
    bool sol = resolver(v, n, d, max);
    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";
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