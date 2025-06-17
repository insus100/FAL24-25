// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool es_Valida(int i, vector<bool>& marca, vector<char> const& aprobada, vector<int> const& prerrequisito) {
    if (marca[i] || aprobada[i] == 'A') return false;

    if (prerrequisito[i] != -1 && aprobada[prerrequisito[i]] == 'N') return false;


    return true;
}

// función que resuelve el problema
void resolver(vector<char> const &aprobada, vector<int> const&prerrequisitos, vector<int> const&creditos, vector<int> const& coste_matricula, vector<bool> &marcasA, int n, int C, int &creditos_matriculados, int &coste_min, int &coste_actual) {

    for (int i = 0; i < n; ++i) {//cada asignatura
        if (es_Valida(i, marcasA, aprobada, prerrequisitos)) {
            marcasA[i] = true;
            creditos_matriculados += creditos[i];
            coste_actual += coste_matricula[i];
            if (creditos_matriculados >= C) {//si se ha superado el número de creditos nesecarios:
                if (coste_actual < coste_min)
                    coste_min = coste_actual;
            }
            else {
                resolver(aprobada, prerrequisitos, creditos, coste_matricula, marcasA, n, C, creditos_matriculados, coste_min, coste_actual);
            }

            marcasA[i] = false;
            creditos_matriculados -= creditos[i];
            coste_actual -= coste_matricula[i];
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, C;//numero de asignaturas, creditos minimos
    cin >> n >> C;


    vector<char> aprobada(n);//Aprobada: A, subspensa: N
    for (char& c : aprobada)
        cin >> c;

    vector<int> prerrequisitos(n);//es otra asignatura: 0, 1. ... o -1 si no tiene.
    for (int& c : prerrequisitos)
        cin >> c;

    vector<int> creditos(n);
    for (int& c : creditos)
        cin >> c;

    vector<int> coste_matricula(n);
    for (int& c : coste_matricula)
        cin >> c;

    vector<bool> marcasA(n, false);
    int coste_min = INT_MAX, coste_actual = 0, creditos_matriculados = 0;
    //Poda optimalidad:
    vector<int> costes_acum(n);
    costes_acum[n - 1] = coste_matricula[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        costes_acum[i] = coste_matricula[i] + costes_acum[i + 1];
    }

    resolver(aprobada, prerrequisitos, creditos, coste_matricula, marcasA, n, C, creditos_matriculados, coste_min, coste_actual);

    if (coste_min == INT_MAX)
        cout << "NO\n";
    else
        cout << coste_min << "\n";
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