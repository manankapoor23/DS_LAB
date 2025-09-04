#include <iostream>
#include <stack>

using namespace std ;

void sortedinsert(stack<int>& stac,int num){
    if(stac.empty() || num>stac.top()){ 
        stac.push(num);
        return ;
    }
    int x = stac.top();
    stac.pop();

    sortedinsert(stac,num);
    stac.push(x);
}

void sort(stack<int>& s){
    // if empty then return 
    if(s.empty()){
        return ;
    }
    // number nikalke rakhlo top wala
    int num = s.top();
    s.pop();

    sort(s);
    sortedinsert(s,num);
}

int main(){
    stack<int> st;
    st.push(2);
    st.push(1);
    st.push(10);
    st.push(3);
    st.push(55);
    st.push(4);
    sort(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0 ;
}
