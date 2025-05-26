// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct figura {
    int coste;
    int area;
};

// función que resuelve el problema
void belen(vector<figura> const& escaparate, vector<bool>& marcas, int objetos, int presupuesto, figura& solucion, figura parc_solucion, int figuras) {
    figura mi_sol, mi_figura;
    //----- Hijo izq 
    marcas[figuras] = true;
    mi_figura = escaparate[figuras];
    mi_sol = parc_solucion;//parcial_solucion
    mi_sol.area += mi_figura.area;
    mi_sol.coste += mi_figura.coste;
    if (mi_sol.coste <= presupuesto) {//es_Valida (si cabe dentro de la mochila, me la quedo
        if (figuras == (objetos - 1)) { // es_Solucion (si ya es el ultimo objeto, verifico areas)
            if (mi_sol.area > solucion.area) { solucion = mi_sol; }
        }
        else {
            belen(escaparate, marcas, objetos, presupuesto, solucion, mi_sol, figuras + 1);
        }
    }
    //------ Hijo der:
    marcas[figuras] = false;
    if (figuras == objetos - 1) {//si ya he terminado la recursion...
        if (parc_solucion.area > solucion.area) {
            solucion = parc_solucion;
        }
    }
    else {
        belen(escaparate, marcas, objetos, presupuesto, solucion, parc_solucion, figuras + 1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (caso especial)
        return false;

    TipoSolucion sol = resolver(datos);

    // escribir sol

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
