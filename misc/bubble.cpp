#include <iostream>
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x=y;
    y=temp;

}

void bubble(int arr[],int n ){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[6]={23,32,44,12,6,1};
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble(arr,6);
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }

}