#include <iostream>
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

LinkedList* removeKth(LinkedList* head , int k ){
    if(head==NULL){
        return head;
    }
    if(k==1){
        LinkedList* temp = head ; 
        head = head->next;
        delete temp ; 
        return head ;
        
    }
    int count = 0 ; 
    LinkedList* temp = head ;
    LinkedList*prev = NULL;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev =  temp ;
        temp = temp->next;
        
    }
    return head;
}


int main(){
    vector<int> arr = {2,3,4,6};
    LinkedList* head = convert(arr);
    int k ; 
    cout<<"Enter the element to be removed :";
    cin>>k;
    head = removeKth(head,k);
    print(head);
}