#include <iostream>
#include <vector>
using namespace std;

class TwoStacks{
    int N;
    vector<int> ds;
    int top1;
    int top2;

    public:
    TwoStacks(int x) {
        N = x;
        ds.resize(x);
        top1 = -1;
        top2 = x;
    }

    void push1(int x){
        if(top1 + 1 == top2){
            cout << "VAI ESTOURAR!" << endl;
            return;
        }
        ds[++top1] = x;
    }
    void pop1(){
        if(top1 > -1){
            top1--;
        }
    }
    void top1Val(){
        if(top1 != -1) cout << "Topo stack1: " << ds[top1] << endl;
        else cout << "Pilha 1 vazia!" << endl;
    }
    void push2(int x){
         if(top1 + 1 == top2){
            cout << "VAI ESTOURAR!" << endl;
            return;
        }
        ds[--top2] = x;
    }
    void pop2(){
        if(top2 < N){
            top2++;
        }
    }
    void top2Val(){
        if(top2 != N) cout << "Topo stack2: " << ds[top2] << endl;
        else cout << "Pilha 2 vazia!" << endl;
    }
};  

int main(){
    TwoStacks pilhas(2);
    pilhas.push1(1);
    pilhas.push2(9);
    pilhas.top1Val();
    pilhas.top2Val();
    pilhas.push2(7);
    pilhas.top1Val();
    pilhas.pop1();
    pilhas.top1Val();
}