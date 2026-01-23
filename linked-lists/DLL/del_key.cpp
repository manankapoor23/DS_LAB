#include <iostream>
using namespace std;

  class Node {
  public:
       int data;
       Node* prev;
       Node* next;
       Node() {
           this->data = 0;
           this->prev = NULL;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->prev = NULL;
           this->next = NULL;
       }
       Node (int data, Node* next, Node* prev) {
           this->data = data;
           this->prev = prev;
           this->next = next;
       }
  };

class DLL{
    public:
    Node* head ;
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
    void deleteKey(Node* head, int key) {
        Node* temp = head;
        Node* previ = NULL;
        Node* nexter = NULL;
        while(temp!=NULL){
            if(temp->data==key){
                if(temp==head){
                    head=head->next;
                }
                nexter=temp->next;
                previ=temp->prev;
                if(nexter!=NULL){
                    nexter->prev=previ;
                }
                if (previ)
                {
                    previ->next=nexter;
                }
                delete temp;
                return;
                
            }
            else{
                temp=temp->next;
            }
    
        }
    }
    void display(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    DLL list(arr);
    Node* head = list.head;

    cout << "Original list: ";
    list.display(head);

    int key = 3;
    list.deleteKey(head, key);

    cout << "List after deleting key " << key << ": ";
    list.display(head);

    return 0;
}