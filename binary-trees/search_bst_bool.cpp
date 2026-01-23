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
bool searchTree(Tree* node , int k){
    if(node == NULL){
        return false;
    }
    if(node->data==k){
        return true;
    }

    if(k > node->data){
        return searchTree(node->right,k);
    }
    return searchTree(node->left,k);
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

    int k;
    cin>>k;
    bool result = searchTree(root,k);
    cout<<result<<endl;
        if (result) {
        cout << "Found!"  << "\n";
    } else {
        cout << "Value not found in tree.\n";
    }

}