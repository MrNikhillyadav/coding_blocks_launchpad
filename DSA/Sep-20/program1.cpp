// Min steps to 1

#include <iostream>
#include <vector>
using namespace std;

int minSteps(int n ){

    //base case
    if(n == 1) {
        // steps required to reduce 1 to 1;
        return 0;
    } 

    // recursive case

    // count min steps required to reduce n to 1

    // option 1 : reduce  n to n -1;
    // option 2 : reduce  n to n n/2;
    // option 3: reduce  n to n n/3;
}


int minStepsTopDown(int n, vector<int>& dp){
    // look up

    // base case

    // recursive case
}


int minStepsBottomUp(int n){

}


int main(){
    int n = 10;
    
    cout << minSteps(n) << endl;

    // vector<int> dp(n+1,-1)  ; // 0th index is not used;

    // cout << minStepsTopDown(n,dp) << endl;

    // cout << minStepsBottomUp(n) << endl;


    return 0;
}