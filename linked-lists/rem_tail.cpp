#include <iostream>
#include <vector>
using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* next ;
    public:
    LinkedList(int x, LinkedList* y) : val(x), next(y) {}


};
LinkedList* removeTail(LinkedList* head){
    if (head == NULL) return NULL;
    if (head->next == NULL) { delete head; return NULL; }



    LinkedList* temp = head ;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next= nullptr;
    return head ;

}
LinkedList* convert(vector<int> arr){
    if(arr.size() == 0) return nullptr;

    LinkedList* head = new LinkedList(arr[0],nullptr);
    LinkedList* curr = head;
    for(int i=1;i<arr.size();i++){
        LinkedList* newNode = new LinkedList(arr[i],nullptr);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}
void print(LinkedList* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {1,4,7,6,4,2,6,9};
    LinkedList* head = convert(arr);
    head = removeTail(head);
    print(head);

}