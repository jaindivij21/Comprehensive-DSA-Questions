// Palindrome Linked List :: Leetcode
// https://leetcode.com/problems/palindrome-linked-list/

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

// find midpoint
ListNode *midpoint(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// If a linked list is a palindrome
bool isPalindrome(ListNode *&head) {
    // find the mid point and reverse the linked list after it
    ListNode *mid = midpoint(head);
    ListNode *newList = reverseList(mid->next);
    mid->next = nullptr;    // just to break the 2 lists

    // now just compare the first (head) and second list (newList) :: how ever if the original list was odd then, first list will have an extra element at the end
    // so to counter that run the while loop only till ptr2 is not null (since extra element always appears in list1 (head))
    ListNode *ptr1 = head;
    ListNode *ptr2 = newList;
    while (ptr2 != nullptr) {
        if (ptr1->val != ptr2->val)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

int main() {
    ListNode *head = nullptr;
    int n;
    cin >> n;

    takeInput(head, n);

    bool ans = isPalindrome(head);

    cout << ans;

    return 0;
}

