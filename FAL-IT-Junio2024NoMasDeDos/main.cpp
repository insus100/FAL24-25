// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
/*int resolver(vector<int> const& v, int k, int n) {
    int segs = 0, elems = -1, maxElems = 0;
    int const MAX_ELEMS = 3;
    for (int i = 0; i < k - 1; i++) {
        if (v[i] < v[i + 1]) {
            if (elems == -1)
                elems = 2;
            else elems++;
            maxElems = max(elems, maxElems);
        }
        else elems = -1;
    }
    if (maxElems < MAX_ELEMS)
        segs++;

    for (int i = k; i < n; i++) {//i es el final del intervalo
        int ini = i - k + 1;
        if (v[ini - 1] < v[ini]) {
            if (elems == -1) {
                maxElems--;
            }
            maxElems = max(elems, maxElems);
        }
        if (v[i - 1] < v[i]) {
            if (elems == -1)
                elems = 2;
            else elems++;
            maxElems = max(elems, maxElems);
        }
        else elems = -1;

        if (maxElems < MAX_ELEMS)
            segs++;
    }

    return segs;
}*/
//ahi se puede cambiar toda la chingadera para cambiar el tamaño del segmento, el problema es mucho más sencillo.
/**
* noMasDeDos(v, p, q) = ¬Ei : p <= i <= q - 3 : v[i] < v[i + 1] < v[i + 2]
* { K >= 3 && long(v) >= k
* fun contarSegmentos(v, k) ret int cantidad
* { cantidad = #w : k <= w <= long(v) : noMasdeDos(v, w - k, w) }
*
* Invariante = Debilitar la postcondicion, es decir, cambiar la longitud del vector por el indice por el momento
* I = cantidad = #u : k <= u <= w : noMasdeDos(v, u - k, u)
*
* seg = max u: 0 <= u <= w - 3 && v[u] < v[u + 1] < v[u + 2] : u
*/

int resolver(vector<int> const& v, int k, int n) {
    int seg = -1, segs = 0, maxElems = 0;
    int const MAX_ELEMS = 3;
    for (int i = 0; i < k - 2; i++) {
        if (v[i] < v[i + 1] && v[i + 1] < v[i + 2]) {
            seg = i;
        }
    }
    if (seg == -1)
        segs++;

    for (int i = k + 1; i <= n; i++) {//i es el final del intervalo
        if (v[i - 3] < v[i - 2] && v[i - 2] < v[i - 1])
            seg = i - 3;

        if (seg < i - k)//si el inicio del segmento está antes de la ventana, entonces este no cumple lo de >= a 3 elementos crecientes.
            segs++;
    }

    return segs;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;
    if (n == 0)
        return false;
    cin >> k;
    vector<int> v(n);

    for (int& c : v)
        cin >> c;

    int sol = resolver(v, k, n);

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
