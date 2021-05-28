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

node *reverse(node *&head, int k, int size) {
    int groupsize = k;  // maintain the size of each group 
    int groups = size / k;  // number of group

    // these are the pointers that'll help us in reversing the list
    node *prev = nullptr;
    node *curr = head;
    node *next;


    node *itr2 = nullptr;  // points to the last element of first group
    node *itr1 = head;  // points to the first element of next group
    node *newHead = head;   // new head that we return by this function

    // kth node in first group is our new head
    groupsize--;
    while (groupsize != 0) {
        newHead = newHead->next;
        groupsize--;
    }

    // main loop to reverse the list in groups of k
    while (groups--) {
        if (groups != 0) {
            /*
             *  if its not the last group.
             *  cuz if its last group then itr1 and itr2 will get seg fault as they'll be null 
             */
            
            // save the link to the first node in next group
            groupsize = k;
            while (groupsize != 0) {
                itr1 = itr1->next;
                groupsize--;
            }
            groupsize = k - 1;

            // save the link to the last node in the next group
            itr2 = itr1;
            while (groupsize != 0) {
                itr2 = itr2->next;
                groupsize--;
            }
            prev = itr2;
        } else {
            // if its the last group make the prev and itr1 as null cuz thats 
            itr1 = prev = nullptr;
        }

        // actual reverse process for that group
        while (curr != itr1) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }


    return newHead;
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