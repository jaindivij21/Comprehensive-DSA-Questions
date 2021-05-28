// Program to merge two sorted lists into one single list
// 2 Methods: 1) Iterative (https://www.youtube.com/watch?v=j_UNYW6Ap0k) 2) Recursive

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

node *iterativeMerging(node *&head1, node *&head2, node *temp) {
    // make the new head
    node *newHead = nullptr;

    // base conditions (if one of the lists are empty)
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    // assign the temp ptr the initial value
    // it points to the smaller first node from the lists
    if (head1->data <= head2->data) {
        temp = head1;
        head1 = head1->next;
    } else {
        temp = head2;
        head2 = head2->next;
    }

    // make new head equal to temp (HERE ONLY)
    newHead = temp;

    // now we start comparing the 2 heads
    while (head1 != nullptr && head2 != nullptr) {
        // loop runs until one of the head doesn't reach the ending null ptr
        if (head1->data <= head2->data) {
            // if head1 is smaller
            // point temp is head1, update temp to head, and finally increment head in that list
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        } else {
            // if head2 is smaller
            // point temp is head2, update temp to head, and finally increment head in that list
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    // after this loop ends, there may be a possibility where a list is still pending
    if (head1 == nullptr) {
        // means list1 has ended
        // so now point the temp (which is at last list 1 element) to head2
        temp->next = head2;
    }
    if (head2 == nullptr) {
        // head2 is nullptr i.e list 2 has ended
        // so now point the temp (which is at last list 2 element) to head1
        temp->next = head1;
    }
    return newHead;
}

node *recursiveMerging(node *head1, node *head2) {
    // base cases
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    // recursive cases
    node *temp;
    if (head1->data <= head2->data) {
        temp = head1;
        temp->next = recursiveMerging(head1->next, head2);
    } else {
        temp = head2;
        temp->next = recursiveMerging(head1, head2->next);
    }
    return temp;
}

int main() {
    // input the 2 lists
    node *head1 = nullptr;
    node *head2 = nullptr;
    cin >> head1 >> head2;
    cout << head1 << endl;
    cout << head2 << endl;

    int choice;
    cout << "Enter 1 or 2 to decide bw iterative or recursive methods" << endl;
    cin >> choice;

    node *newHead = nullptr;

    if (choice == 1) {
        // iterative method to merge the 2 lists
        node *temp1 = nullptr; // helping ptr to merge the 2 lists
        newHead = iterativeMerging(head1, head2, temp1);
        cout << "The new list would be:" << endl;
        cout << newHead << endl;
    }
    if (choice == 2) {
        // recursive method to merge the 2 lists
        newHead = recursiveMerging(head1, head2);
        cout << "The new list would be:" << endl;
        cout << newHead << endl;
    }
    return 0;
}