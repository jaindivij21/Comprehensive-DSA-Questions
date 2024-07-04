// Leetcode: Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros

#include <iostream>

using namespace std;

// Definition of ListNode class for linked list
class ListNode
{
public:
  int val;
  ListNode *next;

  // Constructors for ListNode
  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to delete a node from the linked list
void deleteNode(ListNode *&head, ListNode *&prev, ListNode *&current)
{
  ListNode *temp = current;

  if (prev == nullptr)
  {
    head = current->next;
  }
  else
  {
    prev->next = current->next;
  }

  current = current->next;
  delete temp;
}

// Function to merge nodes in between zeros in the linked list
ListNode *mergeNodes(ListNode *head)
{
  int cumulativeSum = 0;
  ListNode *previousNode = nullptr;
  ListNode *iterator = head;

  while (iterator != nullptr)
  {
    if (iterator->val == 0 || (iterator->next != nullptr && iterator->next->val != 0))
    {
      cumulativeSum += iterator->val;
      deleteNode(head, previousNode, iterator);
    }
    else
    {
      iterator->val += cumulativeSum;
      cumulativeSum = 0;
      previousNode = iterator;
      iterator = iterator->next;
    }
  }

  return head;
}

int main()
{
  int arr[] = {0, 3, 1, 0, 4, 5, 2, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  auto *head = new ListNode(arr[0]);
  auto *itr = head;
  for (int i = 1; i < size; i++)
  {
    itr->next = new ListNode(arr[i]);
    itr = itr->next;
  }

  head = mergeNodes(head);

  return 0;
}