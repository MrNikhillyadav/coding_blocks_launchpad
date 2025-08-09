#include <iostream>
using namespace std;

class ListNode {
    public :

        int data;
        ListNode* next;

        ListNode( int data){
            this->data = data;
            this-> next = NULL;
        }
};


// printing the whole linked list
void printLinkedList(ListNode* head){
   ListNode* temp = head;

   while( temp != NULL ){
        cout << temp -> data << " "; 
        temp = temp -> next;
   }
   cout << " "<< endl;
}

void insertAtHead( ListNode*& head, int data){
    ListNode* n  = new ListNode(data);
    n -> next = head;
    head = n;
}

ListNode* getTailNode( ListNode* head){
    ListNode* temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    return temp;

}

void insertAtTail(ListNode* head, int data){
    if(head == NULL){
        return;
    }
    
   ListNode* n = new ListNode(data);

   ListNode* tail = getTailNode(head);
   tail -> next = n;

}

int main(){
    // create a linked list : 10 -> 20 -> 30;
        ListNode* head = new ListNode(10);
        head -> next =  new ListNode(20);
        head -> next -> next = new ListNode(30);
        printLinkedList(head);

    // insert 0 at head : 0 -> 10 -> 20 -> 30 
        insertAtHead(head,0);
        printLinkedList(head);


    // insert 40 at tail : 0 -> 10 -> 20 -> 30 -> 40
        insertAtTail(head,40);
        printLinkedList(head);


    // insert 25 at index 3 : 0 -> 10 -> 20 -> 25 -> 30 -> 40



    // delete the node at head : 10 -> 20 -> 25 -> 30 -> 40



    // delete the node at tail : 10 -> 20 -> 25 -> 30 

    return 0;
}