#include <iostream>
#include <math.h>
#include <fstream>
#include <climits>

using namespace std;

/*COSTE (caso peor):
*
*/

pair<int, int> calcularCodigo(int n, int pos, int nDer) {
    if (n < 10) {
        return { n, n * 3 + nDer };
    }
    int digito = n % 10;

    pair<int, int> c = calcularCodigo(n / 10, pos - 1, min(digito, nDer));
    if (pos % 2 == 0) {// pos par
        return { max(c.first, digito), (digito * 2 + c.first) + c.second };
    }
    else { // pos impar
        return { max(c.first, digito), (digito * 3 + nDer) + c.second };
    }
}

void tratar_caso() {
    int n;
    cin >> n;

    int numDigitos = (n == 0) ? 1 : log10(n) + 1;
    pair<int, int> codigo = calcularCodigo(n, numDigitos, INT_MAX);

    cout << codigo.second << "\n";
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
    system("PAUSE");
#endif
    return 0;
}