// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
// función que resuelve el problema
pair<int, int> resolver(int n) {
    if (n < 10) {
        if (n == 1) return { 1, n };
        else return { 0, n };
    }
    int digito = n % 10;
    pair<int, int> p = resolver(n / 10);
    
    if (digito == p.second % 10) return { p.first + 1, p.second * digito };
    return { p.first, p.second * digito };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    pair<int, int> sol = resolver(n);
    // escribir sol

    cout << sol.first << "\n";
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