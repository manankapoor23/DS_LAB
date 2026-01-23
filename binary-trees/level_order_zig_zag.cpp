#include <iostream>
using namespace std;

#include <queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int a ){
        data =a;
        left=right=NULL;
    }
};
vector<int> zigZagTraversal(Node* root){
    bool LTR = true;
    vector<int> res ={};
    if(root==NULL){
        return res;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        // level process
        for(int i =0;i<size;i++){
            Node* frontNode = q.front(); // rn frontNode is 1
            q.pop(); // q is empty 
            int index = LTR ? i : size - i - 1;
            ans[index] = frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        for(auto i:ans){
            res.push_back(i);
        }
        LTR=!LTR;
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigZagTraversal(root);
    for (int x : ans) cout << x << " ";

    return 0;
}
