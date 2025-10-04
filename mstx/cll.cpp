#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        next = NULL;
        data=val;
    }
};

class CLL{
    public:
    Node* head;
    CLL(){
        head = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            head->next=head;
            return;
        }
        Node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->next=head;
    }
    void display(){
    if(head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while(temp != head);
    cout << "(head)\n";
}
    void deleteEnd(){
        if(head==NULL){
            cout<<"empty";
            return;
        }
        if(head->next==head){
            delete head;
            head =NULL;
            return;
        }
        Node* fast = head;
        Node* slow = fast;
        while(fast->next!=head){
            slow = fast;
            fast=fast->next;
        }
        Node* temp = fast;
        slow->next = head;
        delete temp;
    }

};

int main(){
    CLL l ;
    l.head=0;
    l.display();
    l.deleteEnd();
    l.display();
}
