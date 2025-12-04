#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int a){
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main() {
    // Example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}
