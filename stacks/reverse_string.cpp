#include <iostream>
#include <stack>
using namespace std;

int main(){
    string word ;
    cout<<"enter string :";
    cin>>word;
    stack<char> s;
    for(int i =0;i<word.size();i++){
        s.push(word[i]);
    }
    string ans ="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<"the rev of "<< word << " string is "<<ans<<endl;
    return  0 ;
}

