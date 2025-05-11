#include <iostream>
#include <vector>
using namespace std;

class Deque{
    int front;
    int back;
    vector<int> deque[50];

    public:
    Deque(){
        int front = 0;
        int back = 0;
    }
    void push_front(int x){
        

    }
    void push_back(int x);
    void pop_front();
    void pop_front();
    void front();
    void back();    
}
