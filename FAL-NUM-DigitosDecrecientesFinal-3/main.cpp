// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>

using namespace std;
// función que resuelve el problema
int resolver(int n, int maxder, int pot) {
    if (n < 10) {//caso base, ultima llamada recursiva.
        if (n < maxder) return 0;//si es menor se elimina.
        else return n * pot;
    }

    int digito = n % 10;

    if (digito >= maxder) return digito * pot + resolver(n / 10, max(maxder, digito), pot * 10);
    else return resolver(n / 10, max(maxder, digito), pot);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int sol = resolver(n, INT_MIN, 1);
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