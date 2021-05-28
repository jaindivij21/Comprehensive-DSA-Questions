// Doubly Linked List
// Program to demonstrate insertion and deletion in doubly linked list
// searching and reversing will almost be the same
// remember the transversal in doubly linked list is possible in both direction i.e bidirectional
// https://www.softwaretestinghelp.com/doubly-linked-list-2/

#include <iostream>

using namespace std;

// A doubly linked list node
class node {
public:
    int data;
    node *next;
    node *prev;

    // constructor
    node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// function to calculate the length of the linked list (number of nodes)
int length(node *head) {
    int count = 0;
    for (; head != nullptr; head = head->next) {
        count++;
    }
    return count;
}

// function to add supppliment to create list
void addNode(node *&head, node *&tail, int d) {
    if (head == nullptr) {
        // list is empty
        head = tail = new node(d);
        return;
    } else {
        node *n = new node(d);
        tail->next = n;
        n->prev = tail;
        tail = n;
        return;
    }
}

// create a list
void createList(node *&head) {
    // make a tail pointer for ease
    node *tail = nullptr;
    cout << "Enter the elements of the list" << endl;
    int d;
    cin >> d;
    while (d != -1) {
        addNode(head, tail, d);
        cin >> d;
    }
}

// Inserion
void insertion(node *&head) {
    /*
     *  3 types of insertion:
     *  1) Insertion at front
     *  2) Insertion at end
     *  3) Insertion in middle
     */
    cout << "Enter the element to be inserted and its position" << endl;
    int d, pos;
    cin >> d >> pos;

    if (head == nullptr) {
        // list is empty
        head = new node(d);
        return;
    }

    if (pos <= 0) {
        cout << "Error position" << endl;
        return;
    } else {
        // new node
        node *n = new node(d);
        if (pos == 1) {
            // insertion at the front
            n->next = head;
            head->prev = n;
            head = n;
        } else if (pos == length(head) + 1) {
            // insertion at the end
            node *tail = head;
            while (tail->next != nullptr)
                tail = tail->next;
            tail->next = n;
            n->prev = tail;
            tail = n;
        } else {
            // insertion in the middle
            node *itrBefore = head;
            node *itrAfter = head;
            pos = pos - 2;
            while (pos--) {
                itrAfter = itrAfter->next;
                itrBefore = itrBefore->next;
            }
            itrAfter = itrAfter->next;
            n->next = itrAfter;
            n->prev = itrBefore;
            itrBefore->next = n;
            itrAfter->prev = n;
        }
    }
}

// Deletion
void deletion(node *&head) {
    /*
   *  3 types of deletion:
   *  1) deletion at front
   *  2) deletion at end
   *  3) deletion in middle
   */
    cout << "Enter the element's position to be deleted" << endl;
    int pos;
    cin >> pos;

    if (head == nullptr) {
        // list is empty, cant delete anything
        return;
    }

    if (pos <= 0) {
        cout << "Error position" << endl;
        return;
    } else {
        if (pos == 1) {
            // deletion at the front
            node *temp = head;
            head->next->prev = nullptr;
            head = head->next;
            delete temp;
        } else if (pos == length(head)) {
            // deletion at the end
            node *itr = head;
            while (itr->next != nullptr)
                itr = itr->next;
            itr->prev->next = nullptr;
            delete itr;
        } else {
            // deletion in the middle
            node *itr = head;
            pos--;
            while (pos--)
                itr = itr->next;
            itr->prev->next = itr->next;
            itr->next->prev = itr->prev;
            delete itr;
        }
    }
}

// print function
void print(node *head) {
    for (; head != nullptr; head = head->next) {
        cout << head->data << " <-> ";
    }
    cout << endl;
}

// operator overloading
istream &operator>>(istream &is, node *&head) {
    createList(head);
    return is;
}

ostream &operator<<(ostream &os, node *head) {
    print(head);
    return os;
}


//main program
int main() {
    node *head = nullptr;

    // creation
    cin >> head;
    cout << head;

    // insertion
    insertion(head);
    cout << head;

    // deletion
    deletion(head);
    cout << head;
    
    return 0;
}