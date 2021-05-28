// Deletion in a linked list
// Deletion is efficient in linked list as compared to an array since we need not shift after deletion

#include<iostream>

using namespace std;


// Defining a node
class node {
public:
    int data;
    node *next;

    // constructor
    node(int d) {
        data = d;
        next = nullptr;
    }
};

// function to calculate the length of the linked list (number of nodes)
int length(node *head, node *tail) {
    int count = 0;
    for (; head != tail->next; head = head->next) {
        count++;
    }
    return count;
}

void insertAtFront(node *&head, node *&tail, int d) {
    if (head == nullptr) {
        head = tail = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void insertAtEnd(node *&head, node *&tail, int d) {
    if (head == nullptr) {
        head = tail = new node(d);
        return;
    }
    node *n = new node(d);
    tail->next = n;
    tail = n;
}

void insertAtMiddle(node *&head, node *&tail, int d, int position) {
    if (position == 1 || head == nullptr) {
        insertAtFront(head, tail, d);
        return;
    } else if (position > length(head, tail)) {
        insertAtEnd(head, tail, d);
        return;
    } else {
        int jumps = 0;
        node *itr = head;
        for (; jumps != position - 1; itr = itr->next, jumps++);
        node *n = new node(d);
        n->next = itr->next;
        itr->next = n;
        return;
    }
}

//  Deletion Functions
void deletionFromFront(node *&head, node *&tail) {
    if (head == nullptr)
        return;
    node *temp = head->next;
    delete head;
    head = temp;
}

void deletionFromEnd(node *&head, node *&tail) {
    if (head == nullptr)
        return;
    else {
        // get to the second last node
        int secondLastPos = length(head, tail) - 1;
        int jumps = 1;
        node *prev = head;  // points to the second last node
        for (; jumps < secondLastPos; prev = prev->next, jumps++);

        // delete the last node
        prev->next = nullptr;
        delete tail;
        tail = prev;
    }
}

void deletionFromMiddle(node *&head, node *&tail, int position) {
    if (head == nullptr)
        return;
    else if (position == 1)
        deletionFromFront(head, tail);
    else if (position == length(head, tail))
        deletionFromEnd(head, tail);
    else {
        // deletion from the middle
        // need to get the target and the prev node from the position to be deleted
        int jumps = 1;
        node *prev = head;
        node *target = nullptr;
        for (; jumps < position - 1; prev = prev->next, jumps++);
        target = prev->next;

        // deletion
        prev->next = target->next;
        delete target;
    }
}

// function to print the linked list
void print(node *head, node *tail) {
    for (; head != tail->next; head = head->next) {
        cout << head->data << " -> ";
    }
    cout << endl;
}

int main() {
    node *head = nullptr;
    node *tail = nullptr;

    // insertions
    for (int i = 1; i < 11; i++) {
        insertAtMiddle(head, tail, i, i);
    }
    print(head, tail);

    // deletions
    deletionFromMiddle(head, tail, 5);
    deletionFromFront(head, tail);
    deletionFromEnd(head, tail);
    print(head, tail);

    return 0;
}