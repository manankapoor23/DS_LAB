#include <iostream>
using namespace std;
class BinaryNode{
    public:
    int data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int val){
        data=val;
        left=right=NULL;
    }
};

void buildTree(BinaryNode* &root){
    root = new BinaryNode(1);
    root->left = new BinaryNode(2);
    root->right = new BinaryNode(3);
    root->left->left = new BinaryNode(4);
    root->left->right = new BinaryNode(5);
    root->right->left = new BinaryNode(6);
    root->right->right = new BinaryNode(7);
}



void inorder_leaf_node(BinaryNode* &root , int &count){
    if(root==NULL){
        return;
    }
    inorder_leaf_node(root->left , count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder_leaf_node(root->right,count);

}

int main(){
    BinaryNode* root = nullptr;
    buildTree(root);
    int count = 0;
    inorder_leaf_node(root, count);
    cout << "Number of leaf nodes: " << count << endl;
}