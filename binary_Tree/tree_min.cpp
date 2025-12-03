#include <iostream>
#include <vector>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    public:
    Tree(int a ){
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }


};
Tree* insertBST(Tree* root, int val) {
    if (root == NULL) {
        return new Tree(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

Tree* maxiTree(Tree* node){
    while(node->right!=NULL){
        node=node->right;
    }
    return node;
}
Tree* miniTree(Tree* node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}


int main(){
    Tree* root = NULL;
    root = insertBST(root, 12);
    insertBST(root, 8);
    insertBST(root, 16);
    insertBST(root, 4);
    insertBST(root, 10);
    insertBST(root, 14);
    insertBST(root, 20);

    Tree* maxxer = maxiTree(root);
    Tree* minner = miniTree(root);
    cout<<"max value in tree is "<<maxxer->data<<endl;
    cout<<"min value in tree is "<<minner->data<<endl;

}