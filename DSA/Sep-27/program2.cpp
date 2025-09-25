/*
    Minimum Sum path
*/

#include<iostream>
#include<vector>
using namespace std;

int minSumPath(vector<vector<int>> grid, int m, int n, int i, int j) {
    
}


int minSumPathTopDown(vector<vector<int>> grid, int m, int n, int i, int j,vector<vector<int>>&dp) {

}


int minSumBottomUp(vector<vector<int>>grid,int m,int n){

}


int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    cout << minSumPath(grid, m, n, 0, 0) << endl;

    return 0;
}
