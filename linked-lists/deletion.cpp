#include <iostream>
using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* next ;
    public:
    LinkedList(int x, LinkedList* y) : val(x), next(y) {}


};
LinkedList* removeHead(LinkedList* head){
    if(head == nullptr) return nullptr;
    LinkedList* temp = head->next;
    delete head;
    return temp;
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
    vector<int> arr = {1,2,3,4,5};
    LinkedList*head = convert(arr);
    head = removeHead(head); // head to jo aapne temp diya tha function mai next wale pe wo dedo 
    print(head);

}


