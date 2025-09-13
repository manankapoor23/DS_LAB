#include <iostream>
#include "linkedlist.h"

using namespace std ;

ListNode* insertK(ListNode* head , int el ,int  k){
    int counter = 0 ;

    if(head == NULL){
        if(k==1){
            return new ListNode(el);
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        ListNode* temp = new ListNode(el,head);
        return temp;
    }
    ListNode* temp = head ;
    while(temp !=NULL){
        count++;
    }
}