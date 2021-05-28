// Input and Output Data in LINKED LIST
// Using operator overloading
// Best and easiest method

#include<iostream>

using namespace std;

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

// Operator Overloading functions
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


int main() {
    // 2 linked lists
    node *head1 = nullptr;
    node *head2 = nullptr;
    // take user input for linked list using operator overloading
    cin >> head1 >> head2;
    // print out the linked list using operator overloading
    cout << head1 << "---> " << head2 << endl;
    return 0;
}