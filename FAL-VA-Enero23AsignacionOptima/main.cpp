#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Función para verificar si una solución parcial es válida
bool esValida(bool usada, int min, int max, int P, int asignadas) {

    asignadas += P;
    // Verificar si las necesidades mínimas de todas las ciudades están cubiertas
    if (!usada && asignadas <= max) {
        return true;
    }
    else {
        return false;
    }
}

// Función para verificar si una solución parcial es solución completa
bool esSolucion(int k, int n, int asignadas, int min) {
    return k == n - 1 && asignadas >= min;
}

// Función para tratar una solución completa
void tratarSolucion(int& minimo, int sueldos, vector<bool>& usadas, vector<int> const& P, int m, int r) {
    // Actualizar el mínimo de personas asignadas si la solución actual es mejor
    for (int i = 0; i < m; i++) {
        if (!usadas[i]) {
            sueldos += P[i] * r;
        }
    }
    minimo = min(minimo, sueldos);
}

// Función principal de vuelta atrás con marcaje
void vueltaAtrasConMarcaje(int& minimo, int sueldos, vector<vector<int>> const& ciudades, vector<int> const& P, int k, const int n, const int m, const int r, vector<bool>& usadas, vector<int>& Pasignadas) {

    for (int i = 0; i < m; i++) {

        if (esValida(usadas[i], ciudades[0][k], ciudades[1][k], P[i], Pasignadas[k])) {
            sueldos += P[i] * ciudades[2][k];
            usadas[i] = true;
            Pasignadas[k] += P[i];

            if (esSolucion(k, n, Pasignadas[k], ciudades[0][k])) {
                tratarSolucion(minimo, sueldos, usadas, P, m, r);
            }
            else if (Pasignadas[k] < ciudades[0][k]) {
                vueltaAtrasConMarcaje(minimo, sueldos, ciudades, P, k, n, m, r, usadas, Pasignadas);
            }
            else {
                vueltaAtrasConMarcaje(minimo, sueldos, ciudades, P, k + 1, n, m, r, usadas, Pasignadas);
            }

            usadas[i] = false;
            Pasignadas[k] -= P[i];
            sueldos -= P[i] * ciudades[2][k];
        }
    }
}

void resolverCaso() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> ciudades(3, vector<int>(n));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> ciudades[i][j];
        }
    }

    vector<int> P(m);
    for (int i = 0; i < m; ++i) {
        cin >> P[i];
    }

    vector<bool>usadas(m, false);
    vector<int>Pasig(n, 0);
    int minimo = INT_MAX;

    vueltaAtrasConMarcaje(minimo, 0, ciudades, P, 0, n, m, r, usadas, Pasig);

    if (minimo == INT_MAX) {
        cout << "NO\n";
    }
    else {
        cout << minimo << "\n";
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { resolverCaso(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Windows
    // system("PAUSE");
#endif
    return 0;
}