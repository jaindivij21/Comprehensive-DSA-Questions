// Reverse Linked List :: Leetcode
// https://leetcode.com/problems/reverse-linked-list/

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

// Reverse a linked list
ListNode *reverseList(ListNode *&head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    ListNode *head = nullptr;
    int n;
    cin >> n;

    takeInput(head, n);

    ListNode *ans = reverseList(head);

    printList(ans);

    return 0;
}

