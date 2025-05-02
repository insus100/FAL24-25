// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
vector<int> resolver(vector<int> const& v, int caras) {
    vector<int> sol;
    vector<int> aux(caras, 0);
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        aux[v[i] - 1]++;
        if (aux[v[i] - 1] > max) max = aux[v[i] - 1];
    }
    
    for (int i = aux.size() - 1; i >= 0; i--) {
        if (aux[i] == max) sol.push_back(i + 1);
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, caras;
    cin >> n;
    if (n == -1)
        return false;
    cin >> caras;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    vector<int> sol = resolver(v, caras);
    // escribir sol
    for (int c : sol)
        cout << c << " ";
    cout << "\n";
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
