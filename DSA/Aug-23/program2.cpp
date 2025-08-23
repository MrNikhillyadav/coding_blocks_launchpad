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

//building input based tree
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
void printTree(TreeNode* root){
  

}


int main(){
    TreeNode* root = buildTree();

    // e.g. printTree input : 3 4 -1 6 -1 -1 5 1 -1 -1 -1


    cout << endl;

    // height | Input = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 -1 


    // print Kth level e.g. k=3


    // print All levels


    //total no. of nodes


    //Diameter of tree

    
    return 0;
}