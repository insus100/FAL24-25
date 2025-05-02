// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const &v, int n, int l) {
    if (l > n) return 0;
    int spares = 0, simpares = 0, segmentos = 0;
    for (int i = 0; i < l; i++) {
        if (v[i] % 2 == 0) spares += v[i];
        else simpares += v[i];
    }
    if (spares > simpares) segmentos++;

    for (int i = 1; i + l - 1 < n; i++) {
        //verifico elemento que sale
        if (v[i - 1] % 2 == 0) spares -= v[i - 1];
        else simpares -= v[i - 1];

        //verifico elemento que entra a la ventana
        if (v[i + l - 1] % 2 == 0) spares += v[i + l - 1];
        else simpares += v[i + l - 1];

        if (spares > simpares) segmentos++;
    }


    return segmentos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    int sol = resolver(v, n, l);
    // escribir sol
    cout << sol << "\n";
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