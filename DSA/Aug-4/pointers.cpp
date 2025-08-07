/*
 * Title: C++ Vector Operations Demo
 * Description: A collection of basic operations on vectors in C++,
 *              including declaration, initialization, addition, removal,
 *              insertion, deletion, traversal, and modification.
 * Author: Nikhil Yadav 
 * Date: August 4, 2025
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Declaration
    vector<int> v1;  // Declares an empty vector of integers

    // 2. Initialization
    vector<int> v2 = {10, 20, 30, 40, 50};  // List initialization
    vector<int> v3(5, 99); // Five elements, all 99: {99, 99, 99, 99, 99}

    // 3. Adding Elements (push_back)
    v1.push_back(5);    // v1 = {5}
    v1.push_back(15);   // v1 = {5, 15}
    v1.push_back(25);   // v1 = {5, 15, 25}

    // 4. Removing Last Element (pop_back)
    v1.pop_back();      // v1 = {5, 15}

    // 5. Insertion at Specific Position
    // Insert 100 at index 1 (second position)
    v1.insert(v1.begin() + 1, 100);   // v1 = {5, 100, 15}

    // 6. Deletion at Specific Position
    // Remove element at index 0 (first position)
    v1.erase(v1.begin());             // v1 = {100, 15}

    // 7. Traversing (Accessing All Elements)
    cout << "Elements of v2 using simple for loop: ";
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << "Elements of v2 using range-based for loop: ";
    for (int val : v2) {
        cout << val << " ";
    }
    cout << endl;

    // 8. Modifying Elements
    v2[2] = 300;    // Modify third element
    cout << "After modification, v2: ";
    for (int val : v2) cout << val << " ";
    cout << endl;

    // 9. Other Useful Operations
    cout << "Size of v3: " << v3.size() << endl;    // Number of elements
    cout << "Is v1 empty? " << (v1.empty() ? "Yes" : "No") << endl;

    // 10. Clearing the Vector
    v3.clear();
    cout << "Cleared v3. New size = " << v3.size() << endl;

    return 0;
}

/* 
 * =========================
 *        EXPLANATION
 * =========================
 * 1. Declaration:
 *      vector<int> v;           // Declares empty integer vector.
 *
 * 2. Initialization:
 *      vector<int> v1 = {1,2};  // List of values.
 *      vector<int> v2(5, 7);    // Five 7's.
 *
 * 3. Adding - .push_back(value)
 *      Adds element at the end.
 *
 * 4. Removing - .pop_back()
 *      Removes last element.
 *
 * 5. Inserting - .insert(iterator, value)
 *      Inserts element at given position.
 *      Eg: v.insert(v.begin() + idx, val);
 *
 * 6. Deleting - .erase(iterator)
 *      Removes element at given position.
 *      Eg: v.erase(v.begin() + idx);
 *
 * 7. Traversing:
 *      - Indexing: v[i]
 *      - Iterator/range-based loop: for(auto x : v)
 *
 * 8. Modifying:
 *      Assign to v[i].
 *
 * 9. Other Methods:
 *      .size(), .empty(), .clear()
 *
 * Good practices:
 * - Always check indices before modifying.
 * - Use .clear() to empty a vector.
 * - Prefer range-based for loops for readability.
 */
