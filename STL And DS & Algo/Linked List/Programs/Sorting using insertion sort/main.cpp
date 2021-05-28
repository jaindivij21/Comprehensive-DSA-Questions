// 1) Create an empty sorted (or result) list
//
// 2) Traverse the given list, do following for every node.
//         a) Insert current node in sorted way in sorted or result list.
// 3) Change head of given linked list to head of sorted (or result) list.


// Code Functionality.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;    //self referential class

    Node(int num) {
        data = num;
        next = nullptr;    //nullptr is a macro
    }
};

Node *copyList(Node *head) {
    if (head == nullptr) return nullptr;

    Node *copy = new Node(head->data);
    copy->next = copyList(head->next);
    return copy;
}

Node *addBehind(Node *head, Node *newNode) {
    if (head == nullptr) {
        return newNode;
    }

    Node *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}


void addToFront(Node *&head, Node *nodeToAdd) {
    if (head == nullptr) {
        head = nodeToAdd;
        return;
    }

    nodeToAdd->next = head;
    head = nodeToAdd;
}

Node *takeInput() {
    int num;
    Node *head = nullptr;

    while (cin >> num && num != -1) {
        Node *newNode = new Node(num);
        head = addBehind(head, newNode);
    }

    return head;
}

Node *takeInput2(int num) {
    Node *head = nullptr;

    int x;

    for (int i = 0; i < num; ++i) {
        cin >> x;
        Node *temp = new Node(x);
        head = addBehind(head, temp);
    }

    return head;
}

void print(Node *head) {
    //prints the Linked list
    Node *tmp = head;
    while (tmp != nullptr) {
        //I have not reached the end
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

using namespace std;

Node *insertProperly(Node *head, Node *temp) {
    if (head == nullptr || head->data >= temp->data) {
        temp->next = head;
        return temp;
    }

    Node *parse = head;

    while (head->next != nullptr && head->next->data < temp->data) {
        head = head->next;
    }

    temp->next = head->next;
    head->next = temp;

    return parse;
}

Node *insertionSort(Node *temp) {
    Node *sorted = nullptr;

    while (temp != nullptr) {
        Node *temp2 = temp->next;
        sorted = insertProperly(sorted, temp);
        temp = temp2;
    }

    return sorted;
}

int main() {
    int n;
    cin >> n;
    Node *head = takeInput2(n);
    head = insertionSort(head);
    print(head);
    return 0;
}