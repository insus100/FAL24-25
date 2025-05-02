//
// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario del juez de examen que has utilizado en la prueba de hoy
//

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;
// Aqui ecuaciones recursivas (función recursiva) que resuelven el problema. 
// Se puede elegir dar las ecuaciones para una recursión final 
// o para una no final.
//
//
//


// Función recursiva no final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionNoFinal(int n1) {

    // Aqui el código del alumno


}


// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int n, int maxder, int pot) {
    if (n < 10) {//caso base, ultima llamada recursiva.
        if (n < maxder) return 0;//si es menor se elimina.
        else return n * pot;
    }

    int digito = n % 10;

    if (digito >= maxder) return digito * pot + recursionFinal(n / 10, max(maxder, digito), pot * 10);
    else return recursionFinal(n / 10, max(maxder, digito), pot);
}


void  resuelveCaso() {
    // lectura de los datos
    int numero;
    std::cin >> numero;
    // LLamadas a las funciones recursivas
    // Modificar parámetros o tipo de retorno donde se necesite
    int s1 = recursionNoFinal(numero);
    int s2 = recursionFinal(numero);
    // Escribir los resultados. Modificar si se necesita
    std::cout << s1 << ' ' << s2 << '\n';
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
