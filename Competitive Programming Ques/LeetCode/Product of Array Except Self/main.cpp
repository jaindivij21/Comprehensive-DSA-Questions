// Leetcode: Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self

#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int totalProduct = 1;
    int nonZeroProduct = 1;
    int zeroCount = 0;

    // Calculate the total product and count the number of zeros in the array
    for (int num : nums)
    {
      totalProduct *= num;
      if (num != 0)
      {
        nonZeroProduct *= num;
      }
      else
      {
        zeroCount++;
      }
    }

    // If there are more than one zero, the result is all zeros since all products will be zero
    if (zeroCount > 1)
    {
      return vector<int>(nums.size(), 0);
    }

    vector<int> result;
    for (int num : nums)
    {
      // If the current number is zero, the result is the product of all non-zero elements
      // Otherwise, it's the total product divided by the current number
      int productExceptSelf = (num == 0) ? nonZeroProduct : totalProduct / num;
      result.push_back(productExceptSelf);
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