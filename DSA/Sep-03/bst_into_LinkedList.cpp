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