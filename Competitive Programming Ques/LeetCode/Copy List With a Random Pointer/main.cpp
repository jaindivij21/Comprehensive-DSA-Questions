// Copy List With Random Pointer :: Leetcode
// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://youtu.be/5Y2EiZST97Y

#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *random;

    // constructor
    ListNode() {
        val = 0;
        next = nullptr;
        random = nullptr;
    }

    explicit ListNode(int data) {
        val = data;
        next = nullptr;
        random = nullptr;
    }
};

void append(ListNode *&head, int data) {
    auto *temp = new ListNode(data);
    if (head == nullptr) {
        head = temp;
    } else {
        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    // random pointer needs to point to any random pointer
}

void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
}

void takeInput(ListNode *&head, int n) {
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        append(head, data);
    }
}

// 2 pass algorithm (linear time)
ListNode *copyRandomList(ListNode *head) {
    // hash map
    unordered_map<ListNode *, ListNode *> copyToNew;

    // pass - 1
    ListNode *ptr = head;
    while (ptr != nullptr) {
        auto *temp = new ListNode(ptr->val);
        copyToNew.insert(make_pair(ptr, temp));
        ptr = ptr->next;
    }

    // pass - 2 :: make use of this hash map to draw the connections
    ptr = head;
    while (ptr != nullptr) {
        auto *temp = copyToNew[ptr];
        temp->next = copyToNew[ptr->next];
        temp->random = copyToNew[ptr->random];
        ptr = ptr->next;
    }
    return copyToNew[head];
}

int main() {
    int size;
    cin >> size;
    ListNode *head = nullptr;
    takeInput(head, size);

    ListNode *ans = copyRandomList(head);

    printList(ans);

    return 0;
}