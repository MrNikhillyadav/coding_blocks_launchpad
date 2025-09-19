#include <iostream>
#include <vector>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

//using recursion only
int fibo(int n ){
    cnt1++;
    //base case
    if( n==0 || n ==1){
        return n;
    }

    // recursive case
   return fibo(n-1) + fibo(n -2);
}


int fiboTopDown(int n, vector<int>& dp){
    cnt2++;
    //lookup 
    if(dp[n] != -1){
        return dp[n];
    }

    // base case
    if( n== 0  || n == 1){
        return dp[n] = n;
    }

    // recursive case
    return dp[n] = fiboTopDown(n-1,dp) + fiboTopDown(n-2,dp);
}

// iterative approach
int fiboBottomUp(int n){
    
    cnt3++;
    // dp array of size n + 1
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    // iterative loop
    for( int i=2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


// int fiboBottomUpSpaceOptimised(int n){

// }


int main(){
    int n = 7;
    
    cout << fibo(n) << endl;
    cout << "cnt1: " << cnt1 << endl;

    vector<int> dp(n+1, -1);
    
    cout << fiboTopDown(n,dp) << endl;
    cout << "cnt2 steps: " << cnt2 << endl;
    
    cout << fiboBottomUp(n) << endl;
    cout << "cnt3 steps: " << cnt3 << endl;

    // cout << fiboBottomUpSpaceOptimised(n) << endl;


    return 0;
}