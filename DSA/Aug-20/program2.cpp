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

TreeNode* buildTree(){
    int d;
    cin >> d;

    if(d == -1) return NULL;

    TreeNode* root = new TreeNode(d);
    root -> left = buildTree();
    root -> right = buildTree();
    
    return root;
}

// Print tree (Preorder for demonstartion)
void printTree(TreeNode* root){
   if(root == NULL) return;

   cout << root -> data << " ";
   printTree(root->left);
   printTree(root->right);

}


int main(){
    TreeNode* root = buildTree();

    // e.g. Tree input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1

    printTree(root);

    

    return 0;
}