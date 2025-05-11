#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int valor;
    node* pai;
    node* esq;
    node* dir;
};

class arvore_bin {
    node* raiz;

    void pre_ordem(node* p);
    void pos_ordem(node* p);
    void em_ordem(node* p);
    void apaga(node* p);

public:
    arvore_bin(int N); // construtor
    ~arvore_bin();     // destrutor

    void reconstroi(int N);
    void reconstroi2(int N);
    void apaga_tudo();

    void pre_ordem();
    void pos_ordem();
    void em_ordem();
    void nivel_ordem();
};

arvore_bin::arvore_bin(int N) {
    raiz = nullptr;
    reconstroi(N);
}

arvore_bin::~arvore_bin() {
    apaga_tudo();
}

void arvore_bin::apaga(node* p) {
    if (p == nullptr) return;

    apaga(p->esq);
    apaga(p->dir);

    delete p;
}

void arvore_bin::apaga_tudo() {
    apaga(raiz);
    raiz = nullptr;
}

void arvore_bin::reconstroi(int N) {
    apaga_tudo();
    if (N <= 0) {
        raiz = nullptr;
        return;
    }

    int T = 1;
    raiz = new node{T++, nullptr, nullptr, nullptr};
    queue<node*> Q;
    Q.push(raiz);

    while (T <= N) {
        node* p = Q.front(); Q.pop();

        if (T <= N) {
            p->esq = new node{T++, p, nullptr, nullptr};
            Q.push(p->esq);
        }
        if (T <= N) {
            p->dir = new node{T++, p, nullptr, nullptr};
            Q.push(p->dir);
        }
    }
}

// Percursos
void arvore_bin::pre_ordem() {
    pre_ordem(raiz);
    cout << endl;
}
void arvore_bin::pre_ordem(node* p) {
    if (p == nullptr) return;
    cout << p->valor << " ";
    pre_ordem(p->esq);
    pre_ordem(p->dir);
}

void arvore_bin::pos_ordem() {
    pos_ordem(raiz);
    cout << endl;
}
void arvore_bin::pos_ordem(node* p) {
    if (p == nullptr) return;
    pos_ordem(p->esq);
    pos_ordem(p->dir);
    cout << p->valor << " ";
}

void arvore_bin::em_ordem() {
    em_ordem(raiz);
    cout << endl;
}
void arvore_bin::em_ordem(node* p) {
    if (p == nullptr) return;
    em_ordem(p->esq);
    cout << p->valor << " ";
    em_ordem(p->dir);
}

void arvore_bin::nivel_ordem() {
    queue <node*> q;
    q.push(raiz);

    while (!q.empty())
    {
        node* p = q.front();
        if(p->esq != nullptr) q.push(p -> esq);
        if(p->dir != nullptr) q.push(p-> dir);
        cout << p->valor<< " "  ; q.pop();
    }
}

int main() {
    arvore_bin tree(15);

    cout << "Pré-ordem: ";
    tree.pre_ordem();

    cout << "Em ordem: ";
    tree.em_ordem();

    cout << "Pós-ordem: ";
    tree.pos_ordem();

    cout << "Por nível: ";
    tree.nivel_ordem();

    return 0;
}
