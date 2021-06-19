// Sort List :: Leetcode
// https://leetcode.com/problems/sort-list/

// asks us to do it in O(logn) time : heap, merge and quick sort :: however quick sort is not advisable in linked lists

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

// HEAP SORT

// comparator function
class compare {
public:
    bool operator()(ListNode *head1, ListNode *head2) {
        return head1->val > head2->val;
    }
};

// heap sort (takes no extra space :: constant space)
ListNode *heapSort(ListNode *head) {
    auto *newHead = new ListNode(0);

    // min heap
    priority_queue<ListNode *, vector<ListNode *>, compare> heap;

    // push the elements into the min heap
    while (head != nullptr) {
        heap.push(head);
        head = head->next;
    }

    // pop one by one and link it to the new head
    ListNode *ptr = newHead;
    while (!heap.empty()) {
        ListNode *top = heap.top();
        heap.pop();
        ptr->next = top;
        ptr = ptr->next;
    }
    ptr->next = nullptr;

    return newHead->next;
}

// MERGE SORT

// midpoint function
ListNode *midpoint(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// merge function : recursive function as well
ListNode *merge(ListNode *&l1, ListNode *&l2) {
    // base case
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    // recursive case
    ListNode *temp;
    if (l1->val <= l2->val) {
        temp = l1;
        temp->next = merge(l1->next, l2);
    } else {
        temp = l2;
        temp->next = merge(l1, l2->next);
    }
    return temp;
}

// merge sort main function
ListNode *mergeSort(ListNode *head) {
    // base cases
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // recursive cases
    ListNode *mid = midpoint(head);
    ListNode *list1 = head;
    ListNode *list2 = mid->next;
    mid->next = nullptr;    // break the list into 2 parts

    list1 = mergeSort(list1);
    list2 = mergeSort(list2);
    ListNode *ans = merge(list1, list2);

    return ans;
}

int main() {
    ListNode *head = nullptr;
    int size;
    cin >> size;
    takeInput(head, size);

//    head = heapSort(head);
//    head = mergeSort(head);

    printList(head);

    return 0;
}

