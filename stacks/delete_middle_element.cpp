#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&input,int count,int size){
    if(count==size/2){
        input.pop();
        return ;
    }
    int num = input.top();
    input.pop();

    solve(input,count+1,size);
    input.push(num);
}
void deletemid(stack<int>&stac,int N){
    int count =0 ;
    solve(stac,count,N);
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);  // stack = [1,2,3,4,5] (top is 5)

    int N = st.size();

    deletemid(st, N);

    cout << "Stack after deleting middle: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}