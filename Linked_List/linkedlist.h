#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x, ListNode* y = nullptr) : val(x), next(y) {}
};

// Convert vector<int> to Linked List
inline ListNode* convert(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0], nullptr);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        ListNode* newNode = new ListNode(arr[i], nullptr);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}

// Print Linked List
inline void print(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Free memory used by Linked List
inline void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

#endif // LISTNODE_H
