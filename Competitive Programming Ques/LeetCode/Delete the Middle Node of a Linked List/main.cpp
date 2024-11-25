// Leetcode: Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      delete head;
      return nullptr;
    }

    ListNode *prevPtr = nullptr;
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
      prevPtr = slowPtr;
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
    }

    if (prevPtr != nullptr)
    {
      prevPtr->next = slowPtr->next;
    }
    delete slowPtr;

    return head;
  }
};

int main()
{
  Solution sol;

  auto *head = new ListNode(1);

  ListNode *result = sol.deleteMiddle(head);

  while (head != nullptr)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}