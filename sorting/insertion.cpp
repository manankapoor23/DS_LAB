#include <iostream>
#include <vector>
using namespace std;



void insertionSort(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;


        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    vector<int> array = {4,2,8,6,1,0};
    int n = array.size();
    insertionSort(array,n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
         cout << array[i] << " ";

}