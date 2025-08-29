#include <iostream>
using namespace std ;
const int MAX_SIZE = 100 ;

class Stack{
    private:
    int arr[MAX_SIZE];
    int top;
    public:
    Stack(){
        top = -1;
    }
    void push(int x){
        if(top>=(MAX_SIZE-1)){
            cout<<"stack overflow"<<endl;
            return ; 
        }
        top = top+1;
        arr[top]=x;
    }
    int pop(){
        if(top<0){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top<0){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return(top<0);
    }

};

int main(){
    Stack s ;
    int size ;
    int choice;
    cout<<"0. make stack with size "<<endl;
    cout<<"1. push"<<endl;
    cout<<"2. pop"<<endl;
    cout<<"3. peek"<<endl;
    cout<<"4. isEmpty"<<endl;
    cout<<"Enter operation on stack: ";
    cin>>choice;
    int m ;
    switch (choice)
    {
    case 0:
        cout<<"enter the size of stack you want : ";
        cin>>size;
        int a ;
        for(int i =0;i<size;i++){
            cout<<"enter "<<i<<"th"<<" : ";
            cin>>a;
            s.push(a);
    }
}}
