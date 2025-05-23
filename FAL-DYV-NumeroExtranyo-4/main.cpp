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
    if (ini == fin) {
        if (v[ini] % 2 == 0) return { true, v[ini], 0,  v[ini], 1};
        else return { true, 0, v[ini], 1, v[ini] };
    }
    else {
            int m = (ini + fin) / 2;
            
            Sol izq = resolver(v, ini, m);
            Sol der = resolver(v, m + 1, fin);

            bool extranio = (izq.sumPares + izq.prodImpares <= der.prodPares + der.sumImpares) &&
                (izq.extranio || der.extranio);

            return {
                extranio,
                izq.sumPares + der.sumPares,
                izq.sumImpares + der.sumImpares,
                izq.prodPares* der.prodPares,
                izq.prodImpares * der.prodImpares,
            };
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