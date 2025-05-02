// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const &v, int p) {
    int max = INT_MIN, i = 0;
    bool valida = true;
    for (i = 0; i <= p; i++) {
        if (v[i] > max) max = v[i];
    }
    i = p + 1;
    while (i < v.size() && valida) {
        if (max >= v[i]) valida = false;
        i++;
    }
    return valida;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    bool sol = resolver(v, p);
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