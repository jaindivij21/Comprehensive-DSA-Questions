// Mid Point Runner Technique
// Program to find the mid point of a linked list

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

// function to find the midpoint of the linked list
node *midpoint(node *head) {
    if (head == nullptr || head->next == nullptr) {
        // if the list is empty or just one element
        return head;
    }
    // else we'll use the running method to find the middle element of list
    node *slowptr = head;
    node *fastptr = head->next;

    while (fastptr != nullptr && fastptr->next != nullptr) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}

int main() {
    node *head = nullptr;
    cin >> head;
    cout << head << endl;

    node *mid = midpoint(head);

    cout << "Midpoint value is " << mid->data << endl;

    return 0;
}