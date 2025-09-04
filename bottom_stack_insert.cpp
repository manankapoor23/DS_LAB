#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int>&orginal , int x , int size ){
    // if stack empty then push x 
    stack<int> temp ;
    while(!orginal.empty()){
        temp.push(orginal.top());
        orginal.pop();
    }
    temp.push(x);
    while(!temp.empty()){
        orginal.push(temp.top());
        temp.pop();
    }
    // if stack not empty then put top num to somwhere and then call insert again 

}
int main(){
    stack<int> org ;
    org.push(1);
    org.push(2);
    org.push(3);
    org.push(4);
    org.push(5);
    int x = 9;
    int size = org.size();
    insert(org,x,size);
    while(!org.empty()){
        cout<<org.top()<<endl;
        org.pop();
    }
    return 0 ;
}