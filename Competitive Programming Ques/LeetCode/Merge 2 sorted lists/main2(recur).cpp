// Merge 2 Sorted Lists :: Leetcode
// https://leetcode.com/problems/merge-two-sorted-lists/

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

    ListNode(int data, ListNode *ptr) {
        val = data;
        next = ptr;
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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // base cases
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    // recursive cases
    ListNode *temp = nullptr;
    if (l1->val <= l2->val) {
        temp = l1;
        temp->next = mergeTwoLists(l1->next, l2);
    } else {
        temp = l2;
        temp->next = mergeTwoLists(l1, l2->next);
    }
    return temp;
}

int main() {
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int n1, n2;
    cin >> n1 >> n2;
    takeInput(head1, n1);
    takeInput(head2, n2);

    ListNode *ans = mergeTwoLists(head1, head2);

    printList(ans);

    return 0;
}