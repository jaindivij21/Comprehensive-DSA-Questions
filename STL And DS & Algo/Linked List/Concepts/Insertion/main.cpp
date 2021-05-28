// Insertion in a linked list

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

// function that inserts values in linked list's front i.e head
// remember to pass the head and the tail of the linked list by reference
void insertAtFront(node *&head, node *&tail, int d) {
    // if list is empty
    if (head == nullptr) {
        /*
         *  Reasons why we use dynamic method to create a new node class object:
         *  1) if we made a static object/node, it would have been destroyed after the funciton call.
         *  2) new keyword always returns address. therefore since head and tail are pointers i.e store addresses, it becomes easier.
         */
        head = tail = new node(d);
        return;
    }
    // if list isn't empty

    // make the new node
    node *n = new node(d);    // here the newNode variable stores address to our new node i.e its a pointer
    n->next = head; // store the head's address into the new node's (which is pointed by n) next variable
    // (*n).next = head (other method to do the same thing as above line)
    head = n;
}

// function to insert at the end
void insertAtEnd(node *&head, node *&tail, int d) {
    if (head == nullptr) {
        // empty list
        head = tail = new node(d);
        return;
    }
    // list isn't empty
    node *n = new node(d);  // make a new node
    tail->next = n; // change the address of second last node
    tail = n;   // change tail
}

// function to insert at the middle
void insertAtMiddle(node *&head, node *&tail, int d, int position) {
    if (position == 1 || head == nullptr) {
        // list is empty or we need to insert at the 0th position
        insertAtFront(head, tail, d);
        return;
    } else if (position > length(head, tail)) {
        // insertion at the end
        insertAtEnd(head, tail, d);
        return;
    } else {
        // insertion in the middle (we need to stop at the position - 1th node)
        int jumps = 0;  // variable to keep count of number of jumps
        node *itr = head;
        for (; jumps != position - 1; itr = itr->next, jumps++); // now itr is at position - 1th place
        // insert
        node *n = new node(d);  // new node
        n->next = itr->next;
        itr->next = n;
        return;
    }
}

// function to print the linked list
void print(node *head, node *tail) {
    // since we didn't pass head by refernce even if we are updating head, it wont affect the actual linked list (IMPORTANT)
    // while(head != nullptr) OR
    for (; head != tail->next; head = head->next) {
        cout << head->data << " -> ";
    }
    cout << endl;
}

int main() {
    // initially a head pointer and a tail pointer will point to NULL when the list is empty
    node *head = nullptr;
    node *tail = nullptr;   // tail function is a added functionality. linked list can work without using this also

    insertAtFront(head, tail, 4);
    insertAtFront(head, tail, 3);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 1);

    print(head, tail);


    insertAtEnd(head, tail, 9);
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 11);
    insertAtEnd(head, tail, 12);

    print(head, tail);

    insertAtMiddle(head, tail, 0, 1);   // insert at 1st position i.e beginning
    insertAtMiddle(head, tail, 5, 5);
    insertAtMiddle(head, tail, 6, 6);
    insertAtMiddle(head, tail, 7, 7);
    insertAtMiddle(head, tail, 8, 8);

    print(head, tail);

    return 0;
}