// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct Sol {
    bool extranio;
    int sumPares;
    int sumImpares;
    int prodPares;
    int prodImpares;
};
using namespace std;
// función que resuelve el problema
Sol resolver(vector<int> const &v, int ini, int fin) {
    if (ini == fin) return {true, ini, fin};
    else {
        int sumaPares = 0, sumaImpares = 0, prodPares = 1, prodImpares = 1;
        if (ini + 1 == fin) {
            if (v[ini] % 2 == 0) sumaPares += v[ini];
            else prodImpares *= v[ini];

            if (v[fin] % 2 == 0) prodPares *= v[fin];
            else sumaImpares += v[fin];

            return { sumaPares + prodImpares <= prodPares + sumaImpares, sumaPares + prodImpares, prodPares + sumaImpares };
        }
        else {
            int m = (ini + fin) / 2;
            
            Sol izq = resolver(v, 0, m);
            Sol der = resolver(v, m + 1, fin);

            return { izq.izq + izq.der <= der.izq + der.der && (izq.extranio || der.extranio) };
            //if (izq.izq + izq.der <= der.izq + der.der && (izq.extranio || der.extranio)) return {};
        }
    }
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

    Sol sol = resolver(v, 0, n - 1);
    // escribir sol
    sol.extranio ? cout << "SI\n" : cout << "NO\n";
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