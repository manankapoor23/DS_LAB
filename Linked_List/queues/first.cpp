#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    queue<char> q ;
    string str ;
    cout<<"Enter the string : ";
    cin>>str;

    for(char ch : str){
        q.push(ch);
    }

    while(!q.empty()){
        char x = q.front();
        q.pop();
        int count=1;
        while(!q.empty()&&q.front()==x){
            q.pop();
            count++;
        }

        if(count%2!=0){
            cout<<"ans is : "<<x;
            break;
        }

    }
}