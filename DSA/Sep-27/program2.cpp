/*
    Knapsack problem
*/

#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> weights, vector<int> profits, int N, int i, int w) {
    if (i == N) {
        return 0;
    }

    if (w == 0) {                   //  optional
        return 0;
    }

    // recursive case
    if (weights[i] > w) {
         return helper(weights, profits, N, i + 1, w);
    }

    return max(
        profits[i] + helper(weights, profits, N, i + 1, w - weights[i]),
        helper(weights, profits, N, i + 1, w)
    );
}

// time : O(NW)
// space : O(NW + N ) ~ O(NW)
int helperTopDown(vector<int> weights, vector<int> profits, int N, int i, int w, vector<vector<int>>& dp) {
    // lookup case
    if(dp[i][w] != -1){
         return dp[i][w];
    }
    
    //base case
    if (i == N) {
        return dp[i][w]= 0;
    }

    if (w == 0) {                   
        return dp[i][w]= 0;
    }

    // recursive case
    if (weights[i] > w) {
         return dp[i][w] = helperTopDown(weights, profits, N, i + 1, w,dp);
    }

    return dp[i][w] = max(
        profits[i] + helperTopDown(weights, profits, N, i + 1, w - weights[i],dp),
        helperTopDown(weights, profits, N, i + 1, w, dp)
    );
}

int helperBottomUp(vector<int> weights, vector<int> profits, int N, int W) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1));

    // Initialize the base cases
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for (int w = 0; w <= W; w++) {
        dp[N][w] = 0;
    }

    // Filling the dp table 
    for (int i = N - 1; i >= 0; i--) {
        for (int w = 1; w <= W; w++) {
            if (weights[i] > w) {
                dp[i][w] = dp[i + 1][w];
            } else {
                // decide for the ith object:
        
                dp[i][w] = max(
                    profits[i] + dp[i + 1][w - weights[i]],
                    dp[i + 1][w]
                );
            }
        }
    }

    return dp[0][W]; 
}


int main() {
    int N = 5;
    int W = 4;

    vector<int> weights = {1, 2, 3, 2, 2};
    vector<int> profits = {8, 4, 1, 5, 3};

    cout << helper(weights, profits, N, 0, W) << endl;

    vector<vector<int>>dp(N+1, vector<int>(W+1,-1));
    cout << helperTopDown(weights, profits, N, 0, W, dp) << endl;

    cout << helperBottomUp(weights, profits, N, W) << endl;

    return 0;
}
