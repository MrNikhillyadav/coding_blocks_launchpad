/*
 * Title: Linked List Implementation Demo
 * Description: Singly linked list using ListNode class, including printLinkedList functions.
 * Author: Nikhil Yadav 
 * Date: August 8th, 2025
 */


#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor
    ListNode(int val) : data(val), next(nullptr) {}
};


// Print all nodes in the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    cout << "Linked List: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    ListNode* head = nullptr; // start with an empty list

    // Insert nodes at head
    ListNode* head = new ListNode(10);
    head -> next = new ListNode(20);
    head -> next ->next = new ListNode(30);

    // Print current list
    printLinkedList(head);

 

    return 0;
}


/*
 * =========================
 *        EXPLANATION
 * =========================
 * 
 * - ListNode class: each node holds integer data and a pointer to next node
 * - printLinkedList: displays all nodes from head to tail
 * - main(): shows both insertions and prints list after each major update
 */
