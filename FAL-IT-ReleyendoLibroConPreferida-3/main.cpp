// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using lli = long long int;
using namespace std;
// función que resuelve el problema
lli resolver(vector<lli> const& v, int L, int preferida) {
    lli sum = 0, max = LLONG_MIN, index = 0, prefEnIntervalo = 0;
    for (int i = 0; i < L; i++) {
        sum += v[i];
        if (v[i] == preferida) prefEnIntervalo++;
    }
    if(prefEnIntervalo > 0)
        max = sum;
    for (int i = 1; i + L - 1 < v.size(); i++) {
        sum -= v[i - 1];
        sum += v[i + L - 1];
        if (v[i - 1] == preferida && prefEnIntervalo > 0) prefEnIntervalo--;
        if(v[i + L - 1] == preferida) prefEnIntervalo++;
        if (sum >= max && prefEnIntervalo > 0) {
            max = sum;
            index = i;
        }
    }
    return index;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0)
        return false;
    vector<lli> v(n);
    int preferida = INT_MIN;
    for (lli& p : v) {
        cin >> p;
        if (p > preferida) preferida = p;
    }
        
    lli sol = resolver(v, L, preferida);

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
