// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
using lli = long long int;
// función que resuelve el problema
pair<lli, lli> resolver(vector<lli> const &v) {
    lli min = LLONG_MAX, suma = 0, cont = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min) {
            suma += min * cont;
            min = v[i];
            cont = 1;
        }
        else if (v[i] == min) {
            cont++;
        }
        else {
            suma += v[i];
        }
    }
    return { suma, v.size() - cont };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<lli> v(n);
    for (lli& c : v)
        cin >> c;

    pair<lli, lli> sol = resolver(v);
    // escribir sol
    cout << sol.first << " " << sol.second << "\n";
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