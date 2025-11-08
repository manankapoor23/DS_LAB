#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int getDigit(int num , int place){
    return (num/place)%10;
}

void countSort(vector<int>&arr,int place){
    int n =arr.size(); // 9
    vector<int> output(n); // n sized vector to take the output of size n
    int count[10]={0}; // vector with all zeros to keep the frequency 

    for(int i =0;i<n;i++){
        count[getDigit(arr[i],place)]++; // getdigit(170,1)->0 , count[0]++;
    }

    for(int i =1;i<10;i++){
        count[i]+=count[i-1]; // count[1]=count[1]+count[0] -> count[1]=0+1 = 1
    }
    for(int i=n-1;i>=0;i--){
        int digit = getDigit(arr[i],place);
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    for(int i =0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(vector<int>&arr){
    int maxVal = *max_element(arr.begin(),arr.end()); // gets 802
    for(int place =1;maxVal/place>0;place=place*10){ // place = 1 , 802/1>0;countsort(arr,1)
        countSort(arr,place);
    }
}

int main(){
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout<<"BEFORE: ";
    for(int i:arr){
        cout<<i<<" , ";
    }
    cout<<endl;
    radixSort(arr);
    cout<<"AFTER: ";
    for(int i:arr){
        cout<<i<<" , ";
    }
}