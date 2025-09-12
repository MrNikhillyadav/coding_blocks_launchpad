/*
    Given an infinite stream of non-negative integers, design an alogithm to output the top-k
    integers every time you encounter -1;

    Example:
        Input : 4,1,2,-1,3,-1,7,0,1,2,-1,8,-1,.....;   k=3
        output: 1 2 4
                2 3 4
                3 4 7 
                4 7 8
                . . .
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//printHeap
void printHeap(priority_queue<int, vector<int>, greater<int>> minHeap){
    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}



int main(){
    int k = 3;
    priority_queue<int, vector<int>,greater<int>>minHeap;

    // todo .......

    return 0;
}   