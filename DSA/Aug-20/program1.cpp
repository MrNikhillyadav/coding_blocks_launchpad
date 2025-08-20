#include <iostream>
using namespace std;

//class definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    //constructor
    TreeNode(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL; 
    }
};

// given tree
TreeNode* buildSampleTree() {
    //    1
    //   / \
    //  2   3
    // / \   \
    //4  5    6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    return root;
}

// root -> left -right
void preOrder(TreeNode* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}



int main(){
    TreeNode* root = buildSampleTree();
    preOrder(root);

    return 0;
}