// Given an array of integers: [1, 2, 1, 3, 2] and we are given some queries: [1, 3, 4, 2, 10].
#include <iostream>
using namespace std;
int occurence(int a , int arr[]){
    int n = sizeof(arr)/sizeof(int);
    int count = 0 ;
    for(int i =0;i<n;i++){
        if(arr[i]==a){
            count++;
        }

    }
    return count;

}

int main(){
   int arr[5] = {1,3,1,2,10};
   cout<<"1 occurs"<< occurence(1,arr)<<" times ";
}