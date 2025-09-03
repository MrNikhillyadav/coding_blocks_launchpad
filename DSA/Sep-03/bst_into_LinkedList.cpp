#include <iostream>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL; 
        }
};

void printLinkedList(TreeNode* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> right;
    }
    cout << endl;
}


class Pair {
    public :
     TreeNode* head;
     TreeNode* tail;
};

Pair convert (TreeNode* root) {
   Pair p;

   // base case
   if(root == NULL){
        p.head = NULL;
        p.tail = NULL;
        return p;
   }

   // recursive case
   Pair left = convert(root->left);

    if(left.head == NULL){
        p.head = root;
    }else{
        left.tail->right = root;
        p.head = left.head;
    }

   Pair right = convert(root->right);

   if(right.head == NULL){
        p.tail = root;
   }else{
       root->right = right.head;
       p.tail = right.tail;
   }

    return p;
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
   
    Pair p = convert(root);

    printLinkedList(p.head);

    return 0;
}