#include<iostream>
using namespace std;

int sum(int n){
    if(n==1){
        return 1 ;
    }
    int summer = 0 ;
    summer = n+ sum(n-1);
    return summer;


}

int main(){
    cout<<sum(5);
}