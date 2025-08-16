#include <iostream>
using namespace std;

class ListNode {
    public :
        int data;
        ListNode* next;

        ListNode(int data){
            this->data = data;
            this -> next = NULL;
        }
};

void insertAtHead(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

void printLinkedList(ListNode* head) {
    ListNode* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool searchIterative(ListNode* head, int target){
    ListNode* temp = head;

    while(temp != NULL){
        if( temp->data == target){
            return true;
        }

        temp = temp -> next;
    }

    return false;
}

bool searchRecursive(ListNode* head, int target){
    //base case
    if(head == NULL){
        return false;
    }

    if( head -> data == target){
        return true;
    }

    // recursive case
    return searchRecursive(head ->next, target);
}

ListNode* reverseRecursive(ListNode* head){
    //base case
    if(head == NULL){
        return head;
    }

    if( head-> next == NULL){
        return head;
    }

    // recursive case
    ListNode* revHead =  reverseRecursive(head -> next);
    head->next -> next = head;
    head -> next = NULL;

    return revHead;
}

ListNode* kthNodeFromEnd(ListNode* head, int k){
    ListNode* slow = head;
    ListNode* fast = head;

    int i = 1;
    while( i <= k){
        fast = fast -> next;
        i++;
    }

    while( fast != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

ListNode* middleOfList(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while( fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

ListNode* deleteMiddleOfList(ListNode* head){
    if( head == NULL){
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while( fast != NULL && fast ->next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next ->next;
    }

    prev ->next = slow ->next;
    return head;
}

int main(){
    ListNode* head = nullptr;

    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);

    // search element in Linkedlist

    //iterative approach :

    // int target = 80;
    // if(searchIterative(head, target)) {
    //     cout << target << " has been found" << endl;
    // }else {
    //     cout << target << " not found" << endl;
    // }

    // recrusive approach

    // if(searchRecursive(head, target)){
    //     cout << target << " value found" << endl;
    // }else {
    //     cout << target << " not found in LL" << endl;
    // }


    //reverse linked list
    // head = reverseRecursive(head);
    // printLinkedList(head);

    // kth node from the end
    // int k = 2;
    // ListNode* kth =  kthNodeFromEnd(head,k);
    // cout << "Kth value from end: "<< kth->data  << endl;

    // find and delete the middle of LL 
    // ListNode* middle = middleOfList(head);
    // if( middle){
    //     cout << "middle of LL: " << middle->data << endl;
    // }

    // delete the middle of list
    head = deleteMiddleOfList(head);
    printLinkedList(head);


    return 0;
}