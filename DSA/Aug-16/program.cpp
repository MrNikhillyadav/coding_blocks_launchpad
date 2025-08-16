/*
 * Title: C++ Singly Linked List Operations
 * Description: Implementation of basic singly linked list operations in C++,
 *              including insertion, traversal, searching (iterative + recursive),
 *              reversing (recursive), finding kth node from end, finding middle,
 *              and deleting middle node.
 * Author: Nikhil Yadav
 * Date: August 16, 2025
 */

#include <iostream>
using namespace std;

// ===== NODE DEFINITION =====
class ListNode {
    public:
        int data;          // Stores the node's integer value
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

// ===== TRAVERSAL =====

void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ===== SEARCHING (Iterative) =====

bool searchIterative(ListNode* head, int target) {
    ListNode* temp = head;

    while (temp != nullptr) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// ===== SEARCHING (Recursive) =====

bool searchRecursive(ListNode* head, int target) {
    // Base case: empty list
    if (head == nullptr) return false;

    if (head->data == target) return true;

    // Recursive case: move to next node
    return searchRecursive(head->next, target);
}

// ===== REVERSING A LINKED LIST =====

ListNode* reverseRecursive(ListNode* head) {
    // Base case: empty list OR single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive case
    ListNode* revHead = reverseRecursive(head->next);

    // Reverse the current pointer
    head->next->next = head;
    head->next = nullptr;

    return revHead;
}

// ===== KTH NODE FROM END =====
/**
 * Finds the kth node from the end of the linked list.
 * Uses two-pointer technique (fast and slow).
 */
ListNode* kthNodeFromEnd(ListNode* head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return nullptr; // Handle case where k > length of list
        fast = fast->next;
    }

    // Move both pointers until fast reaches end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// ===== MIDDLE OF LINKED LIST =====
/**
 * Finds the middle node of the linked list.
 * Uses fast and slow pointer technique.
 */
ListNode* middleOfList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ===== DELETE MIDDLE NODE =====
/**
 * Deletes the middle node of the linked list.
 * Returns new head (unchanged unless list has 1 node).
 */
ListNode* deleteMiddleOfList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // Empty list or single node list
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Remove middle node
    if (prev != nullptr) {
        prev->next = slow->next;
    }
    return head;
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

    // === SEARCHING ===
    int target = 80;
    // Iterative
    cout << "\nSearching " << target << " (Iterative): ";
    cout << (searchIterative(head, target) ? "Found" : "Not Found") << endl;

    // Recursive
    cout << "Searching " << target << " (Recursive): ";
    cout << (searchRecursive(head, target) ? "Found" : "Not Found") << endl;

    // === REVERSAL ===
    cout << "\nReversed Linked List:" << endl;
    head = reverseRecursive(head);
    printLinkedList(head);

    // === KTH NODE FROM END ===
    int k = 2;
    ListNode* kth = kthNodeFromEnd(head, k);
    if (kth) {
        cout << "\nKth node (" << k << ") from end: " << kth->data << endl;
    } else {
        cout << "List has fewer than " << k << " nodes!" << endl;
    }

    // === MIDDLE NODE ===
    ListNode* middle = middleOfList(head);
    if (middle) {
        cout << "Middle of Linked List: " << middle->data << endl;
    }

    // === DELETE MIDDLE ===
    cout << "\nList after deleting middle node:" << endl;
    head = deleteMiddleOfList(head);
    printLinkedList(head);

    return 0;
}

/*
 * =====
 *        EXPLANATION
 * =====
 * 1. Insertion at Head:
 *      new node points to current head, then update head to new node.
 *
 * 2. Traversal:
 *      loop until nullptr, print each node.
 *
 * 3. Searching:
 *      Iterative: linear scan until found.
 *      Recursive: check node, else recurse to next.
 *
 * 4. Reverse (Recursive):
 *      Reverse remainder of list, then set head->next->next = head, cut head->next.
 *
 * 5. Kth Node from End:
 *      Move fast pointer k steps, then move slow and fast until fast=nullptr.
 *
 * 6. Middle of List:
 *      Fast moves 2 steps, slow moves 1 step. When fast reaches end, slow is middle.
 *
 * 7. Delete Middle:
 *      Track prev of slow while finding middle, then bypass middle node.
 *
 */
