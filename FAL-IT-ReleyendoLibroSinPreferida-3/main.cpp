// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const&v, int L) {
    int sum = 0, max = INT_MIN, index = -1;
    for (int i = 0; i < L; i++) {
        sum += v[i];
        if (i == L - 1) {
            max = sum;
            index = 0;
        }
    }
    for (int i = 1; i + L - 1 < v.size(); i++) {
        sum -= v[i - 1];
        sum += v[i + L - 1];
        if (sum >= max) {
            max = sum;
            index = i;
        }
    }
    return index;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0)
        return false;
    vector<int> v(n);
    for (int& p : v)
        cin >> p;
    int sol = resolver(v, L);

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
