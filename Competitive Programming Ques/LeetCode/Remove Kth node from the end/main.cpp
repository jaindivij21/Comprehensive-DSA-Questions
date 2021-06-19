// Remove Nth Node from the end of the list :: Leetcode
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://www.youtube.com/watch?v=XVuQxVej6y8

#include<bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node *next;

    // constructor
    node() {
        val = 0;
        next = nullptr;
    }

    node(int data) {
        val = data;
        next = nullptr;
    }
};

void append(node *&head, int data) {
    node *temp = new node(data);
    if (head == nullptr) {
        head = temp;
    } else {
        node *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void printList(node *head) {
    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
}

void takeInput(node *&head, int n) {
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        append(head, data);
    }
}

// 2 pass is easy - go to the end and come back k positions; but we'll try to do it in one pass
// use running method to do this i.e. fast and slow pointers
node *removeNthFromEnd(node *&head, int k) {
    // dummy node pointing to head
    node *dummy = new node(0);
    dummy->next = head;

    // make 2 pointers
    node *slow = dummy, *fast = head;

    // increment it
    while (k-- && fast) {
        // while k isn'0 and fast isn't equal to null ptr
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

int main() {
    node *head = nullptr;
    int n;
    cin >> n;
    takeInput(head, n);
    printList(head);

    int k;
    cin >> k;
    head = removeNthFromEnd(head, k);

    printList(head);

    return 0;
}