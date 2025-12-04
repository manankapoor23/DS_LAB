#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr , int n){
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(vector<int> &arr , int n){
    for(int i =0;i<n-1;i++){
        int minIndex = i;
        for(int j =i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

int main(){
    vector<int> array = {4,2,8,6,1,0};
    int n = array.size();
    selectionSort(array,n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
         cout << array[i] << " ";

}