// Leetcode: Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list

#include <iostream>
#include <vector>

using namespace std;

class ListNode
{
public:
  // Properties
  int val;
  ListNode *next;

  // Constructors
  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LL
{
public:
  // Properties
  ListNode *head;

  // Constructors
  LL()
  {
    head = nullptr;
  }

  // Methods
  ListNode *createList(vector<int> &nums)
  {
    if (nums.empty())
    {
      return head;
    }

    ListNode *itr = head;
    for (int num : nums)
    {
      if (itr == nullptr)
      {
        itr = new ListNode(num);
        head = itr;
      }
      else
      {
        itr->next = new ListNode(num);
        itr = itr->next;
      }
    }

    return head;
  }

  ListNode *middleNode(ListNode *head)
  {
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
    }

    return slowPtr;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  LL list;
  ListNode *head = list.createList(nums);
  ListNode *ans = list.middleNode(head);

  free(head);
  free(ans);

  return 0;
}