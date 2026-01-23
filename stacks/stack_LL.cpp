#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class Stack{
    public:
    Node* head ;

    Stack(){
        head = NULL;
    }
    void push(int x){
        Node* temp = new Node();
        temp->data=x;
        temp->next=head;
        head = temp;
    }

    int top(){
        if(head==NULL){
            cout<<"empty";
            return -1;
        }
        else{
            return head->data;
        }
    }

    void pop(){
        if(head==NULL){
            cout<<"pop not possible its empty\n";
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.top();
}