// Stacks - LIFO ORDER
// Last in first out

// Implementation using linked list
// When stack needs to have dynamic size

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

void push(node *&head, int data) {
    if (head == nullptr) {
        head = new node(data);
    } else {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
}

void pop(node *&head) {
    node *temp = head;
    head = head->next;
    delete temp;
}

int peek(node *head) {
    return head->data;
}

bool ifEmpty(node *head) {
    if (head != nullptr)
        return false;
    else
        return true;
}

void print(node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main() {
    // create the linked list/stack
    node *stack = nullptr;

    // push
    int size;
    cin >> size;
    int data;
    for (int i = 0; i < size; i++) {
        cin >> data;
        push(stack, data);
    }

    // peek
    int top = peek(stack);
    cout << "Top element is: " << top << endl;

    // pop
    pop(stack);

    cout << "Stack after pop:" << endl;
    print(stack);

    cout << endl;
    
    bool ans = ifEmpty(stack);
    cout << "If the stack is empty: " << ans << endl;

    cout << endl;

    // print
    cout << "Final stack" << endl;
    print(stack);

    return 0;
}

