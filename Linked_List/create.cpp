#include <iostream>
#include <vector>

using namespace std;

class ListNode{
    public:
    int val ;
    ListNode* next;

    public:
    ListNode(int data1,ListNode* next1){
        val = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = {2,4,5,6};
    ListNode* y =  new ListNode(arr[2],nullptr);
    cout<<y->val;
}

/*
we cannot return a whole linkedlist hence we return a pointer to the head */