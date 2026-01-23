#include<iostream>
#include<stack>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int val,Node* next1,Node* next2){
        data=val;
        next = next1;
        back = next2;
    }
    public:
    Node(int data1){
        data=data1;
        next = nullptr;
        back = nullptr;
    }
};

class DLL {
public:
    Node* head;

    // Constructor to create DLL from vector
    DLL(vector<int>& arr) {
        if (arr.empty()) {
            head = nullptr;
            return;
        }

        head = new Node(arr[0]);
        Node* prev = head;

        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
    }
};
int main(){
    vector<int> arr= {2,3,4,5};
    DLL list(arr);
    Node* head = list.head;
    void reverser(Node* head){
        stack<int> st;
        Node* temp = head;
    }
}