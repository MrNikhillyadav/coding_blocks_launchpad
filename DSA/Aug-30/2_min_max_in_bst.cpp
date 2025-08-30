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
    //TREE is empty
    if(root == NULL){
        return NULL;
    }

    TreeNode* cur = root;
    while( cur->left != NULL){
        cur = cur->left;
    }

    // we have reached left most node
    return cur;

}

TreeNode* findMaximum(TreeNode* root){
    //TREE is empty
    if(root == NULL){
        return NULL;
    }

    TreeNode* cur = root;
    while( cur->right != NULL){
        cur = cur->right;
    }

    // we have reached left most node
    return cur;
}

int main(){

   TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);

    TreeNode* minNode= findMinimum(root);
    TreeNode* maxNode= findMaximum(root);

    cout << "min: " << minNode->data << endl;
    cout << "max: " << maxNode->data << endl;



    return 0;
}