#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
    }
        stack<int> input ;
        stack<int> output ;
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        cout<<"the element pushed is :"<<x<<endl;
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        
    }
    
    int pop() {
        if(input.empty()){
            cout<<"stack is empty";
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        if(input.empty()){
            cout<<"stack is empty";
            exit(0);
        }
        return input.top();
        
    }
    
    bool empty() {
        return input.empty();
        
    }
};


int main(){
    MyQueue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.peek() << endl;
    


}
