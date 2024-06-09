// Leetcode: Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Optimised Solution : Using hash map
int subarraysDivByK(vector<int> &nums, int k)
{
  int totalSubarrays = 0; // To store the total count of subarrays with sum divisible by k
  int cumulativeSum = 0;  // To store the running sum of elements

  // Hash map to store the frequency of remainders when cumulativeSum is divided by k
  unordered_map<int, int> remainderFrequency;
  remainderFrequency[cumulativeSum]++; // Initialize with remainder 0 occurring once

  for (int num : nums)
  {
    cumulativeSum += num;              // Update the running sum with the current element
    int remainder = cumulativeSum % k; // Calculate the remainder when cumulativeSum is divided by k
    // Note: If the remainder is negative, adjust it to be positive by adding k
    if (remainder < 0)
    {
      remainder += k;
    }

    // If the remainder has been seen before, it means there are subarrays which sum to a multiple of k
    if (remainderFrequency.find(remainder) != remainderFrequency.end())
    {
      totalSubarrays += remainderFrequency[remainder];
    }

    // Increment the count of this remainder in the hash map
    remainderFrequency[remainder]++;
  }

  return totalSubarrays;
}

/*
 * When performing the modulus operation in C++ with a negative dividend (cumulativeSum in our case),
 * the remainder can be negative. This is because C++ allows negative remainders,
 * which can be confusing when dealing with modulo arithmetic.
 *
 * According to the division equation: a = b * q + r, where:
 * - a is the dividend (cumulativeSum in our case),
 * - b is the divisor (k in our case),
 * - q is the quotient, and
 * - r is the remainder.
 *
 * If the remainder (r) is negative, it indicates that the dividend is less than a multiple of the divisor.
 * In C++, when the dividend is negative, the modulus operation can produce negative remainders.
 *
 * To adjust the negative remainder to be positive, we add the divisor (k) to it.
 * This adjustment ensures that the remainder is always non-negative and falls within the range [0, k-1].
 * Additionally, we increment the quotient (q) by 1 to maintain the validity of the equation:
 * a = b * q + r, ensuring that the remainder (r) becomes positive.
 *
 * Example:
 * If cumulativeSum = -1 and k = 5, then -1 % 5 = -1, which is negative.
 * Adjusting the remainder by adding k, we get: remainder = -1 + 5 = 4.
 * This adjustment ensures that the remainder is positive, as expected in modulo arithmetic.
 */

int main()
{
  int k = 5;
  vector<int> nums = {4, 5, 0, -2, -3, 1};

  cout << subarraysDivByK(nums, k) << endl;
  return 0;
}