#include <iostream>
#include <vector>
#include <algorithm> // para find
using namespace std;

void TipoGrafo(const vector<vector<int>> &ladj) {
    int n = ladj.size();

    // para cada vértice i
    for (int i = 0; i < n; i++) {
        // para cada vizinho v de i
        for (int v : ladj[i]) {
            // procurar se i aparece na lista de v
            if (find(ladj[v].begin(), ladj[v].end(), i) == ladj[v].end()) {
                //ele vai olhar na linha i se tem um vizinho v depois faz o oposto pesquisando o i no vetor v
                cout << "NÃO representa um grafo não-direcionado.\n";
                return;
            }
        }
    }

    cout << "Representa um grafo nao-direcionado.\n";
}

int main() {
    // Teste 1: Grafo que representa um não-direcionado
    vector<vector<int>> ladj = {
        {1, 2},   // 0 -> 1 e 0 -> 2
        {0, 2},   // 1 -> 0 e 1 -> 2
        {0, 1, 3},// 2 -> 0, 2 -> 1, 2 -> 3
        {2}       // 3 -> 2
    };

    TipoGrafo(ladj);
    return 0;
}
