// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct voluntario {
    vector<int> kilos;
};
bool es_Valida(vector<int> const& acum, int n_volunt, int enviados, int l_cupo, int limpias, int recogido_bruto, int max_basura) {
    //
    // recogido + maxBasura para hacer el optimo
    // si el numero de enviados que me quedan con el numero de voluntarios que hay con el cupo de playas es suficiente para limpiarlas todas
    //
    if ((l_cupo - limpias) > (n_volunt - enviados)) { return false; }// no me quedan voluntarios
    if (enviados != (n_volunt - 1)) {
        if ((recogido_bruto + acum[enviados + 1]) < max_basura) { return false; }//Poda de optimos
    }
    return true;
}
// función que resuelve el problema
void limpiar(vector<voluntario> const &voluntarios, vector<int> &playas, vector<int> const &acum, int n_volunt, int m_playas, int l_cupo, int enviados, int recogido, int limpias, int &max_limpias, int &max_basura, bool &posible) {
    int aqui_recogido, local_limpias;
    //envío al usuario "enviados" a la playa "i":
    for (int i = 0; i < m_playas; ++i) {
        if (playas[i] > 0) {//sólo si la playa esta sucia....
            local_limpias = limpias;
            aqui_recogido = min(voluntarios[enviados].kilos[i], playas[i]);//el minimo entre lo que hay en el saco y lo que hay en la playa
            if (es_Valida(acum, n_volunt, enviados, l_cupo, limpias, recogido + aqui_recogido, max_basura)) {
                playas[i] -= aqui_recogido;
                if (playas[i] == 0) { ++local_limpias; }
                if (enviados == (n_volunt - 1)) {//Se han enviado todos los voluntarios
                    //actualizar solucion, miramos si cumple el cupo, si cumple, mido si es mejor sol.
                    //activar posible = true;
                    if (local_limpias >= l_cupo) {//Se cumple el cupo, me la quedo
                        posible = true;
                        if ((recogido + aqui_recogido) > max_basura) {
                            max_limpias = local_limpias;
                            max_basura = recogido + aqui_recogido;
                        }
                        else if (((recogido + aqui_recogido) == max_basura) && (local_limpias > max_limpias)) {
                            //Empata, pero tiene mas limpias
                            //el 4º caso de prueba deberia dar 14,1
                            max_limpias = local_limpias;
                        }
                    }
                }
                else {
                    limpiar(voluntarios, playas, acum, n_volunt, m_playas, l_cupo, enviados + 1, recogido + aqui_recogido, local_limpias, max_limpias, max_basura, posible);
                }
                playas[i] += aqui_recogido;//desmarcar
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> playas;// almacena la basura que hay en cada playa
    vector<voluntario> voluntarios;//esto emberdá es una matriz.
    int n_volunt, m_playas, l_cupo;
    int max_basura = 0, max_limpias = 0;
    bool posible = false;
    cin >> n_volunt >> m_playas >> l_cupo;
    int aux;
    for (int i = 0; i < m_playas; ++i) {
        cin >> aux;
        playas.push_back(aux);
        if (aux == 0) { ++max_limpias; }//si en la entrada ya hay una limpia (con cero de basura) la sumo aqui.
    }
    voluntario aux_vol;
    vector<int> acum;
    int acum_max;
    for (int i = 0; i < n_volunt; ++i) {
        aux_vol.kilos.clear();
        acum_max = 0;
        for (int j = 0; j < m_playas; ++j) {
            cin >> aux;
            aux_vol.kilos.push_back(aux);
            if (aux > acum_max) { acum_max = aux; }
        }
        voluntarios.push_back(aux_vol);
        acum.push_back(acum_max);
    }
    for (int i = (n_volunt - 1); i > 0; --i) {
        acum[i - 1] += acum[i];
    }
    limpiar(voluntarios, playas, acum, n_volunt, m_playas, l_cupo, 0, 0, max_limpias, max_limpias, max_basura, posible);
    if (posible) {
        cout << max_basura << " " << max_limpias << "\n";
    }
    else {
        cout << "IMPOSIBLE\n";
    }

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