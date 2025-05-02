// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> const& v) {
    int ini = -1, cont = 0, maxCont = 0;
    if (v.empty()) return 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (ini == -1) {
            if (v[i + 1] == v[i] + 1 || v[i + 1] == v[i] - 1) {
                ini = i;
                cont = 1;
            }
        }
        else {
            if (v[i + 1] == v[i] + 1 || v[i + 1] == v[i] - 1) {
                cont++;
            }
            else {
                ini = -1;
            }
        }
        if (cont > maxCont) maxCont = cont;
    }
    return maxCont + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    int sol = resolver(v);
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