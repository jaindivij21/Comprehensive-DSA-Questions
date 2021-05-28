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
void reverse(node *&head) {
    node *curr = head;
    node *prev = nullptr;
    node *n;

    // start the loop
    while (curr != nullptr) {
        n = curr->next; // store the next node
        curr->next = prev;  // point the current node to previous node

        // update the pointers
        prev = curr;
        curr = n;
    }
    // finally change the head pointer
    head = prev;
}

int main() {
    node *head = nullptr;
    cin >> head;
    cout << head << endl;

    // function to reverse a linked list
    reverse(head);

    cout << head << endl;

    return 0;
}