// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
pair<int, vector<int>> resolver(vector<int> const &v, int n, int L) {
    int cont = 0, ini = -1, lon = 0;
    vector<int> sol;
    for (int i = 0; i < n - 1; i++) {

        if (abs(v[i] - v[i + 1]) <= 1) {
            if (ini == -1) {
                ini = i;
                lon++;
            }
            else {
                lon++;
                if (i == n - 2) {//si el intervalo terminal al final del vector hay que guardarlo antes de salir del bucle.
                    if (lon + 1 >= L) {
                        cont++;
                        sol.push_back(ini);
                    }
                }
            }
        }
        else {
            if (ini != -1) {
                if (lon + 1 >= L) {
                    cont++;
                    sol.push_back(ini);
                }
            }
            ini = -1;
            lon = 0;
        }

        /*if (ini == -1) {//si no hay intervalo...
            if (abs(v[i] - v[i + 1]) <= 1) {
                ini = i;
                lon++;
            }
        }
        else {//si esta en un intervalo
            if (abs(v[i] - v[i + 1]) <= 1) {//si se sigue cumpliendo se incrementa lon
                lon++;
            }
            else { // si no hay que ver si es suficientemente largo y añadirlo para pintarlo.
                if (lon + 1 >= L) {
                    cont++;
                    sol.push_back(ini);
                }
                ini = -1;
                lon = 0;
            }
        }*/
        
    }

    return { cont, sol };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    pair<int, vector<int>> sol = resolver(v, n, L);

    // escribir sol
    cout << sol.first << " ";
    for (int c : sol.second)
        cout << c << " ";
    cout << "\n";
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
