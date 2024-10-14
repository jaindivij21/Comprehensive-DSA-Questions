// Leetcode: Maximal Score After Applying K Operations
// https://leetcode.com/problems/maximal-score-after-applying-k-operations

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maxKelements(std::vector<int> &nums, int k)
  {
    // Max heap to always get the largest element
    priority_queue<int> maxHeap;

    // Initialize the max heap with all elements from nums
    for (int num : nums)
    {
      maxHeap.push(num);
    }

    long long maxScore = 0;

    // Perform exactly 'k' operations
    for (int operation = 0; operation < k; ++operation)
    {
      // Extract the largest element from the heap
      int largestElement = maxHeap.top();
      maxHeap.pop();

      // Add the largest element to the score
      maxScore += largestElement;

      // Replace the element with ceil(largestElement / 3) and push it back into the heap
      int reducedElement = ceil(largestElement / 3.0);
      maxHeap.push(reducedElement);
    }

    return maxScore;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {10, 10, 10, 10, 10};
  int k = 5;
  cout << sol.maxKelements(nums, k) << endl;

  return 0;
}