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

// left -> root -> right
void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inOrder(root-> left);
    cout << root->data << " ";
    inOrder(root -> right);

}

// left -> right -> root
void postOrder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inOrder(root-> left);
    inOrder(root -> right);
    cout << root->data << " ";

}

int main(){
    TreeNode* root = buildSampleTree();

    cout << "preorder :" ;
    preOrder(root);

    cout << "inorder :" ;
    inOrder(root);

    cout << "postOrder :";
    postOrder(root);

    return 0;
}