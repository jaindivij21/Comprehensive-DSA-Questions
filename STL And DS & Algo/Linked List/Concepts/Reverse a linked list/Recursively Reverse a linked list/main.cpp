// Program to reverse a linked list
// Iterative Method

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

// function to reverse the linked list
node *recursiveRev(node *&head) {
    // base case
    if (head->next == nullptr or head == nullptr) {
        // list contains just 1 or even 0 elements
        return head;
    }
    // ex. 1 -> 2 -> 3 -> 4 (4 returns the base case)
    // recursive case
    node *smallHead = recursiveRev(head->next); // if 3 is head, 4 will be the small head for it

    // now we need to reverse the pointers
    node *temp = head->next;
    temp->next = head;
    head->next = nullptr;

    return smallHead;
}

int main() {
    node *head = nullptr;
    cin >> head;
    cout << head << endl;

    // function to reverse a linked list
    head = recursiveRev(head);

    cout << head << endl;

    return 0;
}