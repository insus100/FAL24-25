// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
pair<int, int> buscarIz(vector<int> const& v, int ini, int fin, int a) {
    if (ini == fin) {
        if (v[ini] == a) return { ini, -1 };
        else return { -1, -1 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] == a && v[fin] == a) return { ini, fin };
        else if (v[ini] == a) return { ini, -1 };
        else if (v[fin] == a) return { fin, -1 };
        else return { -1, -1 };
    }
    else {
        if (v[ini] == a && v[fin] == a) return { ini, fin };
        else {
            int m = (ini + fin) / 2;
            if (v[m] > a) return buscarIz(v, ini, m, a);//tiro por la izquierda
            else return buscarIz(v, m, fin, a);//tiro por la derecha
        }
    }
}
pair<int, int> buscarDer(vector<int> const& v, int ini, int fin, int a) {
    if (ini == fin) {
        if (v[ini] == a) return { -1, ini };
        else return { -1, -1 };
    }
    else if (ini + 1 == fin) {
        if (v[ini] == a && v[fin] == a) return { ini, fin };
        else if (v[ini] == a) return { -1, ini };
        else if (v[fin] == a) return { -1, fin };
        else return { -1, -1 };
    }
    else {
        if (v[ini] == a && v[fin] == a) return { ini, fin };
        else {
            int m = (ini + fin) / 2;
            if (v[m] > a) return buscarDer(v, ini, m, a);//tiro por la izquierda
            else return buscarDer(v, m, fin, a);//tiro por la derecha
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    cin >> n >> a;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& c : v)
        cin >> c;
    if (n == 0) cout << "0\n";
    else if (n == 1) v[0] == a ? cout << "0\n" : cout << "NO EXISTE\n";
    else if (n == 2) {
        if (v[0] == a) cout << "0\n";
        else if (v[1] == a) cout << "1\n";
        else cout << "NO EXISTE\n";
    }
    else {
        pair<int, int> solIzq{ -1, -1 }, solDer{ -1, -1 };
        int m = n / 2;

        if (v[m] > a) {//tiro por la izquierda
            solIzq = buscarIz(v, 0, m - 1, a);
        }
        else if (v[m] < a) {//tiro por la derecha
            solDer = buscarDer(v, m, n - 1, a);
        }
        else {//por los dos lados.
            solIzq = buscarIz(v, 0, m - 1, a);
            if (solIzq.first == -1) solIzq.first = m;
            solDer = buscarDer(v, m, n - 1, a);
            if (solDer.second == -1) solDer.second = m;
        }

        // escribir sol
        pair<int, int> sol{ solIzq.first, solDer.second };
        if (sol.first != -1 && sol.second != -1)
            cout << sol.first << " " << sol.second << "\n";
        else if (sol.first != -1)
            cout << sol.first << "\n";
        else if (sol.second != -1)
            cout << sol.second << "\n";
        else
            cout << "NO EXISTE\n";
    }
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