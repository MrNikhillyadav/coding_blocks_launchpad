#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, string> capitalMap;

    capitalMap.insert(make_pair("India","New Delhi"));
    capitalMap.insert({"France","Paris"});

    cout << "Map size: " << capitalMap.size() << endl;
    
    //using []
    
    capitalMap["Japan"] = "Tokyo";
    cout << "Map size: " << capitalMap.size() << endl;

    // iterating over the map

    for (auto it = capitalMap.begin(), end = capitalMap.end(); it != end; it++) {
        pair<string, string> p = *it;
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;

    for (pair<string, string> p : capitalMap) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;

    // using an iterator to iterate over buckets
    for (int i = 0; i < capitalMap.bucket_count(); i++) {
        cout << i << ": ";
        for (auto it = capitalMap.begin(i), end = capitalMap.end(i); it != end; it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
    }
    cout << endl;

    capitalMap["India"] = "Delhi";
    
    for (int i = 0; i < capitalMap.bucket_count(); i++) {
        cout << i << ": ";
        for (auto it = capitalMap.begin(i), end = capitalMap.end(i); it != end; it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
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

    
    // build an unordered_map using the initialiser list

    unordered_map<int, int> squareMap = {
        {1, 1},
        {2, 4},
        {3, 9},
        make_pair(4, 16),
        make_pair(5, 25)
    };

    cout << "size :" << squareMap.size() << endl;

    for (auto p : squareMap) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
