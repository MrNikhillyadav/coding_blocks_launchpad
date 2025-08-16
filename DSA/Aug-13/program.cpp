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

void deleteAtHead(ListNode*& head){

    if(head == NULL){
        return;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;

}

void deleteAtTail(ListNode* head){
    if(head == NULL){
        return ;
    }

    if(head -> next == NULL){
        deleteAtHead(head);
    }

    ListNode* prev = NULL;
    ListNode* tail = head;

    while( tail -> next != NULL){
        prev = tail;
        tail = tail -> next;
    }

    prev -> next = NULL;
    delete tail;
}

int ComputeLengthIteratively(ListNode* head){
    int i = 0;
    ListNode* temp = head;

    while( temp != NULL){
        temp = temp -> next;
        i++;
    }

    return i;
}

int computeLengthRecursively(ListNode* head){
    // base case
    if(head == NULL){
        return 0;
    }

    //recursive case
    int A =  computeLengthRecursively(head -> next);
    return A + 1;
}

int main(){
    ListNode* head = nullptr;

    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printLinkedList(head);
   
    //length of a linkedlist
    cout << "length: " <<  ComputeLengthIteratively(head) << endl;
    cout << "length: " <<  computeLengthRecursively(head) << endl;


    // searchRecusive 


    //reverseLinkedlistRecursive


    // kth node from the end


    return 0;
}