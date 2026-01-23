#include <iostream>
#include<vector>
using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* next ;
    public:
    LinkedList(int x, LinkedList* y) : val(x), next(y) {}


};

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

LinkedList* removeVal(LinkedList* head , int val ){
    int x = val ;
    if(head==NULL){
        return head;
    } 
    if(head->val==x){
        LinkedList*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    LinkedList* temp = head ;
    LinkedList*prev = NULL;
    while(temp!=NULL && temp->val!=x){
        prev = temp ; 
        temp = temp->next;
        }
        if(temp==NULL){
            cout<<"not found"<<endl;
            return head;
        }
        prev->next=temp->next;
        delete temp; 
    return head;
}


int main(){
    vector<int> arr = {20,33,55,32,11};
    LinkedList* head = convert(arr);
    int k ; 
    cout<<"Enter the value of  element to be removed :";
    cin>>k;
    head = removeVal(head,k);
    print(head);
}