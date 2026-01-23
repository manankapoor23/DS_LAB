#include <iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution{
    public:
    ListNode* sum(ListNode* l1 , ListNode* l2){
        ListNode dummy(0);
        ListNode* curr = &dummy; // [0]->null

    int carry =0 ;
    while(l1!=NULL || l2!=NULL||carry>0){
        int sum = carry; // sum = 0 
        if(l1){
            sum = sum + l1->val; // sum = 0 + 2 = 2
            l1=l1->next;
        }
        if(l2){
            sum = sum + l2->val;
            l2=l2->next;
        }

        carry = sum/10;
        curr->next=new ListNode(sum%10);
        curr=curr->next;
    
    return dummy.next;

    }
}
};

int main(){
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(3);
    Solution obj;
    ListNode* ans = obj.sum(a,b);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }

    return 0;
}