#include <iostream>
#include <vector>
using namespace std;

void MatrizpraLista(const vector<vector<int>> &madj)
{
    int n = madj.size();
    int k = 0;
    vector<vector<int>> ladj(n);

    // preenche a lista a partir da matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { // o v vai ser cada vetor de ladj[i]
            if (madj[i][j] == 1)
            {
                ladj[i].push_back(j);
                k++;
            }
        }
        k = 0;
    }

    // imprime a matriz
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int v : ladj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Exemplo de lista de adjacência (não dirigido):
    vector<vector<int>> madj = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}};

    MatrizpraLista(madj);

    return 0;
}
