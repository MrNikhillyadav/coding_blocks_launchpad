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

ListNode* getPrevNode(ListNode* head, int i){
    ListNode* temp = head;
    int k = 0;
    while( k < i){
        temp = temp -> next;
        k++;
    }

    return temp;
}


int main(){
    ListNode* head = nullptr;

    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printLinkedList(head);

    // delete head
    

    // delete at tail


    // searchRecusive


    //reverseLinkedlist


    // kth node from the end


    return 0;
}