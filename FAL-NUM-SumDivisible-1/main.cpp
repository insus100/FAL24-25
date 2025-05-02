// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int sumaDigitos(int n) {

    if (n < 10) return n;

    return n % 10 + sumaDigitos(n / 10);
}
// función que resuelve el problema
bool resolver(int n, int suma, bool sumDivisible = true) {
    int numDigitos = (n == 0) ? 1 : log10(n) + 1;

    if (!sumDivisible) return false;
    if (n < 10) {
        if (n % numDigitos == 0) return true;
        return false;
    }
    
    return resolver(n / 10, suma - (n % 10), suma % numDigitos == 0 ? true : false);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    int suma = sumaDigitos(n);

    bool sol = resolver(n, suma);
    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";
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
