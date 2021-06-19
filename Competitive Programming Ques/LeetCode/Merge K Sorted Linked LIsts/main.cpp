// Merge k Sorted Lists :: Leetcode
// https://leetcode.com/problems/merge-k-sorted-lists/

// using heaps

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

// making a comparator function **(remember this)**
class Compare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

// merge function
ListNode *mergeKLists(vector<ListNode *> &lists) {
    // make a new list
    auto *l = new ListNode(0, nullptr);
    ListNode *ans = l;
    
    // make a heap 
    priority_queue<ListNode *, vector<ListNode *>, Compare> heap;

    // insert all the first nodes into the heap if that list exists
    for (auto &list : lists) {
        if(list!= nullptr)
            heap.push(list);
    }

    // start popping the minimum
    while (!heap.empty()) {
        ListNode *temp = heap.top();
        heap.pop();
        // after popping, push into the heap the next element from that list (if it exists)
        if (temp->next != nullptr)
            heap.push(temp->next);
        // append the popped element to the list
        l->next = temp;
        l = l->next;
    }
    // return the newly formed list
    return ans->next;
}

int main() {
    int numOfLists;
    cin >> numOfLists;
    vector<ListNode *> v;
    for (int i = 0; i < numOfLists; i++) {
        ListNode *head = nullptr;
        int size;
        cin >> size;
        takeInput(head, size);
        v.push_back(head);
    }

    ListNode *ans = mergeKLists(v);

    printList(ans);

    return 0;
}