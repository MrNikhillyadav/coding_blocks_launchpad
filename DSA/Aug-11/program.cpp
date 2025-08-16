/*
 * Title: C++ Singly Linked List - Insert at Given Index
 * Description: Implementation of linked list operations in C++ including:
 *              - Insertion at head
 *              - Traversal
 *              - Insertion at a given index (middle insertion)
 * Author: Nikhil Yadav
 * Date: August 11, 2025
 */

#include <iostream>
using namespace std;

// ===== NODE DEFINITION =====
class ListNode {
    public:
        int data;          // Value of the node
        ListNode* next;    // Pointer to the next node

        // Constructor
        ListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }
};


// ===== INSERTION AT HEAD =====

void insertAtHead(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}


// ===== PRINT LIST =====

void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// ===== GET PREVIOUS NODE =====

ListNode* getPrevNode(ListNode* head, int i) {
    ListNode* temp = head;
    int k = 0;
    while (k < i && temp != nullptr) {
        temp = temp->next;
        k++;
    }
    return temp;   // Returns nullptr if i is out of range
}


// ===== INSERT AT INDEX =====

void insertAtIndex(ListNode*& head, int data, int index) {
    if (head == nullptr && index > 0) {
        // Cannot insert in empty list (except index=0)
        return;
    }

    if (index == 0) {
        insertAtHead(head, data);
        return;
    }

    // Get node at (index-1)
    ListNode* prev = getPrevNode(head, index - 1);
    if (prev == nullptr) {
        return; // Invalid index (greater than list length)
    }

    ListNode* n = new ListNode(data);
    n->next = prev->next;
    prev->next = n;
}

int main() {
    ListNode* head = nullptr;

    // Create list: 10 -> 20 -> 30 -> 40
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Original Linked List:" << endl;
    printLinkedList(head);

    // Insert 80 at index 2
    cout << "\nInsert 80 at index 2:" << endl;
    insertAtIndex(head, 80, 2);
    printLinkedList(head);

    return 0;
}

/*
 * =====
 *        EXPLANATION
 * =====
 * 1. Insert at Head:
 *      Creates a new node, points it to current head, updates head.
 *
 * 2. Traversal:
 *      Start from head, iterate until nullptr, printing each node.
 *
 * 3. getPrevNode(head, i):
 *      Traverses to the i-th node (0-based).
 *      Used to locate insertion point.
 *
 * 4. Insert at Index:
 *      - To insert at index=0 → use insertAtHead.
 *      - For index > 0:
 *          * Find node at position (index-1).
 *          * New node's next = prev->next.
 *          * prev->next = newNode.
 *
 * Example:
 *   List: 10 -> 20 -> 30 -> 40 -> NULL
 *   insertAtIndex(head, 80, 2)
 *   Step 1: prev = node at index 1 (value=20).
 *   Step 2: new node (80) points to prev->next (30).
 *   Step 3: prev->next = new node.
 *   Result: 10 -> 20 -> 80 -> 30 -> 40 -> NULL
 *
 */
