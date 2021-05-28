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

void insertAtEnd(node *&head, node *&tail, int d) {
    if (head == nullptr) {
        head = tail = new node(d);
        return;
    }
    node *n = new node(d);
    tail->next = n;
    tail = n;
}

void takeInput(node *&head, node *&tail, int d) {
    insertAtEnd(head, tail, d);
}

void print(node *head, node *tail) {
    for (; head != tail->next; head = head->next) {
        cout << head->data << " -> ";
    }
    cout << endl;
}

int main() {
    // initialize the linked list
    node *head = nullptr;
    node *tail = nullptr;

    // take input till the user doesn't input -1
    int d;
    cin >> d;
    while (d != -1) {
        takeInput(head, tail, d);
        cin >> d;
    }

    print(head, tail);

    return 0;
}