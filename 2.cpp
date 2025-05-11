#include <iostream>
using namespace std;

int BuscaPar(int v[], int x, int l, int r, int N) {
    while (l <= r) {
        int meio = (l + r) / 2;
        if (meio % 2 != 0) meio--; 
        if (meio < 0 || meio >= N) break;

        if (x == v[meio]) 
            return meio;
        else if (x < v[meio]) 
            r = meio - 2; 
        else 
            l = meio + 2; 
    }
    return -1;
}

int BuscaImpar(int v[], int x, int l, int r, int N) {
    while (l <= r) {
        int meio = (l + r) / 2;
        if (meio % 2 == 0) meio++; 

        if (meio < 0 || meio >= N) break;

        if (x == v[meio]) 
            return meio;
        else if (x < v[meio]) 
            l = meio + 2;
        else 
            r = meio - 2; 
    }
    return -1;
}

int BuscaBinaria(int v[], int x, int N) {
    int par = BuscaPar(v, x, 0, N-1, N);
    if (par != -1) return par;
    int impar = BuscaImpar(v, x, 0, N-1, N);
    return impar;
}

int main() {
    int A[] = {1, 50, 2, 40, 3, 30, 4, 20, 5, 10};
    int N = sizeof(A)/sizeof(A[0]);
    int x;
    cin >> x;
    int index = BuscaBinaria(A, x, N);
    cout << index << endl;
    return 0;
}