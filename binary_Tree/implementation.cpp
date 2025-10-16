#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int val){
        this->data=val;
        left=right=NULL;
    }

};

/* Types of traversals ( ways to visit nodes ) */
// 1. BFS (breadth first search)
//    -> level order ( top to bottom , left to right )
// 2. DFS (depth first search)
//    ->Inorder (Left → Root → Right)
//    ->Preorder (Root → Left → Right)
//    ->Postorder (Left → Right → Root)
Node* buildTree(){
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->right = new Node(5);
        root->left->left =  new Node(6);
        root->right->right = new Node(10);
    
        return root;
    }

// level order 
void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

// inorder traversal
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// preorder traversal
void preOrder(Node* root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

// postorder traversal
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    // Example usage of levelOrder can be added he
    Node* root = buildTree();
    levelOrder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}


