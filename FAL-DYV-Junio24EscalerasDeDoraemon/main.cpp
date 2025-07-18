// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
void resolver(vector<int> const& n, vector<int> const& g, int c, int f, bool& hablan, int& escalon) {
    if (c == f + 1) {
        hablan = false;
        escalon = f;
    }
    else {
        int m = (c + f) / 2;
        if (n[m] < g[m]) {//si se hablan o cruzan tiene que ser por la derecha
            resolver(n, g, m + 1, f, hablan, escalon);
        }
        else if (n[m] > g[m]) {
            resolver(n, g, c, m - 1, hablan, escalon);
        }
        else {
            hablan = true;
            escalon = m;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    if (tam == 0)
        return false;
    vector<int> n(tam);
    vector<int> g(tam);

    for (int& c : n)
        cin >> c;
    for (int& c : g)
        cin >> c;

    bool hablan;
    int escalon;
    resolver(n, g, 0, tam - 1, hablan, escalon);

    // escribir sol
    hablan ? cout << "HABLAN " << n[escalon] << "\n" : cout << "SE CRUZAN " << n[escalon] << " " << n[escalon + 1] << "\n";
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
