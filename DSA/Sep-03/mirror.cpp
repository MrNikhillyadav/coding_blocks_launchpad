#include <iostream>
#include <queue>
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

int treeHeight(TreeNode* root) {
    if (!root) return 0;

    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

void printKthLevel(TreeNode* root, int k){
    if(!root) return;
    if(k == 1) {
        cout << root -> data << " " ;
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void printAllLevels(TreeNode* root){
    int H = treeHeight(root);

    for(int i=1; i<= H; i++){
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}


void mirrorTree(TreeNode* root) {
    // base case
    if(root == NULL){
        return;
    }

    //swap subtree
    TreeNode* temp = root ->left;
    root->left = root->right;
    root->right = temp;

    // recursive case
    mirrorTree(root->left);
    mirrorTree(root->right);
    
}


int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);

    printAllLevels(root); cout << endl;

    cout << "Mirroring the tree..." << endl;
    mirrorTree(root) ;

    cout<<endl;
    
    printAllLevels(root); cout << endl;

    return 0;
}


