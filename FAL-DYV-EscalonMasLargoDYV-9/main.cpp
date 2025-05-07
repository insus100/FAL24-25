// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Sol {
    int maxLen;     // Longitud del escalón más largo
    int iniVal;     // Valor del primer escalón
    int iniLen;     // Longitud del primer escalón
    int finVal;     // Valor del último escalón
    int finLen;     // Longitud del último escalón
};

Sol resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        return { 1, v[ini], 1, v[ini], 1 };
    }

    int m = (ini + fin) / 2;
    Sol izq = resolver(v, ini, m);
    Sol der = resolver(v, m + 1, fin);

    Sol res;

    // Inicialmente, el máximo es el mejor entre izquierda y derecha
    res.maxLen = max(izq.maxLen, der.maxLen);

    // Si el valor del final de la izquierda es igual al del principio de la derecha
    if (izq.finVal == der.iniVal) {
        int escalonCentral = izq.finLen + der.iniLen;
        res.maxLen = max(res.maxLen, escalonCentral);
    }

    // Primer escalón
    res.iniVal = izq.iniVal;
    if (izq.iniVal == der.iniVal && izq.iniLen == (m - ini + 1)) {
        res.iniLen = izq.iniLen + der.iniLen;
    }
    else {
        res.iniLen = izq.iniLen;
    }

    // Último escalón
    res.finVal = der.finVal;
    if (der.finVal == izq.finVal && der.finLen == (fin - m)) {
        res.finLen = der.finLen + izq.finLen;
    }
    else {
        res.finLen = der.finLen;
    }

    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;

    Sol sol = resolver(v, 0, n - 1);
    // escribir sol
    cout << sol.maxLen << "\n";
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
