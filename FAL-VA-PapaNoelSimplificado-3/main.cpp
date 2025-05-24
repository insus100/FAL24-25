// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
void procesar_sol(vector<int> const& sol) {
    for (int const& s : sol)
        cout << s << " ";
    cout << "\n";
}
bool es_completable(int const k, int const n) {
    return k < n - 1;//o sea se no todos los niños tiene guguete
}
bool es_solucion(int const k, int const n) {
    return k == n - 1;//todos los niños tienen 2 juguetes.
}
bool es_valida(int const k, int const i, vector<int> const& sol, vector<string> const& tipos, vector<string> const& marcador) {
    return k % 2 == 0 || (sol[k - 1] < i && tipos[i] != marcador[k / 2]);
}
void papaNoel(bool& haySol, vector<string> const& tipos, int const num_juguetes, int const k, int const n, vector<int>& sol, vector<string>& marcador) {
    //k es el niño y ahora le asigno juguetes
    for (int i = 0; i < num_juguetes; ++i) {
        if (es_valida(k, i, sol, tipos, marcador)) {
            sol[k] = i;
            if (es_solucion(k, n)) {
                haySol = true;
                procesar_sol(sol);
            }
            else if (es_completable(k, n)) {
                marcador[k / 2] = tipos[i];
                papaNoel(haySol, tipos, num_juguetes, k + 1, n, sol, marcador);
                marcador[k / 2] = "";
            }
        }
    }
}
// función que resuelve el problema
bool resolver(int const num_juguetes, int const num_ninyos, vector<string> tipos) {
    bool haySol = false;

    int n = num_ninyos * 2;
    vector<int> sol(n);
    vector<string> marcador(num_ninyos, "");//marcador del tipo que tiene asignado el ninyo
    papaNoel(haySol, tipos, num_juguetes, 0, n, sol, marcador);//k es el niño

    return haySol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num_juguetes; cin >> num_juguetes;
    if (!std::cin)
        return false;
    int num_ninyos; cin >> num_ninyos;
    vector<string> tipos(num_juguetes);
    for (string& s : tipos)
        cin >> s;
    
    bool sol = resolver(num_juguetes, num_ninyos, tipos);

    // escribir sol
    if (!sol) cout << "SIN SOLUCION\n";
    else cout << "\n";

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