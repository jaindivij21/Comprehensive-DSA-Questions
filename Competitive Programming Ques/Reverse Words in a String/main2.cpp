// Leetcode: Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self

#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();

    // Initialize two arrays to store the prefix (left) and suffix (right) products
    vector<int> leftProducts(n);
    vector<int> rightProducts(n);

    // Variable to keep track of the running product for the prefix (left side)
    int prefixProduct = 1;
    for (int i = 0; i < n; i++)
    {
      leftProducts[i] = prefixProduct;
      prefixProduct *= nums[i];
    }

    // Variable to keep track of the running product for the suffix (right side)
    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      rightProducts[i] = suffixProduct;
      suffixProduct *= nums[i];
    }

    // Generate the result by multiplying left and right products
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
      result[i] = leftProducts[i] * rightProducts[i];
    }

    return result;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Solution sol;
  vector<int> result = sol.productExceptSelf(nums);

  return 0;
}