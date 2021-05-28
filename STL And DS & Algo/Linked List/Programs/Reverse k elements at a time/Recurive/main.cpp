// Reverse k elements at a time in a linked list
/*
    Sample Input
    9 3
    9 4 1 7 8 3 2 6 5
    Sample Output
    1 4 9 3 8 7 5 6 2
 */

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

void createList(node *&head, int size) {
    node *tail = nullptr;
    while (size--) {
        int data;
        cin >> data;

        // insert data at the end
        if (head == nullptr)
            head = tail = new node(data);
        else {
            tail->next = new node(data);
            tail = tail->next;
        }
    }
}

void print(node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

// main reverse function
node *reverse(node *&head, int k) {
    int x = k;
    node *current = head;
    node *prev = nullptr, *n = nullptr;
    while (current != nullptr && x > 0) {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
        x--;
    }
    if (n != nullptr) {
        head->next = reverse(n, k);
    }
    return prev;
}

int main() {
    // input the information
    int size, k;
    cin >> size >> k;

    // input the linked list
    node *head = nullptr;
    createList(head, size);
    head = reverse(head, k);
    print(head);

    return 0;
}