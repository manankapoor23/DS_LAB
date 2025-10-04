#include <iostream>
using namespace std ;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;

    public:
    Queue(){
        front=rear=nullptr;
    }
    void enqueue(int x){
        Node* newNode = new Node(x);
        if(isEmpty()){
            front=rear=newNode;
        }
        rear->next = newNode;
        rear=newNode;
    }
    bool isEmpty(){
        return front==NULL;
    }

    void dequeu(){
        if(isEmpty()){
            cout<<"the queue is empty"<<endl;
        }
        Node* temp = front;
        front = front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
    }
    void display(){
        if(isEmpty()){
            cout<<"the queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    Queue q ;
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(50);
    q.display();

    

    
}