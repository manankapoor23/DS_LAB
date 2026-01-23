#include<iostream>
using namespace std;
#include<queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int a ){
        data=a;
        left=NULL;
        right = NULL;
    }
};

void travLeft(Node* root , vector<int> &ans){
    // no root case
    if(root == NULL){
        return;
    }
    // leaf node case
    if(root->left ==NULL && root->right==NULL){
        return ;
    }
    // phele store karwao
    ans.push_back(root->data);
    if(root->left){
        travLeft(root->left,ans);
    }
    else{
        travLeft(root->right,ans);
    }
}

void travLeaf(Node* root , vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    travLeaf(root->left,ans);
    travLeaf(root->right,ans);
}

void travRight(Node* root , vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right){
        travRight(root->right,ans);
    }
    else{
        travRight(root->left,ans);
    }
    ans.push_back(root->data);

}
vector<int> boundaryTraversal(Node* root){
    vector<int> ans = {};
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);


    // left side nodes , top to bottom , dont incl leaf nodes 
    travLeft(root->left,ans);

    // leaf nodes
    travLeaf(root->left,ans);
    travLeaf(root->right,ans);

    // right side nodes , reverse , dont incl leaf nodes  and dont incl the root , as it will be taken in the left side one.
    travRight(root->right,ans);



    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = boundaryTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    // IT SHUD PRINT 1 2 4 5 6 7 10

}
