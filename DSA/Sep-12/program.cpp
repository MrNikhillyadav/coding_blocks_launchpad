#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int n, int i){
    int maxIdx = i;

    int leftIdx = 2*i + 1;

    if( leftIdx < v.size() and v[leftIdx] > v[maxIdx]){
        maxIdx = leftIdx;
    }

    int rightIdx = 2*i + 2;

    if(rightIdx < v.size() and v[rightIdx] > v[maxIdx]){
        maxIdx = rightIdx;
    }

    if(maxIdx != i){
        swap(v[i], v[maxIdx]);
        heapify(v,n,maxIdx);
    }
}


int main(){ 
    vector<int> v = {20, 10, 50, 40, 30};
    int n = v.size();

    for( int i = n-1; i >= 0; i--){
        heapify(v,n,i);
    }
    
    int heapsize = n;

    while( heapsize > 1){
        swap(v[0], v[heapsize - 1]);
        heapsize--;
        heapify(v,heapsize, 0);
    }
    
    for(int i = 0; i <n; i++){
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}