/***********************************************************************
 * Prepara el resto de tus asignaturas y aprueba todos los exámenes
 * finales con PROXUS!
 *
 * Todos los SPEEDRUNS disponibles:
 * https://www.proxusacademy.com
 *
 * Creado por PROXUS Academy
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;
struct Sol {
    int ini;
    int cont;
    int min;
    int perdida;
};
Sol resolverCaso(vector<int>& v, int n, int limite) {
    Sol aux{ 0, 0, INT_MAX, 0};
    Sol sol{ 0, 0, INT_MAX, 0 };
    for (int i = 0; i < n; i++) {
        if (v[i] < limite) { // si el numero es menor al limite
            if (aux.cont == 0) {// si no he iniciado ningun tramo.
                aux.ini = i;
                aux.cont = 1;
                aux.perdida += abs(v[i]);
            }
            else {
                aux.cont++;
                aux.perdida += abs(v[i]);
                aux.min = min(v[i], aux.min);
            }
            if (aux.cont > sol.cont || (aux.cont == sol.cont && aux.min <= sol.min)) {
                sol = aux;
            }
        }
        else {// si es mayor o igual
            aux.ini = 0;
            aux.cont = 0;
            aux.perdida = 0;
            aux.min = INT_MAX;
        }
    }
    return sol;
}

bool resuelveCaso() {
    // Leer los datos de entrada
    int n, limite;
    cin >> n;

    if (n == 0)
        return false;

    cin >> limite;
    vector<int> beneficios(n);
    for (int i = 0; i < n; ++i) {
        cin >> beneficios[i];
    }

    Sol sol = resolverCaso(beneficios, n, limite);
    if (sol.cont == 0) cout << "SIN PERDIDAS\n";
    else cout << sol.cont << " " << sol.ini << " " << sol.min << "\n";
    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Restablecimiento de la entrada
#ifndef PROXUS
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}