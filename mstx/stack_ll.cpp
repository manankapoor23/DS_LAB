// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class Stack{
//     public:
//     Node* top;
//     public:
//     Stack(){
//         top = NULL;
//     }
//     void push(int x){
//         Node* newNode = new Node(x);
//         newNode->next = top;
//         top=newNode;
//     }
//     void pop(){
//         if(isEmpty()){
//             cout<<"it is empty , stack underflow "<<endl;
//         }
//         Node* temp = top;
//         top=top->next;
//         delete temp;

//     }
//     int peek(){
//         if(isEmpty()){
//             cout<<"no element , stack is empty "<<endl;
//         }
//         return top->data;

//     }
//     bool isEmpty(){
//         return (top==NULL);

//     }
//     void display(){
//     if(isEmpty()){
//         cout << "Stack is empty!" << endl;
//         return;
//     }
//     Node* curr = top;
//     cout << "Stack elements (Top to Bottom): ";
//     while(curr != NULL){
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }



// };

// int main(){
//     Stack s ;
//     int n ;
//     cout<<"Enter number of elements to be pushed : ";
//     cin>>n;
//     for(int i =0;i<n;i++){
//         int x;
//         cout<<"enter element "<<i+1<<": "<<endl;
//         cin>>x;
//         s.push(x);
//     }
//     s.display();

    
// }


#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
    public:
    Node* top;
    public:
    Stack(){
        top = NULL;
    }
    void push(int x ){
        Node* newNode = new Node(x);
        newNode->next = top;
        top=newNode;
    }
    void pop(){
        if(top==NULL){
            cout<<"empty stack"<<endl;
        }
        Node* temp = top;
        top=top->next;
        delete temp;
    }

    int peek(){
        return top->data;
    }

    bool isEmpty(){
        return (top==NULL);
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(40);
    s.push(50);
    cout<<"top element : "<<s.peek();
    
}