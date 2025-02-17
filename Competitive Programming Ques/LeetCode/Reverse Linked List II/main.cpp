// Leetcode: Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii

#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int value) : val(value), next(nullptr) {}
};

class Solution
{
public:
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    // Base cases: if the list is empty, has only one node, or left == right (no reversal needed)
    if (head == nullptr || head->next == nullptr || left == right)
      return head;

    ListNode *prev = nullptr; // Pointer to track the node before the sublist to reverse
    ListNode *curr = head;    // Pointer to traverse the list

    // Move `curr` to the `left`-th node and `prev` to the node before `left`
    for (int i = 0; i < left - 1; i++)
    {
      prev = curr;
      curr = curr->next;
    }

    // Save pointers for later reconnection
    ListNode *newEnd = prev;      // Node before the sublist (could be nullptr if left == 1)
    ListNode *sublistTail = curr; // This will be the new tail after reversal
    ListNode *next = curr->next;  // Store the next node before modifying links

    // Reverse the sublist from position `left` to `right`
    int numOfOperations = right - left + 1;
    while (numOfOperations--)
    {
      curr->next = prev; // Reverse link
      prev = curr;       // Move prev forward
      curr = next;       // Move curr forward
      if (next)
        next = next->next; // Move next forward
    }

    // After this loop, `prev` will be the new head of the reversed sublist whilst `curr` will be the node
    // after the sublist and `next` will be the node after `curr` or nullptr.

    // Reconnect the reversed sublist with the original list
    if (newEnd)
    {
      newEnd->next = prev; // Connect the node before `left` to the new head of reversed sublist
    }
    else
    {
      head = prev; // If `left == 1`, update head to the new front node
    }

    // Connect the tail of the reversed sublist to the remaining list
    sublistTail->next = curr;

    return head;
  }
};

int main()
{
  Solution s;
  vector<int> v = {1, 2, 3, 4, 5};

  auto *head = new ListNode(v[0]);
  auto *current = head;

  // Create the linked list from the vector
  for (int i = 1; i < v.size(); i++)
  {
    current->next = new ListNode(v[i]);
    current = current->next;
  }

  // Reverse the list
  auto *result = s.reverseBetween(head, 1, 5);

  // Print the reversed list
  while (result != nullptr)
  {
    cout << result->val << " ";
    result = result->next;
  }

  while (head != nullptr)
  {
    auto *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}
