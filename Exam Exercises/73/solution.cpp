/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;

/*@ <answer>
  
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

struct Festival {
    int grupos;
    int precio;
};

class CompararGrupos {
public:
    bool operator()(Festival const& a, Festival const& b) const {
        return a.grupos > b.grupos || (a.grupos == b.grupos && a.precio < b.precio);
    }
};

vector<int> maximoConciertos(vector<Festival> const& grupos, int valor, int& numConciertos) {
    int n = grupos.size() - 1;
}



bool resuelveCaso() {

    int P, N;
    cin >> P >> N;
    if (!cin)
        return false;


    vector<Festival> grupos;
    while (N--) {
        int grupo;
        int precio;
        cin >> grupo >> precio;
        grupos.push_back({grupo, precio});
    }

    sort(grupos.begin(), grupos.end(), CompararGrupos());

    for (auto elem : grupos)
        cout << elem.grupos << " " << elem.precio << endl;

    Matriz<int> conciertos(N, N, 0);
    int numConciertos = 0;
    M

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
