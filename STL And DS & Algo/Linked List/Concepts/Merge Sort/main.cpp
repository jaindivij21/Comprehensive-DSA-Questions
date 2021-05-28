// Merge Sorting in Linked List
// Time Complexity = O(nlogn)

#include<iostream>

using namespace std;

// node classs
class node {
public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};

// insert functions
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

// print funciton
void print(node *head) {
    for (; head != nullptr; head = head->next)
        cout << head->data << " -> ";
}

// opertor overloading
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

// merging function
node *merging(node *&head1, node *&head2) {
    // make the new head & temp
    node *newHead = nullptr;
    node *temp = nullptr;

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

// MERGE SORT FUNCTION
// Recursive Function
node *mergeSort(node *head) {
    // base case
    if (head == nullptr || head->next == nullptr)
        return head;

    // recursive case
    /*
     *  1. Find the mid
     *  2. Break the list along the mid
     *  3. Recursively sort the 2 sub lists
     *  4. Merge them
     */

    // 1&2
    node *mid = midpoint(head);
    node *list1 = head;
    node *list2 = mid->next;
    mid->next = nullptr;

    // 3
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    // 4
    node *finalList = merging(list1, list2);

    return finalList;
}


int main() {
    cout << "Enter the unsorting linked list" << endl;
    node *head = nullptr;
    cin >> head;

    cout << "List before Sorting: " << endl;
    cout << head;

    head = mergeSort(head);

    cout << "\nList after sorting" << endl;
    cout << head;

    return 0;
}