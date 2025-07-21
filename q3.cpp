#include <iostream>
#include <vector>
using namespace std;

void listaPraMatriz(const vector<vector<int>> &ladj) {
    int n = ladj.size();

    vector<vector<int>> madj(n, vector<int>(n, 0));// cria matriz n x n inicializada com 0

    // preenche a matriz a partir da lista
    for (int i = 0; i < n; i++) {
        for (int v : ladj[i]){// o v vai ser cada vetor de ladj[i] 
            madj[i][v] = 1;
        }
    }

    // imprime a matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << madj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Exemplo de lista de adjacência (não dirigido):
    vector<vector<int>> ladj = {
        {1, 2},     // vizinhos do vértice 0
        {0, 2},     // vizinhos do vértice 1
        {0, 1, 3},  // vizinhos do vértice 2
        {2}         // vizinhos do vértice 3
    };

    listaPraMatriz(ladj);

    return 0;
}
