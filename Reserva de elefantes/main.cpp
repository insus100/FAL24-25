// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;
// función que resuelve el problema
lli resolver(vector<lli> const &v, int p, int a, int b) {
    int ini = a - p, fin = b - p;
    if (ini == 0) return v[fin];
    else return v[fin] - v[ini - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int p, u;
    cin >> p >> u;
    if (p == 0 && u == 0)
        return false;
    int n = u - p + 1;
    lli sum = 0;
    vector<lli> v(n);
    for (lli& a : v) {
        lli nac;
        cin >> nac;
        sum += nac;
        a = sum;
    }

    int m, a, b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        lli sol = resolver(v, p, a, b);
        cout << sol << "\n";
    }
    
    cout << "---\n";

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
