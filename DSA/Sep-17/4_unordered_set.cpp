/*
    unordered_set : It  stores distinct keys in a unordered manner by default. 
                    Time complexity O(1), worst case : O(n);
*/

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // insert method
    unordered_set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.insert(2);

    cout << "size : " << s.size() << endl; // 5

    // delete an element
    s.erase(5);

    cout << "size : " << s.size() << endl; // 4

    // iterating over the set
    for (auto it = s.begin(), end = s.end(); it != end; it++) {
        //dereferencing iterator
        cout << *it << " ";
    }
    cout << endl;

    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;

    // find method
    if (s.find(3) != s.end()) {
        cout << "3 is present" << endl;
    } else {
        cout << "3 is absent" << endl;
    }

    // count method
    if (s.count(5)) {
        cout << "5 is present" << endl;
    } else {
        cout << "5 is absent" << endl;
    }

    //delete all the elements
    s.clear();

    cout << "size : " << s.size() << endl;

    s.empty() ? cout << "set is empty" << endl : cout << "set is not empty" << endl;

    return 0;
}
