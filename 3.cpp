#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InsertionSort(vector<int> &v){
    int N =v.size();
    for(int i =0;i < N;i++){
        int j = i-1;
        if(v[j] <= v[i]) continue;
        else{
            while(v[j] > v[j+1] && j >=0){
                int key = v[j+1];
                v[j+1] = v[j];
                v[j] = key;
                j--;
            }
        }
    }
    cout << "Insertion Sort: ";
    for (int i : v)
    {
        cout << i << " ";
    }
}
    
void heapify(vector<int>& v,int i,int N){
    int node = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < N && v[node] < v[l]) node = l;
    if(r < N && v[node] < v[r]) node = r;

    if(node != i){
        swap(v[i],v[node]);
        heapify(v,node,N);
    }
}

void HeapSort(vector<int>& v){
    int N = v.size();
    for(int i = N/2 -1;i >=0 ;i--){
        heapify(v,i,N);
    }

    for(int i = N-1;i>0;i--){
        swap(v[i],v[0]);
        heapify(v,0,i);
    }
    cout << "Heap Sort: ";
    for(int i:v){
        cout << i << " ";
    }

}
int main()
{
    int r;
    vector<int> v = {13, 18, 5, 7, 11, 9, 6, 3, 2, 1, 8};

    cout << "Qual metodo de ordenacao voce quer utilizar?" << endl;
    cout << "1 - Insertion Sort" << endl;
    cout << "2 - Heap Sort" << endl;

    cin >> r;

    if (r == 1){
        InsertionSort(v);
    }else{
       HeapSort(v);
 }

    return 0;
}
