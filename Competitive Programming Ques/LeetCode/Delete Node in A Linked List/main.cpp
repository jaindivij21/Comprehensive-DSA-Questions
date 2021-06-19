// Delete Node in a Linked List:: Leetcode
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    // constructor
    ListNode() {
        val = 0;
        next = nullptr;
    }

    explicit ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

void deleteNode(ListNode* node) {
    ListNode *prev = node;
    ListNode *ptr = node->next;
    while(ptr->next!=nullptr){
        swap(prev->val, ptr->val);
        ptr=ptr->next;
        prev = prev->next;
    }
    swap(prev->val, ptr->val);
    prev->next = nullptr;
    delete ptr;
}