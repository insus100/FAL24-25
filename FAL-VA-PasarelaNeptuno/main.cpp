/*********************************************************************** *
 * Prepara el resto de tus asignaturas y aprueba todos los exámenes
 * finales con PROXUS!
 *
 * Todos los SPEEDRUNS disponibles:
 * https://www.proxusacademy.com
 *
 * Creado por PROXUS Academy
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void pasarela(vector<vector<int>> const& trajes, vector<vector<int>> const& zapatos, int k, int n, vector<bool>& marcasT, vector<bool>& marcasZ, vector<int> const& max_satisfaccion_acum, int& max_sol, int& actual_sol) {
    
    for (int i = 0; i < n; ++i) {
        if (!marcasT[i]) {
            marcasT[i] = true;
            //sol[k].first = i;//.first es el traje
            for (int j = 0; j < n; ++j) {
                if (!marcasZ[j]) {
                    marcasZ[j] = true;
                    //sol[k].second = j;
                    actual_sol += trajes[k][i] * zapatos[k][j];
                    if (k == n - 1) {//es_solucion
                        if (actual_sol > max_sol)
                            max_sol = actual_sol;
                        //cout << suma_preferencias(sol) << "\n";
                    }
                    else {
                        if(actual_sol + max_satisfaccion_acum[k + 1] > max_sol)
                            pasarela(trajes, zapatos, k + 1, n, marcasT, marcasZ, max_satisfaccion_acum, max_sol, actual_sol);
                    }
                    marcasZ[j] = false;
                    actual_sol -= trajes[k][i] * zapatos[k][j];
                }
            }
            marcasT[i] = false;
        }
    }
}
// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int n;
    // Leer el tamaño de las matrices
    cin >> n;

    vector<vector<int>> trajes(n, vector<int>(n));
    vector<vector<int>> zapatos(n, vector<int>(n));
    vector<bool> marcasT(n, false), marcasZ(n, false);

    // Leer matriz de trajes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> trajes[i][j];
        }
    }

    // Leer matriz de zapatos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> zapatos[i][j];
        }
    }

    //para la poda de optimalidad
    vector<int> max_satisfacciones(n);
    for (int i = 0; i < n; ++i) {//cada modelo,...
        int max_satisfaccion = 0;
        for (int t = 0; t < n; ++t) {
            for (int z = 0; z < n; ++z) {
                if (max_satisfaccion < trajes[i][t] * zapatos[i][z]) {
                    max_satisfaccion = trajes[i][t] * zapatos[i][z];
                }
            }
        }
        max_satisfacciones[i] = max_satisfaccion;
    }
    vector<int> max_satisfaccion_acum(n);
    max_satisfaccion_acum[n - 1] = max_satisfacciones[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_satisfaccion_acum[i] = max_satisfaccion_acum[i + 1] + max_satisfacciones[i];
    }

    int max_sol = 0, actual_sol = 0;
    //vector<pair<int, int>> sol;
    // Realiza el cálculo del valor máximo según el problema
    pasarela(trajes, zapatos, 0, n, marcasT, marcasZ, max_satisfaccion_acum, max_sol, actual_sol);
    cout << max_sol << "\n";

    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Restablecimiento de la entrada
#ifndef PROXUS
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}