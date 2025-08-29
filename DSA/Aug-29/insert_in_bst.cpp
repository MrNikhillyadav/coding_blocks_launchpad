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

void printInOrder(TreeNode* root){
    //base case
    if(root == NULL) return;

    //recursive case
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}


TreeNode* insert(TreeNode* root, int key){
    //base case
    if(root == NULL){
        return new TreeNode(key);
    }

    //recursive case
    if(key < root->data){
        root ->left = insert(root->left, key);
    }else{
        root -> right = insert(root->right,key);
    }

    return root;
}


int main(){

    TreeNode* root = NULL;

    root = insert(root,10);

    root = insert(root,5);
    root = insert(root,3);
    root = insert(root,7);
    
    root = insert(root,15);
    root = insert(root,13);
    root = insert(root,17);

    //sorted elements
    printInOrder(root);

    return 0;
}