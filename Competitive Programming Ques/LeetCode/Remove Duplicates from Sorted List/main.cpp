// Leetcode: Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list

#include <iostream>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  // Constructors
  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    // If the list is empty, return the head (which is nullptr)
    if (head == nullptr)
      return head;

    // Initialize pointers: 'current' points to the current node being checked
    // 'nextNode' points to the next node in the list
    ListNode *current = head;
    ListNode *nextNode = head->next;

    // Iterate through the linked list
    while (nextNode != nullptr)
    {
      if (current->val == nextNode->val)
      {
        // If the current and next node have the same value, skip the next node
        current->next = nextNode->next;
        delete nextNode;          // Free the memory of the duplicate node
        nextNode = current->next; // Move to the next node after the duplicate
      }
      else
      {
        // Move both pointers forward if no duplicate
        current = nextNode;
        nextNode = nextNode->next;
      }
    }

    return head;
  }
};

int main()
{
  Solution sol;
  auto *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(3);

  ListNode *result = sol.deleteDuplicates(head);

  delete head;

  return 0;
}
