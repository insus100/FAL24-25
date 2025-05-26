// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;
bool es_Valida(int min_dist, int min_coste, int coste_nuevo, int num_ciud, int k) {
    if ((coste_nuevo + (num_ciud - k) * min_dist) >= min_coste) return false;

    return true;
}
// función que resuelve el problema
void tsp(vector<vector<int>> const& matriz_costes, vector<int>& tour, int min_dist, vector<bool>& marcas, int num_ciud, int& min_coste, int coste_parcial, int k) {
    int coste_nuevo;
    for (int i = 1; i < num_ciud; ++i) {
        if (!marcas[i]) {
            coste_nuevo = coste_parcial + matriz_costes[tour[k - 1]][i];
            if (es_Valida(min_dist, min_coste, coste_nuevo, num_ciud, k)) {
                tour[k] = i;
                marcas[i] = true;
                if (k == (num_ciud - 1)) {
                    coste_nuevo += matriz_costes[0][i];
                    if (coste_nuevo < min_coste) {
                        min_coste = coste_nuevo;
                    }
                }
                else {
                    tsp(matriz_costes, tour, min_dist, marcas, num_ciud, min_coste, coste_nuevo, k + 1);
                }
                marcas[i] = false;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<vector<int>> matriz_costes;
    int num_ciud, min_coste = 0, min_dist = INT_MAX, aux;
    vector<int> vec_aux;
    vector<int> tour;
    vector<bool> marcas;
    cin >> num_ciud;
    vec_aux.resize(num_ciud);
    if (num_ciud == 0)
        return false;
    for (int i = 0; i < num_ciud; ++i) {
        for (int j = 0; j < num_ciud; ++j) {
            cin >> aux;
            vec_aux[j] = aux;
            if (aux != 0 && aux < min_dist) {
                min_dist = aux;
            }
        }
        matriz_costes.push_back(vec_aux);
    }

    for (int i = 1; i < num_ciud; ++i) {
        min_coste += matriz_costes[i - 1][i];//sumo los valores de la diagonal, me vale como solucion inicial.
    }
    min_coste += matriz_costes[num_ciud - 1][0];
    if (num_ciud > 3) {
        marcas.resize(num_ciud);
        tour.resize(num_ciud);
        tour[0] = 0;
        marcas[0] = true;
        tsp(matriz_costes, tour, min_dist, marcas, num_ciud, min_coste, 0, 1);
    }
    cout << min_coste << "\n";

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
