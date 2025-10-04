// #include <iostream>

// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int val){
//         data= val;
//         next = NULL;
//     }
// };

// class LinkedList{
//     Node* head;
//     public:
//     LinkedList(){
//         head = NULL;
//     }
//     void insertAtBeg(int val){
//         Node* temp = new Node(val);
//         temp->next=head;
//         head = temp;
//     }

//     void insertAtEnd(int val){
//         Node* newNode = new Node(val);
//         if(head==NULL){
//             head = newNode;
//             return ;
//         }
//         Node* temp = head ; // make a temp pointer at head which will check for the end of the list 
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next = newNode;
//     }

//     void insertAtPos(int val , int pos){
//         Node* newNode = new Node(val);
//         if(pos==1){
//             newNode->next = head;
//             head = newNode;
//         }
//         Node *temp = head;
//         for(int i =1;i<pos-1 && temp!=NULL;i++){temp = temp->next;}
//             if(temp==NULL){
//                 cout<<"out of range"<<endl;
//                 return;
//             }
//             newNode->next = temp->next;
//             temp->next= newNode;
//         }

//     

//     void display(){
//         Node* temp = head;
//         while(temp!=NULL){
//             cout<<temp->data<<" -> ";temp=temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }
// };

// int main(){
//     LinkedList l;
//     l.insertAtBeg(10);
//     l.insertAtEnd(20);
//     l.insertAtEnd(30);
//     l.display();


// }

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    public:
    Node(int value){
        data=value;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;

    }
    void insertBeg(int val){
        Node *newNode = new Node(val);
        newNode->next=head;
        newNode=head;
        }
    void insertEnd(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            insertBeg(val);
            return;
        }
        Node *temp = head ;
        while(temp->next!=NULL){
            temp=temp->next;
        }
            temp->next=newNode;

    }

    void insertPos(int val,int pos){
        Node * newNode = new Node(val);
        if(pos==1){
            insertBeg(val);
            return ;
        }
        Node *temp = head;
        for(int i =1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"out of bounds";
            return ;
        }
        newNode->next = temp->next;
        temp->next=newNode;

    }
};

