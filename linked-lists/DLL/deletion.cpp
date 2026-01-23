#include <iostream>
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

    // ✅ Delete the head node
    void deleteHead() {
        if (head == nullptr||head->next==nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        Node* prev = head;
        head = head->next;
        head->back=nullptr;
        prev->next=nullptr;
        delete prev;
    }
    void deleteTail(){
        if (head == nullptr) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
    }
        Node* tail = head;
        while(tail->next!=nullptr){
            tail=tail->next;
        }
        Node* previous =tail->back;
        previous->next=NULL;
        tail->back=NULL;
        delete tail;
    }

    // ✅ Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    vector<int> arr = {1,2,3,4};
    DLL list(arr);
    list.display();
    list.deleteTail();
    list.deleteTail();
    list.display();
    

}