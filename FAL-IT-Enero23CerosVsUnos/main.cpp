#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
// INV # {i | l <= i < v.size() && cerosUnos(v, i - l + 1, i)} == count
// Bucle: i < v.size()
// Cota: v.size() - 1 - i
// Especificar una función que cuente los segmentos de longitud l
int contarSegmentos(const vector<int>& v, int n, int l) { // C(O) = v.size() = n
    int segmentos = 1;
    if (n == l) return segmentos;
    int ceros = 0, unos = 0;
    //if (v[l] == 0) ceros++;
    //else if (v[l] == 1) unos++;
    for (int i = l; i < n; ++i) {
        int ini = i - l + 1;
        if (v[ini - 1] == 0) ceros--;
        else if (v[ini - 1] == 1) unos--;

        if (v[i] == 0) ceros++;
        else if (v[i] == 1) unos++;

        if (ceros == unos) segmentos++;
    }

    return segmentos;
}

void resolverProblema() {

    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << contarSegmentos(v, n, l) << "\n";

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { resolverProblema(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Windows
    // system("PAUSE");
#endif
    return 0;
}