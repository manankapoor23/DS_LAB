#include <iostream>
#include <vector>
#include "linkedlist.h"

using namespace std;


ListNode* insertHead(ListNode* head , int val ){
    ListNode* temp = new ListNode(val,head) ;
    return temp ; 

}

int main(){
    vector<int> arr = {2,3,4,6,7};
    ListNode* head =  convert(arr);
    head = insertHead(head,9);
    print(head);
}