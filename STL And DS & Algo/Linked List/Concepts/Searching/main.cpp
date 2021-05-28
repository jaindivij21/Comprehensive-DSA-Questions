// Searching an element in a linked list

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

void print(node *head, node *tail) {
    for (; head != tail->next; head = head->next) {
        cout << head->data << " -> ";
    }
    cout << endl;
}

int search(node *head, node *tail, int key) {
    // binary saerch isn't possible in linked lists. Therefore only linear search
    int index = 0;
    for (; head != tail->next; head = head->next, index++) {
        if (head->data == key)
            return index;
    }
    return -1;
}

int main() {
    node *head = nullptr;
    node *tail = nullptr;

    for (int i = 0; i < 11; i++) {
        insertAtEnd(head, tail, i);
    }

    print(head, tail);

    cout << "Enter the element to be searched" << endl;
    int key;
    cin >> key;

    // searching funtion
    int atIndex = search(head, tail, key);
    if (atIndex == -1)
        cout << "The element wasn't found" << endl;
    else
        cout << "The element was found at index " << atIndex << endl;

    return 0;
}