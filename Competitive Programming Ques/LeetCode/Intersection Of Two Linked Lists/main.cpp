// Intersection Of 2 Linked Lists : Leetcode
// https://leetcode.com/problems/intersection-of-two-linked-lists/

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

// calculate length of lists in O(n) time
int len(ListNode *l1) {
    ListNode *ptr = l1;
    int count = 1;
    while (ptr->next != nullptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len0 = len(headA);
    int len1 = len(headB);

    // pointers
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    // cal the difference
    int flag = -1;
    int diff = -1;
    if (len0 >= len1) {
        flag = 0;
        diff = len0 - len1;
    } else {
        flag = 1;
        diff = len1 - len0;
    }

    // increment the difference of the list
    if (flag) {
        // headB is bigger
        while (diff--)
            ptrB = ptrB->next;
    } else {
        // headA is bigger
        while (diff--)
            ptrA = ptrA->next;
    }

    // find the intersection point
    while (ptrA != ptrB) {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return ptrA;
}

int main() {
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int m, n;
    cin >> m >> n;
    takeInput(head1, m);
    takeInput(head2, n);

    ListNode *ans = getIntersectionNode(head1, head2);

    cout << ans->val;

    return 0;
}

