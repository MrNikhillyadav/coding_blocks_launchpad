#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // build an unordered_map using default constructor
    unordered_map<string, string> capitalMap;

    // inserting into a map

    // using unordered_map::insert

    capitalMap.insert(make_pair("India","New Delhi"));
    capitalMap.insert({"France","Paris"});

    // print map size using unordered_map::size
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

    // using for-each loop
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

    // updating a value corresponding to a key in a map using []
    capitalMap["India"] = "NewDelhi";
    for (int i = 0; i < capitalMap.bucket_count(); i++) {
        cout << i << ": ";
        for (auto it = capitalMap.begin(i), end = capitalMap.end(i); it != end; it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
    }
    cout << endl;

    // lookups

    // using unordered_map::find
    string key = "France";
    if (capitalMap.find(key) != capitalMap.end()) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }

    // using unordered_map::count
    if (capitalMap.count(key)) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }

    // deletion using unordered_map::erase

    // by key

    capitalMap.erase("France");
    cout << "size : " << capitalMap.size() << endl;
    if (capitalMap.find(key) != capitalMap.end()) {
        cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
    } else {
        cout << key << " is not found!" << endl;
    }


    // clear using unordered_map::clear

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
