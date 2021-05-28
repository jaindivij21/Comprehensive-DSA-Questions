// Program to detect and remove loops in a linked list
// Floyd's Cycle Method
// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

/*
*
*
*   You do not need to refer or modify any code below this.
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

void buildCycleList(node *&head) {
    unordered_map<int, node *> hash;
    int x;
    cin >> x;
    if (x == -1) {
        head = nullptr;
        return;
    }
    head = new node(x);
    hash[x] = head;
    node *current = head;
    while (x != -1) {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end()) {
            current->next = hash[x];
            return;
        }
        node *n = new node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = nullptr;
}

void printLinkedList(node *head) {
    unordered_set<int> s;
    while (head != NULL) {
        if (s.find(head->data) != s.end()) {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

// function to detect a cycle in linked list
bool detectLoop(node *head) {
    // check by making a diagram
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }
    return false;
}

// detects as well as removes the loop in the linked list
bool floydCycleRemoval(node *head) {
    /* Code here */
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {

        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            fast = head;

            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = nullptr;

            return true;
        }
    }
    return false;
}

int main() {
    node *head = nullptr;
    buildCycleList(head);

    // detect a loop
    bool detection = detectLoop(head);
    if (detection)
        cout << "Yes there is a loop in the list" << endl;
    else
        cout << "No there isn't any loop in the list" << endl;

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent) {
        cout << "Cycle was present\n";
    } else {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}