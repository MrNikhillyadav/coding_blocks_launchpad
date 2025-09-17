/*
    Implement a phonebook storing mapping between person's name and their phone numbers
    using an unordered_map;
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, vector<string>> phoneMap;

    phoneMap["Abhishek"].push_back("1234");
    phoneMap["Abhishek"].push_back("5678");
    phoneMap["Abhishek"].push_back("0000");

    phoneMap["Shashank"].push_back("1111");
    phoneMap["Shashank"].push_back("2222");

    for (pair<string, vector<string>> contact : phoneMap) {
        string contactName = contact.first;
        vector<string> phoneNums = contact.second;
        cout << contactName << " : ";
        
        for (string num : phoneNums) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
