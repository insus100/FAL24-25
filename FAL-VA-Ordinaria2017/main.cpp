// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct profile {
    int veces;
    int prim;
};
void imprimir(vector<int>& tupla) {
    for (int c : tupla)
        cout << c << " ";
    cout << "\n";
}
bool es_Valida(vector<profile>& marcas, int fin, int pos, int i) {
    if (marcas[i - 1].veces == 2) return false;//el numero no se puede poner más de 2 veces
    if (marcas[i - 1].veces == 1) {//si el numero esta puesto una vez, hay que ver que se pueda poner en la posicion actual (comparando con el primero)
        if (pos - marcas[i - 1].prim - 1 != i) { return false; }
        return true;
    }
    if ((fin - pos) <= i) { return false; }
    return true;
}

// función que resuelve el problema
void apariciones(vector<profile> &marcas, vector<int> & tupla, int n, int pos, int &total) {
    int fin = tupla.size() - 1;//ultima posicion (2n - 1)

    for (int i = 1; i <= n; ++i) {//i es el numero a colocar de 1 a n
        tupla[pos] = i;
        if (es_Valida(marcas, fin, pos, i)) {
            ++marcas[i - 1].veces;
            if (marcas[i - 1].veces == 1) { marcas[i - 1].prim = pos; }
            if (pos == fin) {
                ++total;
                imprimir(tupla);
            }
            else {
                apariciones(marcas, tupla, n, pos + 1, total);
            }
            --marcas[i - 1].veces;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, sols = 0;
    cin >> n;
    vector<profile> marcas(2 * n);
    vector<int> tupla(2 * n);

    apariciones(marcas, tupla, n, 0, sols);
    cout << "Soluciones: " << sols << "\n";
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