/*@ <answer>
 *
 * Nombre y Apellidos: Jaime Jiménez Nieto
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"
using namespace std;

/*@ <answer>
 
 Se busca el número mínimo de letras que hacen falta para conseguir que una palabra sea un palíndromo y su correspondiente palabra.
 Para ello se utilizará programación dinámica con la siguiente función recursiva:

 aibofobia(i, j) = número mínimo de letras que hacen falta para conseguir que una palabra se convierta en palindromo
 
 Como toda función recursiva se parte de varios casos básicos:
 - aibofobia (i, i) = 0 en el caso de que i == j
 - aibofobia (i, j) = 0 en el caso de que i > j
 Por contrapartida se tienen diversos casos recursivos:
 - aibofobia (i, j) = aibofobia(i + 1, j - 1) si palabra[i] == palabra[j]
 - aibofobia (i, j) = min(aibofobia(i + 1, j) + 1, aibofobia(i, j - 1) + 1) en caso contrario

 Se utilizará una matriz de dimensionalidad (N + 1) fila * (N + 1) columnas y se irá rellenando teniendo en cuenta la función recursiva
 explicada anteriormente. Una vez que se haya rellenado la matriz, la llamada a la función recursiva será aibofobia (0, n - 1).
 El resultado se restará al número de letras que contenía la palabra inicial y se obtendrá el número de letras que hay que añadir para obtener 
 el palíndromo.
 
 Una vez que se tenga esto, tocará reconstruir la palabra con el objetivo de conseguir dicho palindromo. Para ello se utilizará una vez más programación 
 dinámica con la siguiente función recursiva:
 - reconstruir (i, j) = palabra minima que se obtiene con j letras obtenidas de la 1 a la i.

 Como toda función recursiva se tienen diversos casos básicos:
 - reconstruir (i, j) = { } si i > j
 - reconstruir (i, j) = palabra[i] si i == j
 Por contrapartida, se tienen los siguientes casos recursivos:
 - reconstruir (i, j) = palabra[i] + reconstruir(i + 1, j) + palabra[j] si palabra[i] == palabra[j]
 - reconstruir (i, j) = reconstruir(i + 1, j) si palindromo[i + 1][j] == palindromo[i][j]
 - reconstruir (i, j) = reconstruir (i, j - 1) en caso contrario
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

EntInf aibofobia(string const& palabra, int i, int j, Matriz<EntInf> &M) {
   EntInf& res = M[i][j];
   if (res == Infinito) {
      if (i >= j)
         M[i][j] = 0;
      else if (palabra[i] == palabra[j]) //Tienen la misma letra en ambas posiciones
         M[i][j] = aibofobia(palabra, i + 1, j - 1, M);
      else 
         M[i][j] = min(aibofobia(palabra, i + 1, j, M) + 1, aibofobia(palabra, i, j - 1, M) + 1);
   }
   return M[i][j];
}

string reconstruir(string const& palabra, Matriz<EntInf> const& palindromo, int i, int j) {
   if (i > j)
      return { };
   if (i == j)
      return { palabra[i] };
   if (palabra[i] == palabra[j])
      return palabra[i] + reconstruir(palabra, palindromo, i + 1, j - 1) + palabra[j];
   else if (palindromo[i][j] == palindromo[i + 1][j])
      return palabra[i] + reconstruir(palabra, palindromo, i + 1, j) + palabra[i];
   else 
      return palabra[j] + reconstruir(palabra, palindromo, i, j - 1) + palabra[j];
}

bool resuelveCaso() {

   string palabra;
   cin >> palabra;
   if (!cin)
      return false;
   
   int n = palabra.size();
   Matriz<EntInf> M(n, n, Infinito);
   cout << aibofobia(palabra, 0, n - 1, M)  << " " << reconstruir(palabra, M, 0, n -1) << "\n";

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
