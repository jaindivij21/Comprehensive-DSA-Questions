// Program to find the Kth node from the end of the linked list
/*
 *  Methods:
 *  1) First method can be to find the length of the list in O(n) time and then cal the value
 *     of length - k + 1. Now iterate over the list and print that element.
 *  2) Use the running concept i.e. make 2 pointers slow and fast both pointing to head.
 *     Slow needs to reach N-k+1 and fast needs to reach nullptr. Hence we start moving slow when fast
 *     pointer reaches K+1
 */

#include<iostream>

using namespace std;

class node {
public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};

void insertAtEnd(node *&head, int d) {
    if (head == nullptr) {
        head = new node(d);
        return;
    } else {
        node *itr = head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = new node(d);
        return;
    }
}

void takeInput(node *&head) {
    int d;
    cin >> d;
    while (d != -1) {
        insertAtEnd(head, d);
        cin >> d;
    }
}

void print(node *head) {
    for (; head != nullptr; head = head->next)
        cout << head->data << " -> ";
}

// function to print a linked list
ostream &operator<<(ostream &os, node *head) {
    print(head);
    return os;
}

// function to take a linked list as input
istream &operator>>(istream &is, node *&head) {
    takeInput(head);
    return is;
}

// function to return the kth node from the end
node *kthNode(node *&head, int k) {
    node *slowptr = head;
    node *fastptr = head;
    // make k jumps for fast ptr
    while (k--)
        fastptr = fastptr->next;
    // now till fast reaches null increment both slow and fast ptrs
    while (fastptr != nullptr) {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
    return slowptr;
}

int main() {
    node *head = nullptr;
    cin >> head;
    cout << head << endl;

    int k;
    cout << "Enter the value of K" << endl;
    cin >> k;
    // function to reverse a linked list
    node *ans = kthNode(head, k);

    cout << "Kth node from the end is " << ans->data << endl;

    return 0;
}