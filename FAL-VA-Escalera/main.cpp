// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct profile {
    int stock;
    int precio;
};
bool es_Valida(vector<int> const& anchos, vector<profile> const& paints, vector<int> const& tupla, int coste_local, int gasto, int piso, int i) {
    if (paints[i].stock < anchos[piso]) { return false; }//No tengo pintura lo que viene a ser siendo suficiente para pintar el escalon
    if (piso != 0) {
        if (tupla[piso - 1] == i) { return false; }
    }
    if (gasto <= coste_local) { return false; }
    return true;
}
// función que resuelve el problema
void pintar(vector<int> const&anchos, vector<profile> &paints, vector<int> &tupla, int escalones, int colores, int piso, int coste_parcial, int &gasto, vector<int> &tupla_sol) {
    int coste_local;
    for (int i = 0; i < colores; ++i) {
        tupla[piso] = i;
        coste_local = coste_parcial + anchos[piso] * paints[i].precio;
        if (es_Valida(anchos, paints, tupla, coste_local, gasto, piso, i)) {
            paints[i].stock -= anchos[piso];
            if (piso == (escalones - 1)) {
                if (coste_local < gasto) {
                    tupla_sol = tupla;
                    gasto = coste_local;
                }
            }
            else {
                pintar(anchos, paints, tupla, escalones, colores, piso + 1, coste_local, gasto, tupla_sol);
            }
            paints[i].stock += anchos[piso];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int escalones, colores, aux;
    cin >> escalones;
    if (escalones == -1)
        return false;
    cin >> colores;
    vector<int> anchos(escalones);
    vector<profile> paints(colores);//cantidad y precio
    int gasto = INT_MAX;
    for (int i = 0; i < escalones; ++i) {
        cin >> anchos[i];
    }
    for (int i = 0; i < colores; ++i) {
        cin >> paints[i].stock >> paints[i].precio;
    }
    vector<int> tupla(escalones);
    vector<int> tupla_sol;
    pintar(anchos, paints, tupla, escalones, colores, 0, 0, gasto, tupla_sol);
    if (tupla_sol.size() > 0) {
        cout << gasto << "\n";
        for (int i = 0; i < escalones; i++) {
            cout << tupla_sol[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
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
