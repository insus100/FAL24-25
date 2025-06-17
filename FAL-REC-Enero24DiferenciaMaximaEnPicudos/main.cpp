#include <iostream>
#include <vector>
#include <fstream>
#include <climits> // para INT_MIN

using namespace std;

int maxDiferenciaRecursiva(const vector<int>& v, int idx) {
    if (idx < 1) {
        return INT_MIN;
    }
    
    int maxDiff = maxDiferenciaRecursiva(v, idx - 1);

    int diffAct = v[idx] - v[idx - 1];

    return max(maxDiff, diffAct);
}

void tratar_caso() {

    int n;

    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    cout << maxDiferenciaRecursiva(vec, n - 1) << "\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { tratar_caso(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Windows
    // system("PAUSE");
#endif
    return 0;
}