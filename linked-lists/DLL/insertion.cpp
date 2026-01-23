#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;
    Node(int x,Node*a ,Node* b){
        this->data=x;
        this->next=a;
        this->back=b;
    }
    Node(int x){
        this->data=x;
        this->next=NULL;
        this->back=NULL;
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
    void printList(){
        Node* t = head;
        do{
            cout<<t->data<<" <-> ";
            t=t->next;
        }while (t!=NULL);
        cout<<endl;

    }
    void insert(int x,int pos){
        Node* t = new Node(x);
        Node* p = head;
        Node* mover = head;
        if(pos==0){
            //insert at before head 
            t->next=p;
            p->back=t;
            t->back=NULL;
            head=t;
        }
        else{
            for(int i =0;i<pos-1;i++){
                mover = mover->next;
            }
            // now our mover is on the node before we want to add
            mover->next->back=t;
            t->next=mover->next;
            mover->next=t;
            t->back=mover;
        }

    }
};



int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    DLL d(arr);
    d.printList();
    d.insert(49,5);
    d.printList();

}