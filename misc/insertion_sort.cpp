#include <iostream>
using namespace std;

void insertion(int arr[],int n ){
    for(int i =1;i<n;i++){
        int temp = arr[i];
        int j =i;
        while(j>0&&arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

int main(){
    int arr[6]={23,32,44,12,6,1};
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertion(arr,6);
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }

}


void insertion(int arr[],int n){
    for(int i =1;i<n;i++){
        int temp = arr[i];
        int j =i;
        while(j>0&&arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]==temp;

    }
}


for(int i =1;i<n;i++){
    int temp = arr[i];
    int j =i;
    while(j>0&&arr[j-1]>temp){
        arr[j]=arr[j-1];
        j--
    }
    arr[j]==temp;
}

for(int i =1;i<n;i++){
    int temp = arr[i];
    int j =i;
    while(j>0&&arr[j-1]>temp){
        arr[j]=arr[j-1];
        j--;
    }
    arr[j]==temp;
}