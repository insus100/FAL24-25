// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
    if (ini == fin) return v[ini];

    int mid = (ini + fin) / 2;
    int izq = resolver(v, ini, mid);
    int der = resolver(v, mid + 1, fin);

    if (izq == der) return izq;

    // Contar cuántas veces aparece cada candidato en el rango actual
    int countIzq = 0, countDer = 0;
    for (int i = ini; i <= fin; ++i) {
        if (v[i] == izq) countIzq++;
        if (v[i] == der) countDer++;
    }

    return (countIzq > countDer) ? izq : der;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;

    int c;
    cin >> c;
    while (c != 0) {
        v.push_back(c);
        cin >> c;
    }
    if (v.empty()) {
        cout << "NO\n";
        return;
    }

    int num = resolver(v, 0, v.size() - 1);
    int cont = 0;
    for (int c : v)
        if (c == num) cont++;
    // escribir sol
    if (cont > v.size() / 2) cout << num << "\n";
    else cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}