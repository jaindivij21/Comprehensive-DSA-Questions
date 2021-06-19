// Linked List Cycle - 1&2  :: Leetcode
// https://leetcode.com/problems/linked-list-cycle/
// https://leetcode.com/problems/linked-list-cycle-ii/

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

// Mehtod - 1 (Uses hash map) 
bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, bool>  visited;
    ListNode * ptr = head;

    // start traversing 
    while(ptr !=  nullptr){
        if(visited[ptr]){
            return true;
        }
        visited[ptr] = true;
        ptr = ptr -> next;
    }
    return false;
}

// Method - 2 (Runner Approach) - Constant Space
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow =  slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

// Method - 3 (Floyd Warshall Method)
ListNode *detectCycle(ListNode *head) {
    if(head==nullptr) return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    int flag = 0;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (fast != slow) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}