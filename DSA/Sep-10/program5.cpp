/*
    There are a given n ropes of different length, we need to connect these ropes into one rope.
    The cost to connect two ropes is equeal to the sum of their lengths, we need to connect the ropes
    with minimum cost.

    Example:
        Input : {4,3,2,6}
        output: 29
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    vector<int> ropeLengths = { 4, 3, 2, 6};
    priority_queue<int,vector<int>, greater<int>> minHeap;

    for(int i = 0; i < ropeLengths.size(); i++){
            minHeap.push(ropeLengths[i]);
    }
    
    int totalMinCost = 0;

    while(minHeap.size() > 1){
        int firstSmallestLen = minHeap.top(); // 2
        minHeap.pop();

        int secondSmallestLen = minHeap.top(); // 3
        minHeap.pop();

        int mergeCost = firstSmallestLen + secondSmallestLen;
        totalMinCost += mergeCost;

        minHeap.push(mergeCost);
    }

    cout << totalMinCost << endl;
    return 0;
}   