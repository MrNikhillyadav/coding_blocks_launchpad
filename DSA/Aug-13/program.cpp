/*
 * Title: C++ Singly Linked List - Basic Deletion and Length Operations
 * Description: Implementation of linked list operations in C++, including:
 *              - Insertion at head
 *              - Printing/traversal
 *              - Deletion at head
 *              - Deletion at tail
 *              - Computing length (iteratively & recursively)
 * Author: Nikhil Yadav
 * Date: August 13, 2025
 */

#include <iostream>
using namespace std;

// ===== NODE DEFINITION =====
class ListNode {
    public:
        int data;          // Stores the node value
        ListNode* next;    // Pointer to the next node

        // Constructor
        ListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

// ===== INSERTION =====

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

// ===== DELETE AT HEAD =====

void deleteAtHead(ListNode*& head) {
    if (head == nullptr) {
        return;
    }

    ListNode* temp = head;
    head = head->next;   // Move head to the second node
    delete temp;         // Free removed node
}

// ===== DELETE AT TAIL =====

void deleteAtTail(ListNode*& head) {
    if (head == nullptr) {
        return; // Empty list
    }

    if (head->next == nullptr) {
        // Only one element, delete head
        deleteAtHead(head);
        return;
    }

    ListNode* prev = nullptr;
    ListNode* tail = head;

    // Traverse to the last node
    while (tail->next != nullptr) {
        prev = tail;
        tail = tail->next;
    }

    prev->next = nullptr;  // Unlink last node
    delete tail;           // Delete last node
}

// ===== LENGTH (Iterative) =====

int computeLengthIteratively(ListNode* head) {
    int length = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
        temp = temp->next;
        length++;
    }
    return length;
}

// ===== LENGTH (Recursive) =====

int computeLengthRecursively(ListNode* head) {
    // Base case: end of list
    if (head == nullptr) {
        return 0;
    }

    // Recursive case: 1 + length of remaining list
    return 1 + computeLengthRecursively(head->next);
}

// ===== MAIN DRIVER =====
int main() {
    ListNode* head = nullptr;

    // Insert elements: 10 -> 20 -> 30 -> 40 -> 50
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    cout << "Original Linked List:" << endl;
    printLinkedList(head);

    // === LENGTH ===
    cout << "\nLength (Iterative): " << computeLengthIteratively(head) << endl;
    cout << "Length (Recursive): "  << computeLengthRecursively(head) << endl;

    // === DELETION ===
    cout << "\nDeleting at Head:" << endl;
    deleteAtHead(head);
    printLinkedList(head);

    cout << "\nDeleting at Tail:" << endl;
    deleteAtTail(head);
    printLinkedList(head);

    return 0;
}

/*
 * =====
 *        EXPLANATION
 * =====
 * 1. Insertion at Head:
 *      - New node points to current head.
 *      - Update head = newNode.
 *
 * 2. Traversal:
 *      - Use temp pointer, move until nullptr, and print data.
 *
 * 3. Delete at Head:
 *      - Save current head in temp.
 *      - Move head to head->next.
 *      - Delete temp node.
 *
 * 4. Delete at Tail:
 *      - If empty list: do nothing.
 *      - If single node: just delete head.
 *      - Else traverse to last node, track prev,
 *        then unlink last node and delete it.
 *
 * 5. Length:
 *      Iterative: Traverse and count using loop.
 *      Recursive: Base (nullptr=0), else 1 + recurse(next).
 */
