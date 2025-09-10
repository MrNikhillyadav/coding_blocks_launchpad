#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int n, int i){

}

int main(){ 
    vector<int> v = {20, 10, 50, 40, 30};
    int n = v.size();

    //1. transform the array into a maxheap

    for(int i= n-1; i >= 0; i--){
        heapify(v,n,i);
    }

    //2. transform the maxheap into a sorted arrya

    // todo ......


    
    //accessing elements
    for(int i = 0; i <n; i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}