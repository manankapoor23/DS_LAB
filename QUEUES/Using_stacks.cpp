#include <iostream>
#include <stack>
using namespace std;

class Queue{
    public:
    int data;
    stack<int> s1;
    stack<int> s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        int x =-1;
        if(s2.empty()){
            if(s1.empty()){
                cout<<"queue empty";
                return x;
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

        }
        int m = s2.top();
        s2.pop();
        return m;
    }
        int peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check if empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peek();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(40);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
}
