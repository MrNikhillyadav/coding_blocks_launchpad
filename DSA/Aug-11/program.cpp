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

void insertAtIndex(ListNode* head, int data, int index){

    if(head == NULL){
        return;
    }

    ListNode* n = new ListNode(data);
    ListNode* prev   = getPrevNode(head, index - 1);

    n -> next = prev -> next;
    prev -> next = n;

}

int main(){
    ListNode* head = nullptr;

    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printLinkedList(head);

    // insert a index
    insertAtIndex(head,80, 2);
    printLinkedList(head);


    // delete head
    


    // delete at tail



    // searchRecusive



    //reverseLinkedlist


    return 0;
}