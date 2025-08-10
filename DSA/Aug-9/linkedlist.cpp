/*
 * Title: Linked List Implementation Demo
 * Description: Singly linked list using ListNode class, including
 *              insertAtHead, insertAtTail, and printLinkedList functions.
 * Author: Nikhil Yadav 
 * Date: August 9th, 2025
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

// Insert a new node at the head of the list
void insertAtHead(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert a new node at the tail (end) of the list
void insertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

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
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1); // List: 1 -> 2 -> 3

    // Print current list
    printLinkedList(head);

    // Insert nodes at tail
    insertAtTail(head, 4);
    insertAtTail(head, 5); // List: 1 -> 2 -> 3 -> 4 -> 5

    // Print again
    printLinkedList(head);

    // Free the allocated memory (optional, for clean code)
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
 * =========================
 *        EXPLANATION
 * =========================
 * - ListNode class: each node holds integer data and a pointer to next node
 * - insertAtHead: add new node at the front (constant time)
 * - insertAtTail: add new node at end (linear time)
 * - printLinkedList: displays all nodes from head to tail
 * - main(): shows both insertions and prints list after each major update
 */
