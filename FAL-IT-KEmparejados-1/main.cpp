// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const &v, int n, int k) {
    int i = 0, j = 0, parejas = 0;

    while (i < n && j < n) {
        if (abs(v[i] - v[j]) == k) {
            parejas++;
            j++;
        }
        else if (abs(v[i] - v[j]) > k) {
            i++;
        }
        else if (abs(v[i] - v[j]) < k) {
            j++;
        }
    }

    return parejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;
    if (n == -1)
        return false;
    cin >> k;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    
    int sol = resolver(v, n, k);
    // escribir sol
    cout << sol << "\n";
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
