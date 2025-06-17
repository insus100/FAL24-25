/*********************************************************************** *
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

//INV: 
//Bucle: 
//Cota: 

int contarSegmentos(const std::vector<int>& v, int l) {
    int length = 1, segmentos = 0;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            length++;
        }
        else {
            if (length >= l) {
                segmentos += (length - l + 1) * (length - l + 2) / 2;
            }
            length = 1;
        }
    }

    if (length >= l) {
        segmentos += (length - l + 1) * (length - l + 2) / 2;
    }

    return segmentos;
}

void tratar_caso() {

    int l, n;

    std::cin >> l >> n;

    std::vector<int> v(n);

    for (int& vi : v) {

        std::cin >> vi;
    }

    std::cout << contarSegmentos(v, l) << std::endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { tratar_caso(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}