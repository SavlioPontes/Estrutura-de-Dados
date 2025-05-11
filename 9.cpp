#include <iostream>
using namespace std;

struct node
{
    int valor;
    node *prox;
};

int
josephus(int n, int k)
{
    node *inicio = new node{1, nullptr};
    node *atual = inicio;
    cout << "Jogadores:" << endl;
    cout << 1 << " ";
    for (int i = 2; i <= n; i++)
    {
        atual->prox = new node{i, nullptr};
        atual = atual -> prox;
        cout << i << " ";
    }
    cout << endl;
    atual->prox = inicio;

    node *anterior = atual;
    atual = inicio;

    int vivos = n;

    while (vivos > 1)
    {
        int rodada = 1;
        for (int i = 0; i < k - 1; i++)
        {
            anterior = atual;
            atual = atual->prox;
        }
        cout << "MORREU: " << atual->valor << endl;

        atual = atual->prox;
        anterior->prox = atual;
        vivos--;

        cout << "Sobreviventes rodada " << rodada << ":" << endl;
        node *s = atual;
        for (int i = 0; i < vivos; i++)
        {
            cout << s->valor << " ";
            s = s->prox;
        }
        cout << endl;    
        rodada++;
    }
    return atual -> valor;
}

int main()
{
    int N = 10;
    int k = 2;

    int r = josephus(N, k);
    cout << "Quem sobra eh o " << r << endl;

    return 0;
}
