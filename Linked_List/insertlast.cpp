#include <iostream>
#include <vector>
#include "linkedlist.h"   // your header

using namespace std;

ListNode* insertLast(ListNode* head, int val) {
    if (head == nullptr) {  // empty list
        return new ListNode(val);
    }

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Add new node at end
    ListNode* newer = new ListNode(val);
    temp->next = newer;

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    ListNode* head = convert(arr);

    head = insertLast(head, 10);
    print(head);

    freeList(head); // free memory

    return 0;
}
