// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
// función que resuelve el problema
int resolver(vector<string> const &v, string const &nacionalidad) {
    int anios = 0, i = v.size() - 1;
    bool found = false;

    while (i >= 0 && !found) {
        if (v[i] == nacionalidad) {
            anios = v.size() - i;
            found = true;
        }
        i--;
    }
    
    return anios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anios;
    string nacionalidad;
    cin >> anios >> nacionalidad;
    if (anios == 0)
        return false;
    string aux;
    vector<string> v(anios);
    for (string& s : v)
        cin >> s;

    int sol = resolver(v, nacionalidad);
    // escribir sol
    sol == 0 ? cout << "NUNCA\n" : cout << sol << "\n";
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
