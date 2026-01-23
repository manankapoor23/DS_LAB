#include <iostream>

using namespace std;

void swap(int &x , int &y){
    int temp = x;
    x=y;
    y=temp;
}

void selection_sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int min = i;
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j ;
            }
        }
        if (min!=i){
            swap(arr[min],arr[i]);
        }
    }
}

int main(){
    int arr[6] = {34,23,7,64,99,12};
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort(arr,6);
    for(int i =0;i<6;i++){
        cout<<arr[i]<<" ";
    }

}