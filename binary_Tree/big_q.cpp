#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class LL{
    public:
    int data;
    LL* next;
    public:
    LL(int a){
        this->data=a;
        this->next=NULL;
    }
};

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    public:
    Tree(int m){
        this->data=m;
        this->left=NULL;
        this->right=NULL;
    }
};

// LL* insertLL(LL* head,int x){
//     if(head==NULL){
//         return new LL(x);
//     }
//     LL* temp = head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next= new LL(x);
//     return head;
// }

// convert LL to BT
Tree* LLtoTree(LL* head){
    queue<Tree*> q;
    if(head==NULL){
        return NULL;
    }
    LL* temp = head;
    Tree* newNode = new Tree(temp->data);
    q.push(newNode);
    temp=temp->next;
    while(temp!=NULL){
        Tree* parent = q.front();
        q.pop();

        Tree* leftChild = new Tree(temp->data);
        parent->left=leftChild;
        q.push(leftChild);
        temp=temp->next;
        if(temp==NULL){
            break;
        }
        // right subtree
        Tree* rightChild = new Tree(temp->data);
        parent->right=rightChild;
        q.push(rightChild);
        if(temp!=NULL){
            temp=temp->next;
        }


    }
    return newNode ;
}


bool isBST(Tree* root,long long minVal,long long maxVal){
    if(root==NULL){
        return true;
    }
    if(root->data<=minVal || root->data>=maxVal){
        return false;
    }
    return isBST(root->left,minVal,root->data)&&isBST(root->right,root->data,maxVal);
}

bool checkBST(Tree* root){
    return isBST(root, LLONG_MIN, LLONG_MAX);
}

// inorder traversal of bst 
void inorder(Tree* node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){
    LL* head = NULL;
    int  x;
    // cout << "Enter number of LL nodes: ";
    // cin >> n;

    // cout << "Enter elements: ";
    // for(int i = 0; i < n; i++){
    //     cin >> x;
    //     head = insertLL(head, x);
    // }
    // whats wrong here ? why am i getting segmentation fault ?
    // Because head is NULL, you need to initialize head before accessing its next pointer
    head = new LL(5);
    head->next=new LL(10);
    head->next->next=new LL(30);
    head->next->next->next=new LL(2);
    head->next->next->next->next=new LL(12);
    head->next->next->next->next->next=new LL(6);
    // i am still getting segmentation fault
    // 
    


    // Convert LL to Binary Tree
    Tree* root = LLtoTree(head);

    cout << "Inorder traversal of tree: ";
    inorder(root);
    cout << "\n";

    // Check BST or not
    if(checkBST(root))
        cout << "Tree IS a Binary Search Tree.\n";
    else
        cout << "Tree is NOT a Binary Search Tree.\n";

    return 0;
}
