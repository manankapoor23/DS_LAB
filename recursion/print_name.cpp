#include <iostream>
#include <string>
using namespace std;

void name(int i , int n ){
    if(i>n){
        return;
    }
    cout<<"Manan"<<endl;
    name(i+1,n);

}
int main(){
    int i  = 1 ;
    int N = 3;
    name(i,N);
}