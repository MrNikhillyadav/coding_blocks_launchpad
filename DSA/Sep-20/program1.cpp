// PROBLEM : Min steps to 1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSteps(int n ){

    //base case
    if(n == 1) {
        // steps required to reduce 1 to 1;
        return 0;
    } 

    // recursive case

    // option 1 : reduce  n to n -1;
    int x = minSteps(n-1);

    // option 2 : reduce  n to n n/2;
    int y = INT_MAX;
    if(n % 2 == 0){
        y = minSteps(n/2);
    }

    // option 3: reduce  n to n n/3;
    int  z= INT_MAX;
    if(n %3 == 0){
        z = minSteps(n/3);
    }

    return 1 + min(min(x, y), z);
}


int minStepsTopDown(int n, vector<int>& dp){
    // look up
    if(dp[n] != -1){
        return dp[n];
    }

    // base case
    if(n == 1){
        return dp[n] = 0;
    }

    // recursive case
    int x = minStepsTopDown(n-1,dp);

    
    int y = INT_MAX;
    if(n % 2 == 0){
        y = minStepsTopDown(n/2,dp);
    }

    int  z= INT_MAX;
    if(n %3 == 0){
        z = minStepsTopDown(n/3,dp);
    }

    return dp[n] = 1 + min(min(x, y), z)
;
}


int minStepsBottomUp(int n){
    vector<int> dp(n + 1);

    dp[1] = 0;

    for( int i =2; i <= n ;i++){
        int x = dp[i-1];

        int y = INT_MAX;
        if(n % 2 == 0){
            y = dp[i/2];
        }

        int z = INT_MAX;
        if( i%3 == 0){
            z = dp[i/3];
        }

        dp[i] = 1 + min(min(x, y), z)
;
    }

    return dp[n]; // at the nth index we store f(n)
}


int main(){
    int n = 10;
    
    cout << minSteps(n) << endl;

    vector<int> dp(n+1,-1)  ; // 0th index is not used;

    cout << minStepsTopDown(n,dp) << endl;

    cout << minStepsBottomUp(n) << endl;


    return 0;
}