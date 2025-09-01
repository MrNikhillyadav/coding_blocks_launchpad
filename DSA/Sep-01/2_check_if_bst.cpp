#include <iostream>
#include <climits>
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

int findMinimum(TreeNode* root){
    if(root == NULL){
        return INT_MAX;
    }

    TreeNode* cur = root;

    while( cur->left != NULL){
        cur = cur->left;
    }

    return cur ->data;

}

int findMaximum(TreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }

    TreeNode* cur = root;
    while( cur->right != NULL){
        cur = cur->right;
    }

    return cur->data;
}

bool isBST(TreeNode* root){
    //base case
    if(root = NULL){
        return true;
    }

    //recursive case
    bool isLeftBST= isBST(root->left);
    bool isRightBST= isBST(root->right);

    bool isRootBST = root ->data > findMinimum(root->left) && root->data  < findMinimum(root->right);

    return isLeftBST && isRightBST && isLeftBST; 
}

int main(){
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
   
    if(isBST){
        cout << "true";
    }else{
        cout << "false";
    }


    return 0;
}