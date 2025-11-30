#include <iostream>
#include <stack>
using namespace std;

stack<int> SortStack(stack<int> &st){
    stack<int> temp;
    int n = st.size();
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        while(!temp.empty() &&temp.top()>curr){ // ab current elem agar chota hai to 
            st.push(temp.top()); // stack mai top push karke chote wali ki jageh banao in temp 
            temp.pop(); // jageh banao
        }
        temp.push(curr); // phela element humesha temp mai daldo  , jageh banake push kardia

    }
    return temp;

}


int main(){
    stack<int> st;
    st.push(10);
    st.push(3);
    st.push(5);
    st.push(80);
    st.push(1);
    stack<int> sorted = SortStack(st);
        while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    return 0;


}