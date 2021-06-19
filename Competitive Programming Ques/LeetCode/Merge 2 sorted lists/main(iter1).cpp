// Merge 2 Sorted Lists :: Leetcode
// https://leetcode.com/problems/merge-two-sorted-lists/

#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    // constructor
    ListNode() {
        val = 0;
        next = nullptr;
    }

    explicit ListNode(int data) {
        val = data;
        next = nullptr;
    }

    ListNode(int data, ListNode *ptr) {
        val = data;
        next = ptr;
    }
};

void append(ListNode *&head, int data) {
    auto *temp = new ListNode(data);
    if (head == nullptr) {
        head = temp;
    } else {
        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
}

void takeInput(ListNode *&head, int n) {
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        append(head, data);
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // dummy node pointing to a node *before the* head of the list1
    auto *dum1 = new ListNode(0, l1);
    auto ans = dum1;
    // dummy node 2 pointing to the head of list2 
    auto *dum2 = l2;

    // if the lists are empty
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    // if the lists aren't empty (in place) :: compare the nodes of list 1 and list 2, and if list 2's node is smaller
    // add it *before* the node on list 1
    while (dum1->next != nullptr && dum2 != nullptr) {
        if (dum1->next->val < dum2->val) {
            dum1 = dum1->next;
        } else {
            ListNode *temp = dum2;
            dum2 = dum2->next;
            temp->next = dum1->next;
            dum1->next = temp;
            dum1 = dum1->next;
        }
    }
    // check if l1 ends first and l2 is still left
    if (dum2 != nullptr) {
        dum1->next = dum2;
    }
    return ans->next;
}

int main() {
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int n1, n2;
    cin >> n1 >> n2;
    takeInput(head1, n1);
    takeInput(head2, n2);

    ListNode *ans = mergeTwoLists(head1, head2);

    printList(ans);

    return 0;
}