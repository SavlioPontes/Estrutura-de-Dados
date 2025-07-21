#include <iostream>
#include <vector>
using namespace std;

void tranformarG3(const vector<vector<int>>& G)
{
    int n = G.size();
    vector<vector<int>> G3(n);

    for (int i = 0; i < n; i++)
    {
        for (int v : G[i])
        {
            for (int u : G[v])
            {
                for (int y : G[u])
                {
                    G3[i].push_back(y);
                }
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        cout << i << ": ";
        for (int u : G3[i])
        {
            cout << u << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    vector<vector<int>> G = {
        {1, 2}, // 0 -> 1, 0 -> 2
        {3},    // 1 -> 3
        {3},    // 2 -> 3
        {4},    // 3 -> 4
        {}      // 4 não aponta pra ninguém
    };
    tranformarG3(G);
}