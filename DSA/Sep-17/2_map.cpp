/*
    What are maps ?

    Maps are associative containers that store elements formed by a combination of a key and a mapped
    valude, following a specific order. Internally, the elements in a map pare sorted by its key.

    Maps are typically implemented as binay search trees, and therefore are generally slower than
    unordered_map containers to access individual elements by their key.
*/


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> capitalMap;

    capitalMap.insert(make_pair("India","New Delhi"));
    capitalMap.insert({"France","Paris"});

    cout << "Map size: " << capitalMap.size() << endl;
    
    //using []
    
    capitalMap["Japan"] = "Tokyo";
    cout << "Map size: " << capitalMap.size() << endl;

    // iterating over the map

    // using an iterator
    for (auto it = capitalMap.begin(), end = capitalMap.end(); it != end; it++) {
        pair<string, string> p = *it;
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;

    for (pair<string, string> p : capitalMap) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;


    // lookups

    string key = "France";
    if (capitalMap.find(key) != capitalMap.end()) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }

    if (capitalMap.count(key)) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }


    capitalMap.erase("France");
    cout << "size : " << capitalMap.size() << endl;
    if (capitalMap.find(key) != capitalMap.end()) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }


    capitalMap.clear();
    cout << "size : " << capitalMap.size() << endl;

    capitalMap.empty() ? cout << "map is empty" << endl : cout << "map is not empty" << endl;

    
    map<int, int> squareMap = {
        {11, 121},
        {2, 4},
        {13, 169},
        make_pair(4, 16),
        make_pair(5, 25)
    };

    cout << "size :" << squareMap.size() << endl;

    for (auto p : squareMap) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
