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

int height(TreeNode* root){
    
    //base
    if(root == NULL) 
    return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight,rHeight) + 1;
}

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

void printLevelOrder(TreeNode* root){
    if(root == NULL) return;

    int H = height(root);

    for(int i = 1; i <= H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

void printInorder(TreeNode* root){
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}



TreeNode* buildBalancedBST(int A[],int start, int end){
   
}

int main(){
    int A[] = {3,5,7,10,13,15,17};
    int n = sizeof(A)/sizeof(int);

    TreeNode* root = buildBalancedBST(A,0,n-1);

    printLevelOrder(root);
    cout << endl;

    printInorder(root);
    return 0;
}