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

TreeNode* findMinimum(TreeNode* root){
  
}

TreeNode* findMaximum(TreeNode* root){
   
}

int main(){

   TreeNode* root = new TreeNode(10);

   root->left = new TreeNode(5);
   root->left->left = new TreeNode(3);
   root->left->right = new TreeNode(7);

   root->right = new TreeNode(15);
   root->right->left = new TreeNode(13);
   root->right->right = new TreeNode(17);

   TreeNode* minNode = findMinimum(root);
   TreeNode* maxNode = findMaximum(root);

    cout << "min: " << minNode->data << endl;
    cout << "max: " << maxNode->data << endl;

    return 0;
}