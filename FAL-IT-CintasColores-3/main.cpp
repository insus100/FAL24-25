// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cinta {
    char color;
    int longitud;
    bool operator<(Cinta& b) {
        return longitud < b.longitud;
    }
};
// función que resuelve el problema
pair<int, int> resolver(vector<Cinta> &v, int n) {
    int low = 0, mid = 0, high = n - 1;//inicio y fin de las verdes
    for (int i = 0; i < v.size(); i++) {
        if (v[mid].color == 'a') {
            Cinta c = v[mid];
            v[mid] = v[low];
            v[low] = c;
            low++;
            mid++;
        }
        else if (v[mid].color == 'v') {
            mid++;
        }
        else {
            Cinta c = v[high];
            v[high] = v[mid];
            v[mid] = c;
            high--;
        }
    }
    return { low, high };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<Cinta> v(n);
    for (Cinta& c : v)
        cin >> c.color >> c.longitud;


    pair<int, int> sol = resolver(v, n);
    // escribir sol
    vector<int> azules, verdes, rojas;
    for (int i = 0; i < n; i++) {
        if (v[i].color == 'a') azules.push_back(v[i].longitud);
        else if (v[i].color == 'v') verdes.push_back(v[i].longitud);
        else rojas.push_back(v[i].longitud);
    }

    sort(azules.begin(), azules.end());
    sort(verdes.begin(), verdes.end());
    sort(rojas.begin(), rojas.end());

    // Imprimir la salida en el formato correcto
    cout << "Azules:";
    for (int l : azules) cout << " " << l;
    cout << "\nVerdes:";
    for (int l : verdes) cout << " " << l;
    cout << "\nRojas:";
    for (int l : rojas) cout << " " << l;
    cout << "\n";

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