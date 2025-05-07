// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& v, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j++];
            invCount += (mid - i + 1); // Todos los elementos desde i hasta mid están invertidos con v[j]
        }
    }

    while (i <= mid) temp[k++] = v[i++];
    while (j <= right) temp[k++] = v[j++];

    for (int i = 0; i < k; ++i)
        v[left + i] = temp[i];

    return invCount;
}
// función que resuelve el problema
long long resolver(vector<int> &v, int ini, int fin) {
    if (ini >= fin) return 0;
    int mid = (ini + fin) / 2;
    long long invLeft = resolver(v, ini, mid);
    long long invRight = resolver(v, mid + 1, fin);
    long long invMerge = mergeAndCount(v, ini, mid, fin);
    return invLeft + invRight + invMerge;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    if (!std::cin)
        return false;
    cin >> n;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    long long sol = resolver(v, 0, n - 1);
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