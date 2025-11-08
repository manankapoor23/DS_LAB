#include <iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size =0;

    Heap(){
        arr[0]= -1;
        size = 0;
    }
    
    void insert(int val){
        size++;
        int index = size;
        arr[index]=val;
        while(index >1 ){
            int p_idx = index/2;
            if(arr[p_idx]<arr[index]){
                swap(arr[p_idx],arr[index]);
                index = p_idx;
            }
            else{
                return ;
            }
        }
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"cannot perform ops";
            return;
        }
        // step 1 , put last element into first index and reduce size 
        arr[1]=arr[size];
        // remove last element 
        size--;
        // take root node to its correct postion
        int i =1;
        while(i<size){
            int leftINDEX=2*i;
            int rightINDEX =2*i+1;
            if(leftINDEX<size && arr[i]<arr[leftINDEX]){
                swap(arr[i],arr[leftINDEX]);
                i=leftINDEX;
            }
            else if(rightINDEX<size && arr[i]<arr[rightINDEX]){
                swap(arr[i],arr[rightINDEX]);
                i = rightINDEX;
            }
            else{
                return;
            }
        }

    }
    void print(){
        for(int i =1;i<=size;i++){
            cout<<arr[i]<<" ";                
        }
        cout<<endl;
    }
};

int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(52);
    h.insert(45);
    h.print();
    h.deleteFromHeap();
    h.print();

}