// Leetcode: Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
  /*
   * The goal is to find the k-th largest element in the array.
   * We use a min-heap to efficiently track the k largest elements.
   * By the end of the process, the smallest element in the heap will be the k-th largest element.
   */
  int findKthLargest(vector<int> &nums, int k)
  {
    // Create a min-heap to store the top k the largest elements.
    priority_queue<int, vector<int>, greater<>> minHeap;

    // Initialize the heap with the first k elements from the array.
    for (int i = 0; i < k; ++i)
    {
      minHeap.push(nums[i]);
    }

    // Traverse the rest of the array and maintain the heap with the k largest elements.
    // Push new elements into the heap only if they are larger than the smallest element in the heap.
    for (int i = k; i < nums.size(); ++i)
    {
      // If the current element is larger than the smallest element in the heap,
      // replace the smallest element with the current element.
      if (nums[i] > minHeap.top())
      {
        minHeap.pop();
        minHeap.push(nums[i]);
      }
    }

    // After processing all elements, the top of the min-heap is the k-th largest element.
    return minHeap.top();
  }
};

int main()
{
  int k = 2;
  vector<int> nums = {3, 2, 1, 5, 6, 4};

  Solution s;
  cout << s.findKthLargest(nums, k);

  return 0;
}
