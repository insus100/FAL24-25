// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const &v, int l) {
    int ceros = 0, unos = 0, segmentos = 0, i = 0;
    for (i = 0; i < l; i++) {
        if (v[i] == 0) ceros++;
        else if (v[i] == 1) unos++;
    }
    if (ceros == unos) segmentos++;
    for (i = 1; i < v.size() && i + l - 1 < v.size(); i++) {
        //actualizar numero que sale de la ventana
        if (v[i - 1] == 0) ceros--;
        else if (v[i - 1] == 1) unos--;

        //Actualizar numero que entra en la ventana
        if (v[i + l - 1] == 0) ceros++;
        else if (v[i + l - 1] == 1) unos++;

        if (ceros == unos) segmentos++;
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

    int sol = resolver(v, l);
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