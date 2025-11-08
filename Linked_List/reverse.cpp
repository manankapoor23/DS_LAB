#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int value){
        data=value;
        next=NULL;
    }
};

class Linked{
    public:
    Node* head;
    Linked(){
        head=NULL;
    }
    void insert(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void reverse(){
        Node* prev =NULL;
        Node* curr = head;
        Node* front;
        if(curr==NULL || curr->next==NULL){
            return;
        }
        while(curr!=NULL){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        head=prev;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    Linked list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    cout<<"Original List: ";
    list.display();
    list.reverse();
    cout<<"Reversed List: ";
    list.display();
    return 0;

}