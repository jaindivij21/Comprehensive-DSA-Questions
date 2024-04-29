// Minimum Number of Operations to Make Array XOR Equal to K
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

#include <iostream>
#include <vector>

using namespace std;

// We can invert any bit of any index any number of times. Each invert constitutes for one operation. In minimum number
// of such operations we have to get an array such that XOR of all final elements results into the number k.

// Solution: XOR all the bits of each place of the nums array and check the difference with the resultant bits of the
// number k. Alternatively you can XOR all the original numbers and check the different bits from the number k.
int minOperations(vector<int> &nums, int k)
{
  // XOR all the numbers of the array
  int xorRes = 0;
  for (int i : nums)
  {
    xorRes ^= i;
  }

  // Check the different bits between xorRes and k
  xorRes ^= k;

  int count = 0;
  // Count the number of 1's in xorRes
  while (xorRes != 0)
  {
    int temp = xorRes & 1;
    if (temp == 1)
    {
      count++;
    }

    xorRes = xorRes >> 1;
  }

  return count;
}

int main()
{
  int k, size;
  cin >> size >> k;
  vector<int> nums(size);

  int temp;
  for (int i = 0; i < size; i++)
  {
    cin >> temp;
    nums[i] = temp;
  }

  cout << minOperations(nums, k) << endl;

  return 0;
}