// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
struct Sol {
    int max_lon;
    int num_llanos;
    vector<int> sol;
};
// función que resuelve el problema
/*Sol resolver(vector<int>& v, int n, int l) {
    int ini = -1, lon = 0, max_lon = 0, max = INT_MIN, segmentos = 0;
    vector<int> sol;
    for (int i = n - 1; i > 0; i--) {
        if (v[i] > max) max = v[i];
        if (ini == -1) {// si no esta en un intervalo...
            if (v[i] == v[i - 1] && v[i] >= max) {
                ini = i;
                lon = 2;
                if (i == 1) {
                    if (v[i] >= max && lon >= l) {
                        if (lon > max_lon) max_lon = lon;
                        segmentos++;
                        sol.push_back(ini);
                    }
                }
            }
        }
        else {// si ya está en un intervalo
            if (v[i] == v[i - 1]) {//si sigue cumpliendose la condicion del intervalo
                lon++;
                if (lon > max_lon) max_lon = lon;
                if (i == 1) {//antes de que salga del bucle hay que registrar el resultado.
                    if (v[i] >= max && lon >= l) {
                            segmentos++;
                            sol.push_back(ini);
                            ini = -1;
                    }
                }
            }
            else {//si se termina la secuencia, verifico si es mayor que el max de la derecha
                if (v[i] >= max && lon >= l) {
                    segmentos++;
                    sol.push_back(ini);
                }
                ini = -1;
            }
        }
    }
    return { max_lon, segmentos, sol };
}*/

Sol resolver(vector<int>& v, int n, int l) {
    int ini = -1, lon = 0, max_lon = 0, maxi = INT_MIN, segmentos = 0;
    vector<int> sol;

    for (int i = n - 1; i >= 0; i--) {  // Ahora incluye i = 0
        if (i == n - 1 || v[i] > maxi) maxi = v[i];  // Actualizar máximo después de usarlo

        if (ini == -1) { // Si no está en un llano
            if (i > 0 && v[i] == v[i - 1] && v[i] >= maxi) {
                ini = i;
                lon = 2;
            }
        }
        else { // Si ya está en un llano
            if (i > 0 && v[i] == v[i - 1]) {
                lon++;
            }
            else { // Se terminó el llano
                if (v[i] >= maxi && lon >= l) {
                    segmentos++;
                    sol.push_back(ini);
                    max_lon = max(max_lon, lon);
                }
                ini = -1;
            }
        }
    }

    return { max_lon, segmentos, sol };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, l;
    cin >> n >> l;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    Sol sol = resolver(v, n, l);
    // escribir sol
    cout << sol.max_lon << " " << sol.num_llanos << " ";
    for (int i : sol.sol)
        cout << i << " ";
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