// Leetcode: Range Sum of Sorted Subarray Sums
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
  int rangeSum(vector<int> &nums, int n, int left, int right)
  {
    // Min-heap to store subarray sums in non-decreasing order
    priority_queue<int, vector<int>, greater<>> minHeap;

    // Calculate all subarray sums and push them into the min-heap
    for (int i = 0; i < n; ++i)
    {
      int currentSum = 0;
      for (int j = i; j < n; ++j)
      {
        currentSum += nums[j];
        minHeap.push(currentSum);
      }
    }

    // Modulo value as given in the problem statement
    const int MODULO = 1e9 + 7;
    long long result = 0;

    // Remove the first (left - 1) elements from the min-heap
    for (int i = 0; i < left - 1; ++i)
    {
      minHeap.pop();
    }

    // Sum the elements from index left to index right
    for (int i = 0; i < right - left + 1; ++i)
    {
      result = (result + minHeap.top()) % MODULO;
      minHeap.pop();
    }

    return result;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  int n = 4, left = 1, right = 5;

  Solution s;
  cout << s.rangeSum(nums, n, left, right) << endl;

  return 0;
}