// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
char resolver(vector<char> const &v, int ini, int fin, char prim, char ult) {
    if (ini + 1 == fin) {
        if (v[ini] == prim) return ult;
        else return prim;
    }
    else {
        int m = (ini + fin) / 2;
        char medio = (prim + ult) / 2;
        if (v[m] > medio) {
            return resolver(v, ini, m, prim, medio);
        }
        else return resolver(v, m, fin, medio, ult);
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char primer, ultimo;
    cin >> primer >> ultimo;
    int n = ultimo - primer;

    vector<char> v(n);
    for (char& c : v)
        cin >> c;

    char sol = resolver(v, 0, n, primer, ultimo);
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