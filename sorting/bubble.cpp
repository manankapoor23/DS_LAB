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


int main(){
    vector<int> array = {4,2,8,6,1,0};
    int n = array.size();
    bubbleSort(array,n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
         cout << array[i] << " ";

}