// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
// función que resuelve el problema
int resolver(int n, int p) {
    if (n < 10) {
        return (9 - n) * p;
    }

    return (9 - (n % 10)) * p + resolver(n / 10, p * 10);
}

int resolverInverso(int n, int p) {
    if (n < 10) {
        return (9 - n) * p;
    }

    return (9 - (n % 10)) * p + resolverInverso(n / 10, p / 10);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int sol = resolver(n, 1);
    int numDigitos = (n == 0) ? 1 : log10(n) + 1;//saco num digitos para ver la potencia que tiene que tener el primer digito.
    int potencia = pow(10, numDigitos - 1);
    int solInverso = resolverInverso(n, potencia);
    // escribir sol
    cout << sol << " " << solInverso << "\n";
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