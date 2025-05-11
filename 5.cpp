#include <iostream>
using namespace std;

struct node{
    int valor;
    node* prox;
}

class listaS{
    node* inicio;
    node* fim;

    public:
        //metodos publicos:
        inveter_lista();
}

listaS::inveter_lista(){
    node* p = inicio;
    node* q = p ->prox;
    node* r = q ->prox;

    fim = inicio;
    inicio -> prox = null

    while (q != null)
    {
        q -> prox = p;
        p = q;
        q = r;
        if(r != null) r = r-> prox;
    }
    inicio = p;
}