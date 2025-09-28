/*
    Minimum Sum path Problem
*/

#include<iostream>
#include<vector>
using namespace std;

int minSumPath(vector<vector<int>> grid, int m, int n, int i, int j) {
    // bae case
    if( i == m-1 and j == n-1){
        return grid[i][j];
    }

    // recursive case
    if( i ==m-1){
        return grid[i][j] + minSumPath(grid, m,n, i, j+1);
    }

    if( j ==n-1){
        return grid[i][j] + minSumPath(grid, m,n, i+1, j);
    }

    int X = minSumPath( grid, m, n, i, j+1);
    int Y  = minSumPath( grid, m ,n, i+1, j);

    return grid[i][j] + min(X,Y);
}

int minSumPathTopDown(vector<vector<int>> grid, int m, int n, int i, int j,vector<vector<int>>&dp) {
    // lookup case
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // base case 
    if(i == m-1 and j == n-1){
        return dp[i][j] = grid[i][j];
    }

    // recursive case
    if( i == m-1){
        return dp[i][j] = grid[i][j] + minSumPathTopDown(grid, m,n,i,j+1, dp);
    }

    if( j == n-1){
        return dp[i][j] = grid[i][j] + minSumPathTopDown(grid, m,n,i+1,j, dp);
    }

    int X = minSumPathTopDown(grid, m,n, i ,j+1, dp);
    int Y = minSumPathTopDown(grid, m,n, i+1 ,j, dp);

    return dp[i][j] = grid[i][j] + min(X,Y);
}

int minSumBottomUp(vector<vector<int>>grid,int m,int n){
    vector<vector<int>> dp(m,vector<int>(n));

    for( int i = m-1; i >= 0; i--){
        for( int j = n-1; j>=0; j--){
            // dp[i][j] = f(i,j)
        if( i == m-1 and j == n-1){
            dp[i][j] = grid[i][j];
        }else if( i == m-1){
            dp[i][j] = grid[i][j] + dp[i][j+1];
        }else if( j == n-1){
            dp[i][j] = grid[i][j] + dp[i+1][j];
        }else {
            dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
        }
        }
    }

    return dp[0][0]; // at (0,0) index, we are storing f(0,0)
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

    vector<vector<int>> dp(m, vector<int>(n,-1));

    cout << minSumPathTopDown(grid, m,n,0,0, dp) << endl;

    cout << minSumBottomUp(grid,m,n) << endl;

    return 0;
}
