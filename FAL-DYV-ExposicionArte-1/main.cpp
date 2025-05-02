// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool puedeTransportar(const vector<int>& pesos, int maxViajes, long long capacidad) {
    int viajes = 1;
    long long cargaActual = 0;

    for (int peso : pesos) {
        if (peso > capacidad) return false;  // no cabe ni una obra

        if (cargaActual + peso > capacidad) {
            viajes++;
            cargaActual = peso;
        }
        else {
            cargaActual += peso;
        }
    }
    return viajes <= maxViajes;
}

// función que resuelve el problema
long long resolver(vector<int> const &v, int viajes) {
    long long izq = *max_element(v.begin(), v.end());  // mínimo posible
    long long der = accumulate(v.begin(), v.end(), 0LL);  // máximo posible
    long long mejor = der;

    while (izq <= der) {
        long long mid = (izq + der) / 2;
        if (puedeTransportar(v, viajes, mid)) {
            mejor = mid;
            der = mid - 1;
        }
        else {
            izq = mid + 1;
        }
    }

    return mejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int obras, viajes;
    cin >> obras >> viajes;

    if (obras == 0 && viajes == 0)
        return false;
    vector<int> pesos(obras);

    for (int& p : pesos) {
        cin >> p;
    }

    long long sol = resolver(pesos, viajes);

    // escribir sol
    cout << sol << "\n";
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
