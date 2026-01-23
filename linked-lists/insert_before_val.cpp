#include <iostream>
#include "linkedlist.h"

using namespace std;

ListNode* inserBeforeVal(ListNode* head , int val, int k){
    if(head==NULL){
        return NULL;
    }
    if(head->val==val){
        return new ListNode(k,head);
    }
    ListNode* temp = head ;
    while(temp->next!=NULL){
        if(temp->next->val == val){
            ListNode* x = new ListNode(k,temp->next);
            temp->next = x;
            break;

        }
        temp= temp->next;

    }
    return head;
}

int main(){
    vector<int> arr = {2,3,4};
    ListNode* head  = convert(arr);
    head = inserBeforeVal(head , 100,4);
    print(head);
}