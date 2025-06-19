// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
// función que resuelve el problema
void resolver(vector<vector<int>> const& S, vector<bool> &asignada, int super, int k, int n, int m, int t, 
    vector<int> const &maximos_acum, int &satis_act, int &satis_max, int &num_sol) {

    for (int i = 0; i < n; ++i) {
        if (S[k][i] > -1 && !asignada[i]) {
            asignada[i] = true;
            satis_act += S[k][i];
            if (i == k)
                super++;

            if (super <= m / 3 && k == m - 1 && asignada[t]) {
                if (satis_act > satis_max) {
                    satis_max = satis_act;
                    num_sol = 1;
                }
                else if (satis_act == satis_max) num_sol++;
            }
            else if(super <= m / 3 && k < m - 1 && satis_act + maximos_acum[k + 1] >= satis_max) {
                resolver(S, asignada, super, k + 1, n, m, t, maximos_acum, satis_act, satis_max, num_sol);
            }

            asignada[i] = false;
            satis_act -= S[k][i];
            if (i == k)
                super--;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//personas que pueden ser invitadas al convite (invitados)
    cin >> n;
    if (n == 0)
        return false;
    int m, t;//personas que vamos a seleccionar (huecos) (k), puesto de familiares en el que esta tia Remedios
    cin >> m >> t;

    vector<vector<int>> S(m, vector<int>(n));
    vector<int> maximos(m), maximos_acum(m);
    int aux = INT_MIN;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> S[i][j];
            if (S[i][j] > aux)
                aux = S[i][j];
        }
        maximos[i] = aux;
        aux = INT_MIN;
    }
    maximos_acum[m - 1] = maximos[m - 1];
    for (int i = m - 2; i >= 0; --i) {
        maximos_acum[i] = maximos[i] + maximos_acum[i + 1];
    }

    vector<bool> asignada(n, false);
    int super = 0;//num de personas que han sido asignadas en el puesto igual que la lista
    int satis_act = 0, satis_max = INT_MIN, num_sol = 0;
    
    resolver(S, asignada, super, 0, n, m, t, maximos_acum, satis_act, satis_max, num_sol);

    satis_max == INT_MIN ? cout << "No\n" : cout << satis_max << " " << num_sol << "\n";

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
