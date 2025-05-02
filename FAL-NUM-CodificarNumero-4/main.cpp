// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;
// función que resuelve el problema
pair<int, int> resolver(int n, int posicion, int nDerecha) {
    if (n < 10) {//esta es la ultima de las llamadas recursivas, en funcion de si es una posicion par o impar operar
        //posicion 1 siempre
        return { n, n * 3 + nDerecha };
    }

    pair<int, int> p = resolver(n / 10, posicion - 1, min(n % 10, nDerecha));

    int digito = n % 10;
    if (posicion % 2 == 0) {//posicion par se multiplica por 2 y se le suma el mayor dígito a su izquierda
        return { max(digito, p.first), p.second + (digito * 2 + p.first) };
    }
    else {// posicion impar se multiplica por 3 y se le suma el menor dígito a su derecha
        return { max(digito, p.first), p.second + (digito * 3 + nDerecha) };
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int numDigitos = (n == 0) ? 1 : log10(n) + 1;
    pair<int, int> sol = resolver(n, numDigitos, INT_MAX);
    // escribir sol
    cout << sol.second << "\n";
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