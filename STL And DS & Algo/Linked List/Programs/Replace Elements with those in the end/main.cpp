// Program to swap kth element of a LL with the sum of itself and n-(k-1)th element where k = 1,2,3,4 ... n
// TC: O(n) and SC: O(n)

// The main issue with this problem was travelling backwards in a singly linekd list, this was solved by reversing the LL.

#include<bits/stdc++.h>

using namespace std;

// LL node
class Node {
public:
    int val;
    Node *next;

    // constructor/initialization
    explicit Node(int val) : val(val), next(nullptr) {}
};

// function to make a ll
Node *buildLL() {
    int size;
    cin >> size;
    Node *head = nullptr;
    Node *ptr = head;
    int element;
    cin >> element;
    head = new Node(element);
    ptr = head;
    for (int i = 1; i < size; i++, ptr = ptr->next) {
        cin >> element;
        ptr->next = new Node(element);
    }
    return head;
}

// function to print a ll
void printLL(Node *head) {
    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
}

// reverse a linked list
void reverseLL(Node *&head) {
    Node *curr = head;
    Node *next = nullptr;
    Node *prev = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// main function : 2*O(n) for a doubly linked list
Node *replace(Node *&head) {
    // store the values in an array
    Node *ptr1 = head;
    int arr[100];
    int i = 0;
    while (ptr1 != nullptr) {
        arr[i++] = ptr1->val;
        ptr1 = ptr1->next;
    }
    // reverse the linked list
    reverseLL(head);
    ptr1 = head;
    i = 0;
    // traverse over this linked list and add the values from the array
    while (ptr1 != nullptr) {
        ptr1->val += arr[i++];
        // increment
        ptr1 = ptr1->next;
    }
    return head;
}

int main() {
    Node *head = buildLL();
    printLL(head);
    cout << endl;

    // main function
    head = replace(head);
    printLL(head);

    return 0;
}