#include <iostream>
using namespace std;

void print(int i , int n){
    if(i>n){
        return;
    }
    cout<<i<<endl; // i++ for odd , and ++i for even , i for normal
    
    print(i+1,n);
    
}

int main(){
    print(1,20);
}

