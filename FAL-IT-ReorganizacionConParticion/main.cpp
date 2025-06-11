/***********************************************************************
* Prepara el resto de tus asignaturas y aprueba todos los exámenes
* finales con PROXUS!
*
* Todos los SPEEDRUNS disponibles:
* https://www.proxusacademy.com
*
* Creado por PROXUS Academy
***********************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap(vector<int>& v, int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
int particion(vector<int>& v, int a, int b) {
    int p = v[b]; // pivote, ultima posicion
    int i = a;
    int j = b - 1;
    while (i <= j) {
        if (v[i] < p)//si la pos de i es menor que el pivote, esta bien colocado.
            ++i;
        else if (v[j] >= p)
            --j;
        else {
            swap(v, i, j);
            ++i;
            --j;
        }
    }
    swap(v, i, b);
    return i;
}

bool resuelveCaso() {
    int n, p;
    cin >> n;
    if (n == 0) return false;
    cin >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (p != n - 1)
        swap(v, p, n - 1);
    int nuevaPosicion = particion(v, 0, n - 1);
    cout << nuevaPosicion << "\n";
    return true;
}

int main() {
#ifndef PROXUS
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}