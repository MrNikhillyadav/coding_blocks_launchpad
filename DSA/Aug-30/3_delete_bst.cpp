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
    
    if(root == NULL) 
    return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight,rHeight) + 1;
}

void printInOrder(TreeNode* root){
    //base case
    if(root == NULL) return;

    //recursive case
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
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


//delete 
TreeNode* deleteFromBST(TreeNode* root, int key){
    //base case
    if(root == NULL){
        return NULL;
    }

    // recursive case
    if( key < root->data){
       root->left = deleteFromBST(root->left, key);
    } else if( key > root->data){
        root->right = deleteFromBST(root->right, key);
    }else{
       
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }else if (root -> left == NULL and root->right != NULL){
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        }else if (root ->left != NULL and root->right == NULL){
             TreeNode* temp = root->left;
            delete root;
            root = temp;
        }else {
            TreeNode* leftMaxNode =  findMaximum(root->left);
            swap( leftMaxNode->data , root->data);
            root->left = deleteFromBST(root->left, key);
        }
    }

    return root;
}

int main(){

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);

    printInOrder(root);
    cout << endl;

    printLevelOrder(root);
    cout << endl;
    
    int key = 10;
    root = deleteFromBST(root,key);
    cout << endl;


    printInOrder(root);
    cout << endl;

    printLevelOrder(root);
    cout << endl;

    return 0;
}