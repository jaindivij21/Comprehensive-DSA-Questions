// Program to detect and remove cycle from the linked list
// O(N) TIME and O(N) space. But Floyd takes O(1) space thus is better.
#include<iostream>
#include<unordered_map>

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

node *getLast(node *&head) {
    node *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    return temp;
}

ostream &operator<<(ostream &os, node *head) {
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head) {
    takeInput(head);
    return is;
}

void removeCycle(node *&head) {
    // detect and remove the cycle using hashmap
    // basically we store each node's data and address. Once any node's address point to some node that already exists, we have detected a cycle

    // declare
    unordered_map<node *, int> addrMap;
    node *itr = head;
    while (true) {
        addrMap.insert(make_pair(itr, itr->data));
        if (addrMap.find(itr->next) != addrMap.end()) {
            // means the address has been found, therefore need to make repairs
            cout << "Cycle found from " << itr->data << " to " << itr->next->data << endl;

            // removing the cycle
            itr->next = nullptr;
            break;
        }
        itr = itr->next;
    }
}


int main() {
    node *head = nullptr;
    cin >> head;

    // make a LL with a cycle in it
    node *tail = getLast(head);
    tail->next = head->next->next->next;

    removeCycle(head);

    cout << head;

    return 0;
}