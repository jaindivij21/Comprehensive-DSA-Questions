// Linked List

#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = nullptr;
    }
};

// insert at end
void insertAtEnd(node *&head, int d)
{
    if (head == nullptr)
    {
        head = new node(d);
        return;
    }
    else
    {
        node *ptr = head;
        for (; ptr->next != nullptr; ptr = ptr->next)
            ;
        node *temp = new node(d);
        ptr->next = temp;
        return;
    }
}

// insert at head
void insertAtHead(node *&head, int d)
{
    node *ptr = head;
    node *temp = new node(d);
    temp->next = ptr;
    head = temp;
}

// take input
void takeInput(node *&head)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        insertAtHead(head, x);
        cin >> x;
    }
}

// print the linked list
void printList(node *head)
{
    node *ptr = head;
    for (; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->data << " ";
    }
}

int main()
{
    node *head = nullptr;
    takeInput(head);
    printList(head);
    return 0;
}