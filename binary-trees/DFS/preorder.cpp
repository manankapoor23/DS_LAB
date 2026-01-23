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
vector<int> store ;

void preorder(Tree* t,vector<int> &store){
    if(t==NULL){
        return;
    }
    store.push_back(t->data);
    preorder(t->left,store);
    preorder(t->right,store);
}

int main(){
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(15);
     vector<int> store;
    preorder(root, store);

    for(int x : store) cout << x << " ";

}

