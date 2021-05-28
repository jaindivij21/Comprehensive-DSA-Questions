// Reverse k elements at a time in a linked list
/*
    Sample Input
    9 3
    9 4 1 7 8 3 2 6 5
    Sample Output
    1 4 9 3 8 7 5 6 2
 */

//https://www.youtube.com/watch?v=9F55R1VJRZ4

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

void reverse(node *head) {

    if (head == nullptr)
        return;


    if (head->next == nullptr)
        return;


    reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

}

node *reverse(node *&start, int k, int size) {
    //swap the linked list in group size = k
    node *p, *q, *new_start, *temp;
    int cnt;
    p = start;
    cnt = 0;
    while (cnt != k - 1)    // go to the 'K'th node
    {
        if (p->next == nullptr) {
            return start;
        }
        p = p->next;
        cnt++;
    }

    new_start = p; //the new start
    q = new_start;
    while (true) {
        p = start;
        temp = q->next;
        if (temp == nullptr)  // if total number of nodes is divisible by K (multiple of K)
        {
            reverse(p);
            return new_start;
        }

        q->next = nullptr;
        q = temp;
        start = temp;

        cnt = 0;
        //in the last outside while loop , if remainder is non-zero number of nodes
        while (cnt != k - 1) {
            if (temp->next == nullptr) {
                reverse(p);
                p->next = q;
                return new_start;
            }
            temp = temp->next;
            cnt++;
        }

        reverse(p);
        p->next = temp;
        q = temp;
    }

    return new_start;
}

int main() {
    // input the information
    int size, k;
    cin >> size >> k;

    // input the linked list
    node *head = nullptr;
    createList(head, size);
    head = reverse(head, k, size);
    print(head);

    return 0;
}