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
   
}


// inserting Node at head of linked list
void insertAtHead(ListNode*& head, int data){
  
}


// getting tail node
ListNode* getTailNode(ListNode* head){
  
}


// inserting Node at tail of linked list
void insertAtTail(ListNode* head,int data){
 
    
}


// get previous node 
ListNode* getPrevNode(ListNode* head, int i){
   
}

// inserting node at an Index i
void insertAtIndex(ListNode* head, int data, int index){
  

}


// delete the Head node
void deleteAtHead(ListNode*& head){
  
}


// delete the tail node
void deleteAtTail(ListNode* head){

    
}



int main(){
    // create a linked list : 10 -> 20 -> 30;
    ListNode* head =  new ListNode(10);
    head -> next = new ListNode(20);
    head ->next ->next =  new ListNode(30)

    printLinkedList(head)

    // insert 0 at head : 0 -> 10 -> 20 -> 30 



    // insert 40 at tail : 0 -> 10 -> 20 -> 30 -> 40



    // insert 25 at index 3 : 0 -> 10 -> 20 -> 25 -> 30 -> 40



    // delete the node at head : 10 -> 20 -> 25 -> 30 -> 40



    // delete the node at tail : 10 -> 20 -> 25 -> 30 

    return 0;
}