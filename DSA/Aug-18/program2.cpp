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

void printLinkedList(ListNode* head) {
    ListNode* temp = head; 
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


//check if cycle is present
bool hasCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast !=NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

//remove the loop cycle
void removeCycle(ListNode* head){
  
    ListNode* slow = head;
    ListNode* fast = head;

    while(true){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast ){
            break;
        }
    }
    slow = head;

    while(fast -> next != slow -> next){
        slow = slow->next;
        fast  = fast -> next;
    }

    fast ->next = NULL;
}


int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next->next = head->next->next;

    
    // remove cycle and print
    removeCycle(head);
    
    // detect cycle in LL (infinte loop)
    if(hasCycle(head)){
        cout << "cycle found" << endl;
    }else{
        cout << "cycle not found" << endl;
    }
    return 0;
}