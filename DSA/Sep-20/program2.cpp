/*  ROD CUTTING :

    Given a rod of length 'n' along with prices of its pieces of different lengths, 
    design an algorithm to compute the maximum profit we can make by cutting the rod 
    and selling its pieces.

    Example :

    Input : n = 8
        length = [1,2,3,4,5,6,7,8]
        prices = [1,5,8,9,10,17,17,20]
    Output : 22

    Input : n = 8
        length = [1,2,3,4,5,6,7,8]
        prices = [3,5,8,9,10,17,17,20]
    Output : 24

*/

#include <iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(int n, vector<int> p) {
    // base case
    if (n == 0) {
        // compute the max. profit given a rod of length 0
        return 0;
    }

    // recursive case
    // decide the next cut
    int  maxSoFar = INT_MIN;

    for( int j = 1; j <= n; j++){
        // make a cut of size j
        maxSoFar = max(maxSoFar, p[j-1] + maxProfit(n-j,p));
    }

    return maxSoFar;

}

int maxProfitTopDown( int n, vector<int> p, vector<int>& dp){
    //lookup
    if(dp[n] !=  -1){
        return dp[n];
    }

    //base capse
    if(n ==0){
        return dp[n] = 0;
    }

    // recursive case
    // decide the next cut
    int  maxSoFar = INT_MIN;

    for( int j = 1; j <= n; j++){
        // make a cut of size j
        maxSoFar = max(maxSoFar, p[j-1] + maxProfitTopDown(n-j,p, dp));
    }

    return dp[n] = maxSoFar;

}

// time : 0(N^2)
// space : 0(n) duce to the dp[];

int maxProfitBottomUp(int n, vector<int>p){
    vector<int> dp(n+1);

    dp[0] = 0; // at 0th INDEX, we store f(0);

    for( int i = 1; i<= n ; i++){
        int maxSoFar = INT_MIN;
    for(int j =1; j <= i; j++)
        // make a cut of size j
        maxSoFar = max(maxSoFar, p[j-1]+ dp[i-j]);
    }

    return dp[n]; // at nth index, storing f(n)
}

int main() {
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = p.size();

    cout << maxProfit(n, p) << endl;

    vector<int> dp(n+1, -1);

    cout << maxProfitTopDown(n,p,dp) << endl;

    cout << maxProfitBottomUp(n, p) << endl;

    return 0;
}
