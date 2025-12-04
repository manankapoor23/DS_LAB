#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int> &arr,int low,int high){
    int pivot = arr[high]; // last element pivot
    int i = low-1; // index of smaller element

    for(int j = low; j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}


void quicksort(vector<int> &arr,int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    vector<int> arr = {3,57,4,21,68,5,3,7,843,56,8,433,1,100,4,3};
    int n = arr.size();
    quicksort(arr,0,n-1);
    cout<<"sorted array : ";
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
