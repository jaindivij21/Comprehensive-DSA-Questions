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

void deleteNode(node *&head, int ele)
{
    if (head == nullptr)
        return;
    else
    {
        node *prev = nullptr;
        node *itr = head;
        while (itr != nullptr)
        {
            if (itr->data == ele)
            {
                if (itr == head)
                {
                    head = itr->next;
                }
                else
                {
                    prev->next = itr->next;
                }
                delete itr;
                return;
            }
            prev = itr;
            itr = itr->next;
        }
        return;
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

int kFromLast(node *head, int pos)
{
    int itr = 1;
    node *fastPtr = head;
    node *slowPtr = head;
    while (fastPtr != nullptr)
    {
        fastPtr = fastPtr->next;
        if (itr > pos)
        {
            slowPtr = slowPtr->next;
        }
        itr++;
    }
    return slowPtr->data;
}

// 1->2->3->4->5
// 1<-2<-3<-4<-5
void reverse(node *&head)
{
    node *temp = nullptr;
    node *prev = nullptr;
    node *curr = head;
    while (curr != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main()
{
    node *head = nullptr;
    takeInput(head);
    printList(head);
    return 0;
}