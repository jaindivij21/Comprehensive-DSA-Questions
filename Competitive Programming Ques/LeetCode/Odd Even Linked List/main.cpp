// Odd Even Linked List :: Leetcode
// https://leetcode.com/problems/odd-even-linked-list/

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

ListNode *oddEvenList(ListNode *&head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;

    ListNode *oddPtr = odd;
    ListNode *evenPtr = even;

    // loop till the last element
    while (evenPtr != nullptr && evenPtr->next != nullptr) {
        oddPtr->next = evenPtr->next;
        evenPtr->next = evenPtr->next->next;
        oddPtr = oddPtr->next;
        evenPtr = oddPtr->next;
    }
    oddPtr->next = even;
    return odd;
}

int main() {
    ListNode *head = nullptr;
    int n;
    cin >> n;

    takeInput(head, n);

    head = oddEvenList(head);

    printList(head);

    return 0;
}

