/*
    check for duplicates in the given vector array
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

//approach 1
bool f(vector<int> v) {
    unordered_map<int, int> freqMap;
    for (int i = 0; i < v.size(); i++) {
        freqMap[v[i]]++;
        if (freqMap[v[i]] > 1) {
            return true;
        }
    }
    return false;
}


// approach 2
bool f2(vector<int> v) {
    unordered_set<int> us;

    for (int i = 0; i < v.size(); i++) {
        if (us.find(v[i]) == us.end()) {
            // you are seeing v[i] for the 1st time
            us.insert(v[i]);
        } else {
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> v = {1,2,3,1,1,2};

    f(v) ? cout << "duplicate found" << endl: cout << "no duplicate found" << endl;
    f2(v) ? cout << "duplicate found" << endl: cout << "no duplicate found" << endl;
    
    return 0;
}