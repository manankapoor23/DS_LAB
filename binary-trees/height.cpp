#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int a){
        this->data=a;
        this->right=NULL;
        this->left=NULL;
    }
};

int heightTree(Node* t){
    if(t==NULL){
        return 0;
    }
    return (max(heightTree(t->left),heightTree(t->right))+1);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"height : "<<heightTree(root);

}