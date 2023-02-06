// Shuffle the Array Problem
// https://leetcode.com/problems/shuffle-the-array/description/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Naive Method - Takes extra space
vector<int> shuffle1(vector<int> &nums, int n)
{
  vector<int> ans;
  int ptr1 = 0;
  int ptr2 = n;

  for (int i = 0; i < n; i++)
  {
    // Run the loop for n times
    ans.push_back(nums[ptr1++]);
    ans.push_back(nums[ptr2++]);
  }

  return ans;
}

// Optimized Method - In constant space by shuffling the same array
// Used the concept of bit-masking
vector<int> shuffle2(vector<int> &nums, int n)
{
  // Store both the paired numbers (Xi, Yi) on same index
  for (int i = n - 1; i >= 0; i--)
  {
    // Left shift the Xi by 10 to get space for Yi
    nums[i] = nums[i] << 10;
    // Store Yi on the same index
    nums[i] = nums[i] | nums[i + n];
  }

  // '0000000000 1111111111' in decimal.
  int allOnes = pow(2, 10) - 1;

  // Start storing the numbers at their correct positions
  // Note: Will have to start from the (n-1)th index moving backward (since if go from left to right, we'll overwrite our stored value pairs (Xi, Yi))
  int ptr = 2 * n - 1;
  for (int i = n - 1; i >= 0; i--)
  {
    // Extract the 2 numbers
    int num1, num2;
    num1 = nums[i] >> 10;
    num2 = nums[i] & allOnes;

    // Replace the corresponding indices with correct values
    nums[ptr--] = num2;
    nums[ptr--] = num1;
  }

  return nums;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(2 * n);

  for (int i = 0; i < 2 * n; i++)
  {
    cin >> nums[i];
  }

  vector<int> ans = shuffle2(nums, n);

  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}