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

//build input based tree recursively
TreeNode* buildTree(){
    int d;
    cin >> d;

    if(d == -1) return NULL;

    TreeNode* root = new TreeNode(d);
    root -> left = buildTree();
    root -> right = buildTree();
    
    return root;
}

//preorder
void preOrder(TreeNode* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//height of a tree
int height(TreeNode* root){
    
    //base
    if(root == NULL) 
    return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight,rHeight) + 1;
}

//kth level
void printKthLevel(TreeNode* root, int k){
    //base
    if(root == NULL){
        return ;
    }

    //k==1, means we are on the right level
    if( k == 1){
        cout << root -> data << " ";
        return;
    }

    printKthLevel(root -> left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

//print all the levels:
void printAllLevels(TreeNode* root){
    if(root == NULL) return;

    int H = height(root);

    for(int i = 1; i <= H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

// count of nodes
int count(TreeNode* root){
	// base case
    if(root == NULL) return 0;

    return 1 + count(root->left) + count(root->right);
}

//diameter of Binary Tree
int diameter(TreeNode* root){
    //base 
    if(root == NULL) return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;

    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

//delete a tree
void deleteTree(TreeNode* root){
    // base
    if(root == NULL){
        return;
    }
    // recursive call
    deleteTree(root -> left);
    deleteTree(root -> right);

    delete root;
}

int main(){
    // Input = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
    TreeNode* root = buildTree();
    preOrder(root);
    cout << endl;

    // delete a tree
    deleteTree(root);
    return 0;
}