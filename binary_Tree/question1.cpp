#include <iostream>
#include <queue>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    public:
    Tree(int a){
        this->data=a;
        this->left=NULL;
        this->right=NULL;
    }
};

class ListNode{
    public:
    int data;
    ListNode* next;
    public:
    ListNode(int x){
        this->data=x;
        this->next=NULL;
    }
};

// this function converts the given LL to a tree using queues
Tree* ConvertLLtoTree(ListNode* head){
    if(head==NULL){
        return NULL;
    }
    Tree* root = new Tree(head->data);
    head=head->next;
    queue<Tree*> q;
    q.push(root);
    
    while(head!=NULL){
        Tree* parent = q.front();
        q.pop();

        // left child 
        Tree* leftChild = new Tree(head->data);
        parent->left=leftChild;
        q.push(leftChild);
        head=head->next;

        // right child 
        if(head!=NULL){
                Tree* rightChild = new Tree(head->data);
                parent->right=rightChild;
                q.push(rightChild);
                head=head->next;
        }
        
    }
    return root;

}

void preOrder(Tree* node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void levelOrder(Tree* node){
    if(node==NULL){
        return;
    }
    queue<Tree*> q;
    q.push(node);
    while(!q.empty()){
        Tree* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int heightTree(Tree* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(heightTree(root->left),heightTree(root->right));
}


int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next->next = new ListNode(70);

    Tree* main = ConvertLLtoTree(head);
    cout<<"Level order traversal is : ";
    levelOrder(main);
    cout<<endl;
    cout<<"Height of this tree is: "<<heightTree(main);
    cout<<endl;
    preOrder(main);

    return 0 ;

}