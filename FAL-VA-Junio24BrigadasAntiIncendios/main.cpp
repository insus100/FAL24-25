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
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

void asignar_vigilantes(vector<vector<int>> const& distancias, vector<int> const& tamMinimo, vector<int>& vig_por_brigada, int& necesarios, int distMaxima, int& num_completadas, int k, int n, int m, int& min_actual, int& min_global, vector<int> const& dist_min_acum) {

    for (int i = 0; i < n; i++) {
        if (distancias[k][i] <= distMaxima) {
            vig_por_brigada[i]++;
            if (vig_por_brigada[i] == tamMinimo[i]) num_completadas++;
            if (vig_por_brigada[i] <= tamMinimo[i]) necesarios--;
            min_actual += distancias[k][i];
            if (k == m - 1) {//si se ha llegado al final (todas las brigadas asignadas)
                if (num_completadas == n) {
                    if (min_global == -1 || min_actual < min_global)
                        min_global = min_actual;
                }
            }
            else {
                //poda
                if (min_global == -1 || min_actual + dist_min_acum[k + 1] < min_global) {
                    if (m - k - 1 >= necesarios) {//m totales, k actual - 1 (los que faltan por asignar)
                        asignar_vigilantes(distancias, tamMinimo, vig_por_brigada, necesarios, distMaxima, num_completadas, k + 1, n, m, min_actual, min_global, dist_min_acum);
                    }
                }
            }
            min_actual -= distancias[k][i];
            if (vig_por_brigada[i] <= tamMinimo[i]) necesarios++;
            if (vig_por_brigada[i] == tamMinimo[i]) num_completadas--;
            vig_por_brigada[i]--;
        }
    }
}

bool resuelveCaso() {
    int n, m; // n: número de brigadas (montes), m: número de vigilantes contratados
    cin >> n >> m;
    if (n == 0 && m == 0) return false;

    // Leer tamaños mínimos de las brigadas
    vector<int> tamMinimo(n);
    for (int i = 0; i < n; i++) {
        cin >> tamMinimo[i];
    }
    int necesarios = 0;
    for (int i = 0; i < n; i++) {
        necesarios += tamMinimo[i];//para ver si tenemos suficientes Vigilantes para llenar las brigadas o hacer poda.
    }
    // Leer distancia máxima permitida
    int distMaxima;
    cin >> distMaxima;

    // Leer matriz de distancias
    vector<vector<int>> distancias(m, vector<int>(n));
    vector<int> distancias_minimas(m), distancias_minimas_acum(m);
    int aux = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distancias[i][j];
            aux = min(distancias[i][j], aux);
        }
        distancias_minimas[i] = aux;
        aux = INT_MAX;
    }
    distancias_minimas_acum[m - 1] = distancias_minimas[m - 1];
    for (int i = m - 2; i >= 0; --i) {
        distancias_minimas_acum[i] = distancias_minimas[i] + distancias_minimas_acum[i + 1];
    }
    vector<int> vig_por_brigada(n, 0);
    int num_completadas = 0;
    int min_global = -1, min_actual = 0;

    asignar_vigilantes(distancias, tamMinimo, vig_por_brigada, necesarios, distMaxima, num_completadas, 0, n, m, min_actual, min_global, distancias_minimas_acum);
    min_global == -1 ? cout << "IMPOSIBLE\n" : cout << min_global << "\n";
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