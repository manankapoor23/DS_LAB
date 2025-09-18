#include <iostream>

using namespace std;
#include <stack>
#include <queue>

int main(){
    stack<int> s ;
    queue<int> q ; 
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    int size = q.size();

    for(int i =0;i<size/2;i++){
        s.push(q.front()); // adds 4 then 7 then 11
        q.pop(); // removes 4 then 7 then 11 
    }
    // now our stack has 11 7 4 
    
    // now add em to back of queue

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    // now our queue has 20 5 9 11 7 4 

    for(int i=0;i<size/2;i++){
        q.push(q.front());
        q.pop();
        // makes our queue 11 7 4 20 5 9
    }
    
    for(int i =0;i<size/2;i++){
        s.push(q.front());
        q.pop();
    }

    // stack has 4 7 11 
    // now alternatevly we want from stack then queue the stack then queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }




}