#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char,int> mp;
int main(){
    string s;
    cin>>s;

    for(char c:s){
        mp[c]++;
    }
    if(mp.size()%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }

    return 0;
    
}