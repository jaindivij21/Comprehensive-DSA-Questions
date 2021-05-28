// circular linked list

#include <iostream>

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

void addNode(node *&head, int d) {
    if (head == nullptr) {
        // initially the list is empty
        head = new node(d);
        head->next = head;
        return;
    } else {
        // if list isn't empty
        node *n = new node(d);
        node *itr = head;
        while (itr->next != head)
            itr = itr->next;
        n->next = head;
        itr->next = n;
    }
}

void takeInput(node *&head) {
    int d;
    cin >> d;
    while (d != -1) {
        addNode(head, d);
        cin >> d;
    }
}

void print(node *head) {
    node *itr = head;
    while (itr->next != head) {
        cout << itr->data << " -> ";
        itr = itr->next;
    }
    cout << itr->data;
    cout << endl;
    return;
}

// Get node (search function)
node *getNode(node *head, int data) {
    node *temp = head;
    while (temp->next != head) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    if (temp->data == data)
        return temp;
    else
        return nullptr;
}

// Deletion
void deletion(node *&head, int i) {
    // you already know and can code to delete an element if its position is inputted.
    // here we'll change it. now the user inputs the actual node data that needs to be deleted.
    cout << "Enter the element to be deleted" << endl;
    int d;
    cin >> d;


    if (head == nullptr) {
        // list is empty, cant delete anything
        return;
    } else {
        node *del = getNode(head, d);
        if (del == nullptr)
            return;
        if (del == head) {
            // first node has to be deleted
            head = head->next;
            node *itr = head;
            while (itr->next != del)
                itr = itr->next;
            itr->next = head;
            delete del;
        } else if (del->next == head) {
            // last element has to be deleted
            node *itr = head;
            while (itr->next != del)
                itr = itr->next;    // stops one step behind the last element
            itr->next = head;
            delete del;
        } else {
            node *itr = head;
            while (itr->next != del)
                itr = itr->next;
            itr->next = del->next;
            delete del;
        }
    }

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
    node *head = nullptr;
    // take user input for linked list using operator overloading
    cin >> head;
    // print out the linked list using operator overloading
    cout << head;

    deletion(head, 3);

    cout << head;
    return 0;
}