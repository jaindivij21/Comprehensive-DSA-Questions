// Leetcode: Minimum Array End
// https://leetcode.com/problems/minimum-array-end
// https://www.youtube.com/watch?v=gpiR6Dfrr3k&t=475s

#include <iostream>

using namespace std;

class Solution
{
public:
  long long minEnd(int n, int x)
  {
    if (n == 1)
      return x; // If only one element, return x itself.

    long long remainingPositions = n - 1;
    long long bitMask = 1;
    long long result = x;

    while (remainingPositions > 0)
    {
      // Check if the current bit in result is 0
      long long currentBit = result & bitMask;
      if (currentBit == 0)
      {
        // If remainingPositions has a 1 at this bit position, set it in result
        if (remainingPositions & 1)
        {
          result |= bitMask;
        }
        remainingPositions >>= 1; // Move to the next bit of remainingPositions
      }
      bitMask <<= 1; // Shift the mask to the next bit position
    }

    return result;
  }
};

int main()
{
  Solution s;
  cout << s.minEnd(3, 2) << endl;

  return 0;
}