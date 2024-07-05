// Leetcode: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Find the Minimum and Maximum Number of Nodes Between Critical Points

#include <iostream>
#include <vector>

using namespace std;

// LinkedList Node Class
class ListNode
{
public:
  // Variables
  int val;
  ListNode *next;

  // Constructors
  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to determine if a node is a critical point (local minima or maxima)
bool isCriticalNode(ListNode *&prev, ListNode *&curr)
{
  if (prev == nullptr || curr->next == nullptr)
    return false; // Edge nodes cannot be critical points

  // Check for local minima or maxima
  if ((curr->val < prev->val && curr->val < curr->next->val) ||
      (curr->val > prev->val && curr->val > curr->next->val))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Function to find distances between critical points in the linked list
vector<int> nodesBetweenCriticalPoints(ListNode *&head)
{
  ListNode *prev = nullptr;
  ListNode *curr = head;
  int position = 1;
  int noOfCriticalNodes = 0;
  int firstCriticalNodePosition = -1;
  int latestCriticalNodePosition = -1;
  int minDistance = INT_MAX;
  int maxDistance = INT_MIN;

  // Iterate over the linked list
  while (curr != nullptr)
  {
    // Check if the current node is a critical point
    if (isCriticalNode(prev, curr))
    {
      noOfCriticalNodes++;

      // Record the position of the first critical node found
      if (firstCriticalNodePosition == -1)
      {
        firstCriticalNodePosition = position;
      }

      // Calculate and update the minimum distance between critical points
      if (latestCriticalNodePosition != -1)
      {
        minDistance = min(minDistance, position - latestCriticalNodePosition);
      }

      // Update the position of the latest critical node found
      latestCriticalNodePosition = position;
    }

    // Move to the next node
    position++;
    prev = curr;
    curr = curr->next;
  }

  // Calculate the maximum distance between critical points
  maxDistance = latestCriticalNodePosition - firstCriticalNodePosition;

  vector<int> result;
  // Check if there are fewer than two critical points
  if (noOfCriticalNodes < 2)
  {
    result = {-1, -1}; // Return [-1, -1] as specified
  }
  else
  {
    // Return the computed distances
    result = {minDistance, maxDistance};
  }

  return result;
}

int main()
{
  vector<int> list = {1, 3, 2, 2, 3, 2, 2, 2, 7};

  auto *head = new ListNode(list[0]);
  ListNode *itr = head;
  for (int i = 1; i < list.size(); i++)
  {
    itr->next = new ListNode(list[i]);
    itr = itr->next;
  }

  vector<int> result = nodesBetweenCriticalPoints(head);

  return 0;
}